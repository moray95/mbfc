#pragma once

#include "visitor.h"
#include <mbfc-exception.h>

namespace visitor
{
  class InterpreterException : public exception::MBFCException
  {
  public:
    InterpreterException(const std::string& message) : MBFCException(message)
    {
    }
  };

  class Interpreter : public Visitor
  {
  public:
    using super_type = Visitor;
    using super_type::visit;
    Interpreter();
    virtual void visit(instruction::DecByteInstruction& instruction) override;
    virtual void visit(instruction::DecPtrInstruction& instruction) override;
    virtual void visit(instruction::InByteInstruction& instruction) override;
    virtual void visit(instruction::IncByteInstruction& instruction) override;
    virtual void visit(instruction::IncPtrInstruction& instruction) override;
    virtual void visit(instruction::LoopInstruction& instruction) override;
    virtual void visit(instruction::OutByteInstruction& instruction) override;
    virtual ~Interpreter() = default;

  private:
    std::vector<char> data_;
    size_t index_ = 0;
  };
}
