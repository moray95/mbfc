#include <stddef.h>
#include "stackable.h"

using instruction::Stackable;

size_t Stackable::get_count() const
{
  return count_;
}

void Stackable::increment_count()
{
  count_++;
}
