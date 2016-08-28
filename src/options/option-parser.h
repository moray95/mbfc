#pragma once
#include <iostream>
#include <map>
#include <mbfc-exception.h>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

namespace options
{
  const std::map<std::string, std::string> options{
      {"-h, --help", "Displays this help."},
      {"-o FILE", "Sets the file to compile. If absent, reads from stdin."},
      {"-i", "Interprets the code instead of compiling."}};
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
    bool interpret = false;
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
