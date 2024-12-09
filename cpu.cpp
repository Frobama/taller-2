#include "cpu.h"
#include <limits.h>
#include <iostream>
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

int nodosExplorados = 0;

int Cpu::getExplored(){
    return nodosExplorados;
}
int Cpu::minimaxPoda(Tablero tablero, int profundidad, bool esMax, int alfa, int beta){
    nodosExplorados++;
    int puntaje = evaluar(tablero);

    if(puntaje == 10 || puntaje == -10){
        return puntaje;
    }

    if(tablero.lleno()){
        return 0;
    }

    bool poda = false;

    if(esMax){ // alfa va a ser del max (de la IA)
        int mejor = INT_MIN;
        for(int fila = 0; fila < 3 && !poda; ++fila){
            for(int col = 0; col < 3; ++col){
                if(tablero.valido(fila,col)){
                    tablero.hacerJugada('O',fila,col);

                    mejor = max(mejor,minimaxPoda(tablero, profundidad +1, false, alfa, beta));
                    alfa = max(alfa,mejor);

                    
                    
                    
                    tablero.hacerJugada(' ',fila,col);

                    if (beta <= alfa) { //Poda
                        poda = true;
                        break;
                    }
                }
            }
        }
        return mejor;
    }
    else{
        int peor = INT_MAX;
        for(int fila = 0; fila < 3 && !poda; ++fila){
            for(int col = 0; col < 3; ++col){
                if(tablero.valido(fila,col)){
                    tablero.hacerJugada('X',fila,col);

                    peor = min(peor,minimaxPoda(tablero, profundidad +1, true, alfa, beta));
                    beta = min(beta, peor);
                    
                    
                    
                    tablero.hacerJugada(' ',fila,col);

                    if (beta <= alfa) { //Poda
                        poda = true;
                        break;
                    }
                }
            }
        }
       
        return peor;
    }
}
pair<int,int> Cpu::mejorJugada(Tablero tablero){
    int mejorValor = INT_MIN;
    pair<int,int> mejorMov = {-1,-1};
    int cont = 0;
    for(int fila = 0; fila < 3; ++fila){
        for(int col = 0; col < 3; ++col){
            if(tablero.valido(fila,col)){
                //Se simula la jugada
                tablero.hacerJugada('O',fila,col);
                
                int valor = minimaxPoda(tablero, 0, false, INT_MIN, INT_MAX);
                
                tablero.hacerJugada(' ', fila,col);
                    
                if(valor >= mejorValor) {
                    
                    mejorValor = valor;
                    mejorMov = {fila,col};
                }
            }
        }
    }


    return mejorMov;
}