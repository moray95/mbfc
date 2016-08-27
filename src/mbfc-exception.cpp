#include "mbfc-exception.h"

using exception::MBFCException;

MBFCException::MBFCException(const std::string& message) : message_(message)
{
}

const char* MBFCException::what() const noexcept
{
  return message_.data();
}
