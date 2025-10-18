#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 10
#define MAX_HEIGHT 5
#define ASCII_A 65

void init_board(int board[MAX_HEIGHT][MAX_WIDTH]) {
    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            board[i][j] = 0;
        }
    }
}

/*
 * 0 - Water                - print 0
 * 1 - Ship                 - print 1
 * 2 - shoot on the water   - print W
 * 3 - shoot on a ship.     - print X
 */
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
            if (board[i][j] == 0 || board[i][j] == 1)
                printf("%d", board[i][j]);
            else if (board[i][j] == 2)
                printf("%c", 'W');
            else if (board[i][j] == 3)
                printf("%c", 'X');
        }
        printf("\n");
    }
}

int get_position(int maximum, int with_length) {
    int position;

    srand(time(NULL));

    do {
        position = rand() % maximum;
    } while((position + with_length) > maximum);

    return position;
}

int can_be_floated(int length, int is_vertical, int first_position, int second_position
    , int board[MAX_HEIGHT][MAX_WIDTH]) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (is_vertical == 1)
            sum += board[(first_position + i)][second_position];
        else
            sum += board[second_position][(first_position + i)];
    }

    return sum;
}

void float_ship(int length, int is_vertical, int first_position, int second_position
    , int board[MAX_HEIGHT][MAX_WIDTH]) {

    for (int i = 0; i < length; i++) {
        if (is_vertical == 1)
            board[(first_position + i)][second_position] = 1;
        else
            board[second_position][(first_position + i)] = 1;
    }
}

void build_ship(int length, int board[MAX_HEIGHT][MAX_WIDTH]) {

    srand(time(NULL));
    int first_limit, second_limit;
    int first_position = 0;
    int second_position = 0;

    int is_vertical = rand() % 2 + 1;

    if (is_vertical == 1) {
        first_limit = MAX_HEIGHT;
        second_limit = MAX_WIDTH;
    }else {
        first_limit = MAX_WIDTH;
        second_limit = MAX_HEIGHT;
    }

    do {
        first_position = get_position(first_limit, length);
        second_position = get_position(second_limit, 0);
    }while (can_be_floated(length, is_vertical, first_position, second_position, board) > 0);

    float_ship(length, is_vertical, first_position, second_position, board);
}

/*
 * 0 - Water
 * 1 - Ship
 * 2 - shoot on the water
 * 3 - shoot on a ship.
 */
void calculate_shoot(int x, int y, int board[MAX_HEIGHT][MAX_WIDTH]) {
    if (board[y][x] == 0)
        board[y][x] = 2;
    else if (board[y][x] == 1)
        board[y][x] = 3;
}

int main(void) {
    /*
     * HUNDIR LA FLOTA
     *
     * [X] - Crear array bidimensional a 0 y mostrar en pantalla (junto con coordenadas).
     * [ ] - Inicializar los barcos a 1 en la matriz board.
     *      [X] - Inicializar barcos en horizontal o vertical aleatoriamente.
     *      [X] - Flotar barcos donde haya espacio disponible y no choque con otros barcos.
     * [X] - Calcular: agua o barco tocado.
     * [ ] - Calcular: fin del juego.
     * [ ] - Recoger respuesta de coordenadas del usuarios.
     * [ ] - Menú.
     */

    int board[MAX_HEIGHT][MAX_WIDTH];

    init_board(board);

    // build_ship(4, board);
    // build_ship(3, board);
    // build_ship(3, board);
    // build_ship(2, board);

    float_ship(4, 1, 0, 0, board);

    calculate_shoot(0, 0, board);
    calculate_shoot(1, 0, board);

    print_board(board);


    return 0;
}