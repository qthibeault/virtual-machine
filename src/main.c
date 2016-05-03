#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "instructions.h"
#include "registers.h"

const int program[] = {
    ADD, 10, 12,
    PRINT,
    SUB, 10, 7,
    PRINT,
    HLT
};

bool running = true;
int registers[NUM_OF_REGISTERS];

int fetch()
{

    return program[registers[IP]];
}

void eval(int instruction)
{

    switch(instruction)
    {
        case HLT: {
            running = false;
            break;
        }

        case ADD: {
            registers[IP]++;
            registers[A] = fetch();
            registers[IP]++;
            registers[B] = fetch();
            registers[RES] = registers[A] + registers[B];
            break;
        }

        case SUB: {
            registers[IP]++;
            registers[A] = fetch();
            registers[IP]++;
            registers[B] = fetch();
            registers[RES] = registers[A] - registers[B];
            break;
        }

        case PRINT: {

            printf("Result: %d \n", registers[RES]);

            break;
        }
    }
}

int main()
{
    /* SETUP */
    registers[IP] = 0;
    registers[SP] = 0;

    while(running)
    {
        eval(fetch());
        registers[IP]++;
    }

    return 0;
}
