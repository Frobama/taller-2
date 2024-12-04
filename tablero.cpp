#include "Tablero.h"
#include <iostream>

using namespace std;

Tablero::Tablero(){
    
    char valores[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int index = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = valores[index++];
        }
    }   
}

void Tablero::imprimirTablero() {
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

bool Tablero::valido(int f, int c){
    if(f < 3 && f >= 0 && c < 3 && c >= 0 && tablero[f][c] != 'X' && tablero[f][c] != 'O'){
        return true;
    }
    return false;
}

bool Tablero::verificarGanador(char jugador){
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

void Tablero::hacerJugada(char jugador, int f, int c){
    tablero[f][c] = jugador;
}

bool Tablero::lleno(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(tablero[i][j] == ' '){
                return false;
            }
        }
    }
    return true;
}