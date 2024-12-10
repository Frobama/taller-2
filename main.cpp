#include "Tablero.h"
#include "Cpu.h"
#include <iostream>
using namespace std;

// Función principal
int main() {
    Tablero tablero = Tablero();
    Cpu cpu = Cpu();
    int turnos = 0;
    char jugadorActual = 'X';
    cout << "Bienvenido al juego de Tres en Linea" << endl << "Para ganar, tienes que lograr tener 3 de tus símbolos en una linea, ya sea" << endl << "horizontal, vertical, o diagonalmente."<< endl;
    cout << "Para escoger la casilla, sólo ingresa su número correspondiente"<<endl;
    cout << "1 jugador (contra la IA)" << endl << "2 jugadores"<< endl;
    cout << "Cantidad de jugadores: " << endl;
    int cantJugadores;
    cin >> cantJugadores;
    while(cantJugadores != 1 && cantJugadores != 2){
        cout << "Cantidad de jugadores: " << endl;
        cin >> cantJugadores;
    } 

    int movimiento;
    int fila;
    int columna;

    // Juego principal
    while (turnos < 9) {
        tablero.imprimirTablero();

        if(cantJugadores == 1){
            //Turno del jugado
            if(jugadorActual == 'X'){
                cout << "Es tu turno. Ingresa el número de la celda: ";
                cin >> movimiento;
                fila = (movimiento - 1) / 3;
                columna = (movimiento - 1) % 3;

                // Verificar si la celda está disponible
                if (tablero.valido(fila,columna)) {
                    tablero.hacerJugada(jugadorActual,fila,columna);
                    turnos++;

                    // Verificar si el jugador actual ganó
                    if (tablero.verificarGanador(jugadorActual)) {
                        tablero.imprimirTablero();
                        cout << "¡Has ganado!" << endl;
                        return 0;
                    }

                    // Cambiar al otro jugador
                    jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
                } else {
                    cout << "Celda ocupada. Intenta de nuevo.\n";
                }
            //Turno de la IA
            } else{
                cout << "Es el turno de la IA" << endl;

                auto [fila,columna] = cpu.mejorJugada(tablero);
                tablero.hacerJugada('O',fila,columna);
                
                // Verificar si la IA ganó
                if (tablero.verificarGanador('O')) {
                    tablero.imprimirTablero();
                    cout << "¡La IA ha ganado!\n";
                    cout<<cpu.getExplored()<<endl;
                    return 0;
                }
                turnos++;
                jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';

            }
        }
        
        else{
            cout << "Turno del jugador " << jugadorActual << ". Ingresa el número de la celda: ";
            cin >> movimiento;

            // Convertir el número ingresado a coordenadas de la matriz
            fila = (movimiento - 1) / 3;
            columna = (movimiento - 1) % 3;

            // Verificar si la celda está disponible
            if (tablero.valido(fila,columna)) {
                tablero.hacerJugada(jugadorActual,fila,columna);
                turnos++;

                // Cambiar al otro jugador
                jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
            } else {
                cout << "Celda ocupada. Intenta de nuevo.\n";
            }
        }
        
    }

    tablero.imprimirTablero();
    cout << "¡Es un empate!\n";
    cout<<"Nodos Explorados: "<<cpu.getExplored()<<endl;
    return 0;
}
