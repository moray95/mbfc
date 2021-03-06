#pragma once

#include "instruction.h"
#include "stackable.h"
#include <visitor/visitor.h>

namespace instruction
{
  class DecByteInstruction : public Instruction, public Stackable
  {
  public:
    virtual void accept(visitor::Visitor& v) override;
  };
}
