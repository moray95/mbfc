#include "dec-ptr.h"

using instruction::DecPtrInstruction;

void DecPtrInstruction::accept(visitor::Visitor& v)
{
  v.visit(*this);
}
