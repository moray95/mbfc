#include "inc-ptr.h"

using instruction::IncPtrInstruction;

void IncPtrInstruction::accept(visitor::Visitor& v)
{
  v.visit(*this);
}
