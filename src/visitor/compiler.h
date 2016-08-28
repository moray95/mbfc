#pragma once
#include "visitor.h"
#include <iostream>

namespace visitor
{
  class Compiler : public Visitor
  {
  public:
    using super_type = Visitor;
    using super_type::visit;
    Compiler() = delete;
    Compiler(std::ostream& out);
    void compile(
        std::vector<std::shared_ptr<instruction::Instruction>>& instructions);
    virtual void visit(instruction::DecByteInstruction& instruction) override;
    virtual void visit(instruction::DecPtrInstruction& instruction) override;
    virtual void visit(instruction::InByteInstruction& instruction) override;
    virtual void visit(instruction::IncByteInstruction& instruction) override;
    virtual void visit(instruction::IncPtrInstruction& instruction) override;
    virtual void visit(instruction::LoopInstruction& instruction) override;
    virtual void visit(instruction::OutByteInstruction& instruction) override;

  private:
    std::ostream& out_;
  };
}
