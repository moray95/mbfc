#include "instruction.h"
#include "loop.h"

using instruction::LoopInstruction;

LoopInstruction::LoopInstruction(std::vector<instr_type>&& instructions)
  : instructions_(instructions)
{
}

auto LoopInstruction::instructions() -> const std::vector<instr_type>&
{
  return instructions_;
}

void LoopInstruction::accept(visitor::Visitor& v)
{
  v.visit(*this);
}
