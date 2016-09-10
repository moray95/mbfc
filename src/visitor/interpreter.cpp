#include "interpreter.h"
#include <instruction/dec-byte.h>
#include <instruction/dec-ptr.h>
#include <instruction/in-byte.h>
#include <instruction/inc-byte.h>
#include <instruction/inc-ptr.h>
#include <instruction/instruction.h>
#include <instruction/loop.h>
#include <instruction/out-byte.h>
#include <iostream>

using visitor::Interpreter;

Interpreter::Interpreter() : data_(100000, 0)
{
}

void Interpreter::visit(instruction::DecByteInstruction& instr)
{
  data_[index_] -= instr.get_count();
}

void Interpreter::visit(instruction::DecPtrInstruction& instr)
{
  if (index_ < instr.get_count())
  {
    throw InterpreterException("Pointer underflow");
  }
  index_ -= instr.get_count();
}

void Interpreter::visit(instruction::InByteInstruction&)
{
  std::cin >> data_[index_];
}

void Interpreter::visit(instruction::IncByteInstruction& instr)
{
  data_[index_] += instr.get_count();
}

void Interpreter::visit(instruction::IncPtrInstruction& instr)
{
  index_ += instr.get_count();
  if (index_ >= data_.size())
  {
    data_.resize(index_ + 1);
  }
}

void Interpreter::visit(instruction::LoopInstruction& loop)
{
  while (data_[index_])
  {
    super_type::visit(loop);
  }
}

void Interpreter::visit(instruction::OutByteInstruction&)
{
  std::cout << data_[index_];
}
