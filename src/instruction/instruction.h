#pragma once
#include <visitor/visitor.h>

namespace instruction
{
  class Instruction
  {
  public:
    virtual void accept(visitor::Visitor& v) = 0;
  };
}
