#pragma once

#include "instruction.h"
#include <visitor/visitor.h>

namespace instruction
{
  class InByteInstruction : public Instruction
  {
    virtual void accept(visitor::Visitor& v) override;
  };
}
