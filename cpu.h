#include "main.cpp"

class cpu{

    private:
    
    char tablero[3][3];
    char matrizRecorrido;
    void preconstruct(int turnos,char jugadorActual);

    public:
    cpu(char tablero[3][3]);
};
