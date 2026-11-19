#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// -- FUNCTIONS -- //
void check_limits(int *state_x, int *state_y) {
    if (*state_x < 0) {
        *state_x += 1;
    }
    else if (*state_x > 9) {
        *state_x -= 1;
    }
    if (*state_y < 0) {
        *state_y += 1;
    }
    else if (*state_y > 9) {
        *state_y -= 1;
    }
}
// ^^ FUNCTIONS ^^ //

int main() {

    // -- initilize variables -- //
    char grid[10][10];
    char input[10];
    int state_x = 0;
    int state_y = 0;

    while (1) {
	// -- getting input -- //
        printf("[-] Input (w/s/a/d) >> ");
        scanf(" %c", input);
 	
	// -- making the last box empty -- //
	grid[state_x][state_y] = 'O';

	// -- if statements -- //
        if (strcmp(input, "a") == 0) {
            state_x += 1;
        }
        else if (strcmp(input, "w") == 0) {
            state_y += 1;
        }
        else if (strcmp(input, "d") == 0) {
            state_x -= 1;
        }
        else if (strcmp(input, "s") == 0) {
            state_y -= 1;
        }
        else {
            printf("wrong input");
        }


        check_limits(&state_x, &state_y);
        printf("y - %d\nx - %d", state_y, state_x);

        
        // -- updating grid -- //
        grid[state_x][state_y] = 'X';
	
	// -- print grid -- //
    }

    return 0;
}
