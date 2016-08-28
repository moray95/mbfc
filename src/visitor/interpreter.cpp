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

void Interpreter::visit(instruction::DecByteInstruction&)
{
  data_[index_]--;
}

void Interpreter::visit(instruction::DecPtrInstruction&)
{
  if (index_ == 0)
  {
    throw InterpreterException("Pointer underflow");
  }
  index_--;
}

void Interpreter::visit(instruction::InByteInstruction&)
{
  std::cin >> data_[index_];
}

void Interpreter::visit(instruction::IncByteInstruction&)
{
  data_[index_]++;
}

void Interpreter::visit(instruction::IncPtrInstruction&)
{
  index_++;
  if (index_ == data_.size())
  {
    data_.emplace_back();
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
