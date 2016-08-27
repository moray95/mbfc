#include "dec-byte.h"

using instruction::DecByteInstruction;

void DecByteInstruction::accept(visitor::Visitor& v)
{
  v.visit(*this);
}
