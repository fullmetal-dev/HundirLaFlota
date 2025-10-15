#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 10
#define MAX_HEIGHT 5
#define ASCII_A 65

struct ship {
    int position[2];
    char* name;
};

void init_board(int board[MAX_HEIGHT][MAX_WIDTH]) {
    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            board[i][j] = 0;
        }
    }
}

void print_board(int board[MAX_HEIGHT][MAX_WIDTH]) {

    printf(" "); // blank space.

    // coordinates 1 - 10.
    for (int i = 0; i < MAX_WIDTH; i++)
        printf("%d", i);

    printf("\n");

    for (int i = 0; i < MAX_HEIGHT; i++) {

        // Coordinates A - E.
        char letter = i + ASCII_A;
        printf("%c", letter);

        // Rest of the row.
        for (int j = 0; j < MAX_WIDTH; j++) {
            printf("%d", board[i][j]);
        }
        printf("\n");
    }
}

void build_ship(int length, int board[MAX_HEIGHT][MAX_WIDTH]) {

    srand(time(NULL));
    int first_position_x = 0;
    int position_y = 0;

    do {
        first_position_x = rand() % MAX_HEIGHT;
    } while((first_position_x + length) > MAX_HEIGHT);

    do {
        position_y = rand() % MAX_WIDTH;
    } while (position_y > MAX_WIDTH);

    for (int i = 0; i < length; i++) {
        board[(first_position_x + i)][position_y] = 1;
    }

}

int main(void) {
    /*
     * HUNDIR LA FLOTA
     *
     * [X] - Crear array bidimensional a 0 y mostrar en pantalla (junto con coordenadas).
     * [ ] - Crear arrays barcos.
     *      - 1 Acorazado     4
     *      - 2 Crucero       3
     *      - 2 Destructores  2
     *      - 2 Submarino     1
     * [ ] - Inicializar los barcos a 1 en el array inicial.
     * [ ] - Recoger respuesta de coordenadas del usuarios.
     * [ ] - Calcular: agua, barco tocado o barco hundido.
     * [ ] - Calcular: fin del juego.
     * [ ] - Menú.
     */

    int board[MAX_HEIGHT][MAX_WIDTH];

    init_board(board);

    build_ship(4, board);

    print_board(board);


    return 0;
}