#pragma once
#include "instruction.h"
#include <memory>
#include <vector>

namespace instruction
{
  class LoopInstruction : public Instruction
  {
  public:
    using instr_type = std::shared_ptr<instruction::Instruction>;
    LoopInstruction(std::vector<instr_type>&& instructions);

  private:
    std::vector<instr_type> instructions_;
  };
}
