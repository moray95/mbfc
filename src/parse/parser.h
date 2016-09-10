#pragma once
#include <instruction/instruction.h>
#include <iostream>
#include <memory>
#include <vector>

namespace parse
{
  class Parser
  {
  public:
    using instr_type = std::shared_ptr<instruction::Instruction>;
    std::vector<instr_type> parse(std::istream& stream);

  private:
    instr_type parse_instr(std::istream& stream);
    template <typename T>
    instr_type stack_instructions(char instr_char, std::istream& stream);
  };
}
