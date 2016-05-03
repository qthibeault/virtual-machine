typedef enum {
    ADD,
    SUB,
    MUL,
    DIV,
    PSH,
    POP,
    HLT
} InstructionSet;

/* TODO I want to implement registers. Then I can push things into registers instead of the stack*/

const int program[] = {
    PSH, 10,
    PSH, 4,
    ADD,
    POP,
    HLT
};

int stack[256];

int instruction_pointer = 0;
int stack_pointer = 0;

int fetch()
{
    return program[instruction_pointer++];
}

void eval(int instruction)
{
    switch(instruction)
    {
        case PSH: {
            stack[stack_pointer++] = program[++instruction_pointer];
        }

        case ADD: {
            int a = stack[stack_pointer--];
            int b = stack[stack_pointer--];

            int result = a + b;
            stack[++stack_pointer] = result;
        }

        /* TODO Other instructions here */
    }
}

int main()
{
    int instruction = 0;
    while(instruction != HLT)
    {
        instruction = fetch();
        eval(instruction);
    }

    return 0;
}
