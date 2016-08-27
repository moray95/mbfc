#include "inc-byte.h"

using instruction::IncByteInstruction;

void IncByteInstruction::accept(visitor::Visitor& v)
{
  v.visit(*this);
}
