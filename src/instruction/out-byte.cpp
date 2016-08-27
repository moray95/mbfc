#include "out-byte.h"

using instruction::OutByteInstruction;

void OutByteInstruction::accept(visitor::Visitor& v)
{
  v.visit(*this);
}
