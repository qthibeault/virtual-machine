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

int main()
{
  return 0;
}
