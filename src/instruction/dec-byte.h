#pragma once

#include "instruction.h"
#include <visitor/visitor.h>

namespace instruction
{
  class DecByteInstruction : public Instruction
  {
  public:
    virtual void accept(visitor::Visitor& v) override;
  };
}
