#include "cpu.h"

cpu::cpu(char tablero[3][3]){

    this -> tablero[3][3];    // acá entrega el tablero de en la jugada actual
    
}

void preconstruct(int turnos,char jugadorActual){  //ve todos los casos posibles desde esa jugada
    if (turnos > 9){return;}
    //acá tendría que ir la iteración de X y O en todas las casillas 

    else if (verificarGanador) {
        return;
        //acá hay que añadir que se añada el resultado a la matriz de recorridos
    }
    else{

        preconstruct(turnos+1, jugadorActual = (jugadorActual == 'X') ? 'O' : 'X'); //se eleva en 1 los turnos y se cambia el jugador (revisar esto último)
        
    }
}