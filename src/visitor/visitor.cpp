#include "visitor.h"
#include <instruction/dec-byte.h>
#include <instruction/dec-ptr.h>
#include <instruction/in-byte.h>
#include <instruction/inc-byte.h>
#include <instruction/inc-ptr.h>
#include <instruction/instruction.h>
#include <instruction/loop.h>
#include <instruction/out-byte.h>

using visitor::Visitor;

void Visitor::visit(std::vector<std::shared_ptr<instruction::Instruction>>& instructions)
{
  for (auto& instruction : instructions)
  {
    instruction->accept(*this);
  }
}

void Visitor::visit(instruction::Instruction& instruction)
{
  instruction.accept(*this);
}

void Visitor::visit(instruction::DecByteInstruction&)
{
}

void Visitor::visit(instruction::DecPtrInstruction&)
{
}

void Visitor::visit(instruction::InByteInstruction&)
{
}

void Visitor::visit(instruction::IncByteInstruction&)
{
}

void Visitor::visit(instruction::IncPtrInstruction&)
{
}

void Visitor::visit(instruction::LoopInstruction& loop)
{
  for (auto& i : loop.instructions())
  {
    i->accept(*this);
  }
}

void Visitor::visit(instruction::OutByteInstruction&)
{
}
