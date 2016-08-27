#pragma once
#include <iostream>
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

  struct Options
  {
    bool help = false;
    std::shared_ptr<std::ostream> out = nullptr;
    std::shared_ptr<std::istream> in = nullptr;
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
