#pragma once
#include "options.h"
#include <iostream>
#include <map>
#include <mbfc-exception.h>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

namespace options
{
  class ParseException : public exception::MBFCException
  {
  public:
    ParseException(const std::string& message) : MBFCException(message)
    {
    }
    virtual ~ParseException() = default;
  };

  class OptionParser
  {
  public:
    OptionParser(int argc, const char* const* argv);
    Options parse_options();

  private:
    std::vector<std::string> args_;
  };
}
