#include "instruction.h"
#include "loop.h"

using instruction::LoopInstruction;

LoopInstruction::LoopInstruction(std::vector<instr_type>&& instructions)
  : instructions_(instructions)
{
}
