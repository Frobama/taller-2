#include "cpu.h"
#include <limits.h>

using namespace std;

int Cpu::evaluar(Tablero tablero) {
    if(tablero.verificarGanador('O')){
        return 10;
    }
    else if(tablero.verificarGanador('X')){
        return -10;
    }
    return 0;
}

int Cpu::minimax(Tablero tablero, int profundidad, bool esMax){
    int puntaje = evaluar(tablero);

    if(puntaje == 10 || puntaje == -10){
        return puntaje;
    }

    if(tablero.lleno()){
        return 0;
    }

    if(esMax){
        int mejor = INT_MIN;

        for(int fila = 0; fila < 3; ++fila){
            for(int col = 0; col < 3; ++col){
                if(tablero.valido(fila,col)){
                    tablero.hacerJugada('O',fila,col);

                    mejor = max(mejor,minimax(tablero, profundidad +1, false));

                    tablero.hacerJugada(' ',fila,col);
                }
            }
        }
        return mejor;
    }
    else{
        int peor = INT_MAX;

        for(int fila = 0; fila < 3; ++fila){
            for(int col = 0; col < 3; ++col){
                if(tablero.valido(fila,col)){
                    tablero.hacerJugada('X',fila,col);

                    peor = min(peor,minimax(tablero, profundidad +1, true));

                    tablero.hacerJugada(' ',fila,col);
                }
            }
        }
        return peor;
    }
}
pair<int,int> Cpu::mejorJugada(Tablero tablero){
    int mejorValor = INT_MIN;
    pair<int,int> mejorMov = {-1,-1};

    for(int fila = 0; fila < 3; ++fila){
        for(int col = 0; col < 3; ++col){
            if(tablero.valido(fila,col)){
                //Se simula la jugada
                tablero.hacerJugada('O',fila,col);

                int valor = minimax(tablero, 0, false);

                tablero.hacerJugada(' ', fila,col);

                if(valor > mejorValor) {
                    mejorValor = valor;
                    mejorMov = {fila,col};
                }
            }
        }
    }


    return mejorMov;
}