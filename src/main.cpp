#include <fstream>
#include <iostream>
#include <options/option-parser.h>
#include <options/options.h>
#include <parse/parser.h>
#include <visitor/compiler.h>
#include <visitor/interpreter.h>
#include <visitor/visitor.h>
#include "mbfc-exception.h"

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

int run(int argc, char** argv)
{
  options::OptionParser option_parser(argc, argv);
  options::Options options = option_parser.parse_options();
  if (options.help())
  {
    help(argv[0]);
    return 0;
  }
  parse::Parser parser;
  auto instrs = parser.parse(options.in());
  if (options.interpret())
  {

    visitor::Interpreter interpreter;
    interpreter.visit(instrs);
  }
  else
  {
    visitor::Compiler compiler(options.out());
    compiler.compile(instrs);
  }
  return 0;
}

int main(int argc, char** argv)
{
  try
  {
    return run(argc, argv);
  }
  catch (const exception::MBFCException& e)
  {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
