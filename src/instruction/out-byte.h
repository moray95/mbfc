#pragma once

#include "instruction.h"
#include <visitor/visitor.h>

namespace instruction
{
  class OutByteInstruction : public Instruction
  {
  public:
    virtual void accept(visitor::Visitor& v) override;
  };
}
