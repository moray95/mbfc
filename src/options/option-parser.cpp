#include "option-parser.h"
#include <fstream>
#include <string>
#include <unistd.h>

using options::OptionParser;

namespace
{
  bool parse_file(const std::vector<std::string>& args, size_t& index,
                  options::Options& options)
  {
    options.in = std::static_pointer_cast<std::istream>(
        std::make_shared<std::ifstream>(args[index]));
    return true;
  }

  bool parse_out(const std::vector<std::string>& args, size_t& index,
                 options::Options& options)
  {
    if (args[index] != "-o")
    {
      return false;
    }
    if (args.size() <= index + 1)
    {
      throw options::ParseException("-o option requires a filename");
    }
    index++;
    options.out = std::static_pointer_cast<std::ostream>(
        std::make_shared<std::ofstream>(args[index]));
    return true;
  }

  bool parse_help(const std::vector<std::string>& args, size_t& index,
                  options::Options& options)
  {
    if (args[index] == "--help" || args[index] == "-h")
    {
      options.help = true;
      return true;
    }
    return false;
  }

  bool parse_interpret(const std::vector<std::string>& args, size_t& index,
                       options::Options& options)
  {
    if (args[index] == "-i" || args[index] == "--interpret")
    {
      options.interpret = true;
      return true;
    }
    return false;
  }
}

OptionParser::OptionParser(int argc, const char* const* argv)
{
  for (int i = 1; i < argc; i++)
  {
    args_.emplace_back(argv[i]);
  }
}

options::Options OptionParser::parse_options()
{
  using parser_type = std::function<bool(const std::vector<std::string>&,
                                         size_t&, options::Options&)>;
  std::array<parser_type, 4> parsers{parse_out, parse_help, parse_interpret,
                                     parse_file};
  options::Options options;
  for (size_t i = 0; i < args_.size(); i++)
  {
    bool parsed = false;
    for (const auto& parser : parsers)
    {
      if (parser(args_, i, options))
      {
        parsed = true;
        break;
      }
    }
    if (!parsed)
    {
      throw options::ParseException(std::string("Unknown option ") + args_[i]);
    }
  }
  return options;
}
