#pragma once
#include "Tablero.h"
#include <vector>

class Cpu{

    private:
    
    char tablero[3][3];
    int evaluar(Tablero tablero);
    int minimax(Tablero tablero, int profundidad, bool esMax, int alfa, int beta);

    public:
    std::pair<int,int> mejorJugada(Tablero tablero);
};
