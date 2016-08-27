#include <fstream>
#include <iostream>
#include <parse/parser.h>

int main(int argc, char** argv)
{
  parse::Parser parser;
  if (argc == 1)
  {
    parser.parse(std::cin);
  }
  else
  {
    std::ifstream stream(argv[1]);
    parser.parse(stream);
  }
  return 0;
}
