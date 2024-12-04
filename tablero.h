#pragma once


class Tablero
{
    public:
        Tablero();
        char tablero[3][3];
        void imprimirTablero();
        bool valido(int f, int c);
        bool verificarGanador(char jugador);
        void hacerJugada(char jugador, int f, int c);
        bool lleno();

};