#pragma once
#include <vector>
#include <memory>

namespace instruction
{
  class Instruction;
  class DecByteInstruction;
  class DecPtrInstruction;
  class InByteInstruction;
  class IncByteInstruction;
  class IncPtrInstruction;
  class LoopInstruction;
  class OutByteInstruction;
}

namespace visitor
{
  class Visitor
  {
  public:
    virtual void visit(std::vector<std::shared_ptr<instruction::Instruction>>& instructions);
    virtual void visit(instruction::DecByteInstruction& instruction);
    virtual void visit(instruction::DecPtrInstruction& instruction);
    virtual void visit(instruction::InByteInstruction& instruction);
    virtual void visit(instruction::IncByteInstruction& instruction);
    virtual void visit(instruction::IncPtrInstruction& instruction);
    virtual void visit(instruction::LoopInstruction& instruction);
    virtual void visit(instruction::OutByteInstruction& instruction);
    virtual ~Visitor() = default;
  };
}
