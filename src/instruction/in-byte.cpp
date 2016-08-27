#include "in-byte.h"

using instruction::InByteInstruction;

void InByteInstruction::accept(visitor::Visitor& v)
{
  v.visit(*this);
}
