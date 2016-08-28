#include <fstream>
#include <iostream>
#include <options/option-parser.h>
#include <parse/parser.h>
#include <visitor/interpreter.h>
#include <visitor/visitor.h>
#include <options/options.h>

namespace
{
  void help(const char* name)
  {
    std::cout << "mbfc, The Brainfuck compiler and interpreter\n"
              << "Usage: " << name << " [FILE] [OPTIONS...]\n"
              << "Options:\n";
    for (const auto& option : options::options)
    {
      std::cout << option.first << "\t" << option.second << "\n";
    }
  }
}

int main(int argc, char** argv)
{
  options::OptionParser option_parser(argc, argv);
  options::Options options = option_parser.parse_options();
  if (options.help())
  {
    help(argv[0]);
    return 0;
  }
  if (!options.interpret())
  {
    std::cerr << "Compiler not implemented yet, use -i to interpret"
              << std::endl;
    return 1;
  }
  parse::Parser parser;
  auto instrs = parser.parse(options.in());
  visitor::Interpreter interpreter;
  interpreter.visit(instrs);
  return 0;
}
