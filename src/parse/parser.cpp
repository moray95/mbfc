#include "parser.h"
#include <instruction/dec-byte.h>
#include <instruction/dec-ptr.h>
#include <instruction/in-byte.h>
#include <instruction/inc-byte.h>
#include <instruction/inc-ptr.h>
#include <instruction/instruction.h>
#include <instruction/loop.h>
#include <instruction/out-byte.h>
#include <iostream>
#include <vector>

using parse::Parser;

auto Parser::parse(std::istream& stream) -> std::vector<instr_type>
{
  std::vector<instr_type> instructions;
  for (instr_type instr = parse_instr(stream); !stream.eof();
       instr = parse_instr(stream))
  {
    if (instr != nullptr)
    {
      instructions.push_back(instr);
    }
  }
  return instructions;
}

auto Parser::parse_instr(std::istream& stream) -> instr_type
{
  char c;
  stream >> c;
  switch (c)
  {
    case '>':
      return std::static_pointer_cast<instruction::Instruction>(
          std::make_shared<instruction::IncPtrInstruction>());
    case '<':
      return std::static_pointer_cast<instruction::Instruction>(
          std::make_shared<instruction::DecPtrInstruction>());
    case '+':
      return std::static_pointer_cast<instruction::Instruction>(
          std::make_shared<instruction::IncByteInstruction>());
    case '-':
      return std::static_pointer_cast<instruction::Instruction>(
          std::make_shared<instruction::DecByteInstruction>());
    case '.':
      return std::static_pointer_cast<instruction::Instruction>(
          std::make_shared<instruction::OutByteInstruction>());
    case ',':
      return std::static_pointer_cast<instruction::Instruction>(
          std::make_shared<instruction::InByteInstruction>());
    case '[':
    {
      std::vector<instr_type> instrs;
      while (stream.peek() != ']' && !stream.eof())
      {
        instrs.push_back(parse_instr(stream));
      }
      if (stream.get() != ']') // Consume the `]' and check for unmatched `['
      {
        // TODO: Handle error correctly
        std::cerr << "Unmatched [" << std::endl;
        return nullptr;
      }
      return std::static_pointer_cast<instruction::Instruction>(
          std::make_shared<instruction::LoopInstruction>(std::move(instrs)));
    }
    default:
      return nullptr;
  }
}
