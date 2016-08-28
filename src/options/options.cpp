#include "options.h"
#include <iostream>

using options::Options;

bool& Options::help()
{
  return help_;
}

bool& Options::interpret()
{
  return interpret_;
}

std::ostream& Options::out()
{
  if (out_ != nullptr)
  {
    return *out_;
  }
  else
  {
    return std::cout;
  }
}

std::istream& Options::in()
{
  if (in_ != nullptr)
  {
    return *in_;
  }
  else
  {
    return std::cin;
  }
}

void Options::set_in(std::shared_ptr<std::istream> stream)
{
  in_ = stream;
}

void Options::set_out(std::shared_ptr<std::ostream> stream)
{
  out_ = stream;
}

