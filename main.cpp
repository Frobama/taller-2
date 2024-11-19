#include <iostream>
using namespace std;

// Función para imprimir el tablero
void imprimirTablero(char tablero[3][3]) {
    cout << "Tablero actual:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << tablero[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "--|---|--\n";
    }
    cout << endl;
}

// Función para verificar si hay un ganador
bool verificarGanador(char tablero[3][3], char jugador) {
    // Comprobar filas y columnas
    for (int i = 0; i < 3; i++) {
        if ((tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador) || 
            (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador)) {
            return true;
        }
    }
    // Comprobar diagonales
    if ((tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador) || 
        (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador)) {
        return true;
    }
    return false;
}




// Función principal
int main() {
    char tablero[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int turnos = 0;
    char jugadorActual = 'X';



    // Juego principal
    while (turnos < 9) {
        imprimirTablero(tablero);
        int movimiento;
        cout << "Turno del jugador " << jugadorActual << ". Ingresa el número de la celda: ";
        cin >> movimiento;

        // Convertir el número ingresado a coordenadas de la matriz
        int fila = (movimiento - 1) / 3;
        int columna = (movimiento - 1) % 3;

        // Verificar si la celda está disponible
        if (tablero[fila][columna] != 'X' && tablero[fila][columna] != 'O') {
            tablero[fila][columna] = jugadorActual;
            turnos++;

            // Verificar si el jugador actual ganó
            if (verificarGanador(tablero, jugadorActual)) {
                imprimirTablero(tablero);
                cout << "¡Jugador " << jugadorActual << " ha ganado!\n";
                return 0;
            }

            // Cambiar al otro jugador
            jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
        } else {
            cout << "Celda ocupada. Intenta de nuevo.\n";
        }
    }

    imprimirTablero(tablero);
    cout << "¡Es un empate!\n";
    return 0;
}
