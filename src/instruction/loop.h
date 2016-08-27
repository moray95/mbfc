#pragma once
#include "instruction.h"
#include <memory>
#include <vector>
#include <visitor/visitor.h>

namespace instruction
{
  class LoopInstruction : public Instruction
  {
  public:
    using instr_type = std::shared_ptr<instruction::Instruction>;
    LoopInstruction(std::vector<instr_type>&& instructions);
    const std::vector<instr_type>& instructions();
    virtual void accept(visitor::Visitor& v) override;

  private:
    std::vector<instr_type> instructions_;
  };
}
