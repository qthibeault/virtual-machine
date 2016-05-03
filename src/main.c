typedef enum {
  ADD,
  SUB,
  MUL,
  DIV,
  PSH,
  POP,
  HLT
} InstructionSet;

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

void eval(int instruction)
{
  switch(instruction)
  {
    case PSH: {
      stack[stack_pointer++] = program[++instruction_pointer];
    }
  }
}

int main()
{
  int instruction = 0;
  while(instruction != HLT)
  {
    instruction = program[instruction_pointer++];
    eval(instruction);
  }

  return 0;
}
