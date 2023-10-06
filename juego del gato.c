#include <stdio.h>
#include <stdlib.h>

char tablero[3][3];
void inicializarTablero() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = ' ';
        }
    }
}//esta funcion lo que hace es inicializar el tablero mediante un arreglo bidimensional, y le asigna un valor de " " a esa posicion del arreglo don de iran los tiros de cada jugador

void mostrarTablero() {
    system("cls");
    printf("    0     1    2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d   ", i);
        for (int j = 0; j < 3; j++) {
            printf("%c", tablero[i][j]);
            if (j < 2) printf("  |  ");
        }
        printf("\n");
        if (i < 2) printf("    -  +  -  +  -\n");
    }
}// esta funcion muestra el tablero de una manera estetica para que el usuario pueda ver de una manera facil y entendible los movimientos realizados y los que puede realizar

int verificarGanador(char jugador) {
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador) return 1;
        if (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador) return 1;
    }
    if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador) return 1;
    if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador) return 1;
    return 0;
} // Esta funcion verifica qn a sido el ganador del juego esto mientras compara en cada ocacion las posibles maneras en las que se pudiera ganar

int main() {
    int fila, columna;
    char jugadorActual = 'X';
    int jugadas = 0;

    inicializarTablero();

    while (1) {
        mostrarTablero();

        if (jugadorActual == 'X') {
            jugadorActual = 'O';
        } else {
        jugadorActual = 'X';
        }//esto ayuda a que en cada iteracion se vaya modificando el valor de el jugador en cada turno


        printf("Jugador %c, ingresa fila y columna (ejemplo: 1 2): ", jugadorActual);
        scanf("%d %d", &fila, &columna);// ingresar las coordenadas de donde se desea agregar el tiro

        if(tablero[fila][columna] == 'X' || tablero[fila][columna] == 'O'){//verifica si las coordenadas dadas estan libres
             printf("Movimiento inválido. Inténtalo de nuevo.\n");
        }else{
            if (fila >= 0 && fila < 3 && columna >= 0 && columna < 3 && tablero[fila][columna] == ' ') {//verifica si las coordenadas dadas son validas
                tablero[fila][columna] = jugadorActual;
                jugadas++;

                if (verificarGanador(jugadorActual)) {//manda a llamar a la funcion de verificar el ganador y si es true rompe el ciclo y muestra el ganador, si no se vuelve a ejecutar
                    mostrarTablero();
                    printf("¡Jugador %c ha ganado!\n", jugadorActual);
                    break;
                }

                if (jugadas == 9) {
                    mostrarTablero();
                    printf("¡Empate!\n");
                    break;
                }//rompe el ciclo por numero maximo de movimientos
        } else {
            printf("Movimiento inválido. Inténtalo de nuevo.\n");
        }
        }
    }

    return 0;
}

