#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


void check_limits(int *state_x, int *state_y) {
    if (state_x < -10) {
        state_x += 1;
    }
    else if (state_x > 10) {
        state_x -= 1;
    }
    if (state_y < -10) {
        state_y += 1;
    }
    else if (state_y > 10) {
        state_y -= 1;
    }
}

int main() {

    char grid[10][10];
    char input[10];
    int state_x = 0;
    int state_y = 0;
 
    while (1) {
        printf("[-] Input (w/s/a/d) >> ");
        scanf(" %c", input);
 
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
        
        
    }

    return 0;
}