#include "compiler.h"
#include <fstream>
#include <instruction/dec-byte.h>
#include <instruction/dec-ptr.h>
#include <instruction/in-byte.h>
#include <instruction/inc-byte.h>
#include <instruction/inc-ptr.h>
#include <instruction/instruction.h>
#include <instruction/loop.h>
#include <instruction/out-byte.h>
#include <iostream>

using visitor::Compiler;

Compiler::Compiler(std::ostream& out) : out_(out)
{
}

void Compiler::compile(
    std::vector<std::shared_ptr<instruction::Instruction>>& instructions)
{
  std::ifstream runtime_stream("src/visitor/runtime.c");
  char c;
  while (runtime_stream.get(c))
  {
    out_ << c;
  }
  out_ << "\n";
  out_ << "int main()\n"
          "{\n"
          "struct context ctx;\n"
          "ctx_init(&ctx);\n";
  super_type::visit(instructions);
  out_ << "ctx_free(&ctx);\n"
          "return 0;\n"
          "}\n";
}

void Compiler::visit(instruction::DecByteInstruction& instr)
{
  out_ << "ctx_dec_byte(&ctx, " << instr.get_count() << ");\n";
}

void Compiler::visit(instruction::DecPtrInstruction& instr)
{
  out_ << "ctx_dec_ptr(&ctx, " << instr.get_count() << ");\n";
}

void Compiler::visit(instruction::InByteInstruction&)
{
  out_ << "ctx_in_byte(&ctx);\n";
}

void Compiler::visit(instruction::IncByteInstruction& instr)
{
  out_ << "ctx_inc_byte(&ctx, " << instr.get_count() << ");\n";
}

void Compiler::visit(instruction::IncPtrInstruction& instr)
{
  out_ << "ctx_inc_ptr(&ctx, " << instr.get_count() << ");\n";
}

void Compiler::visit(instruction::LoopInstruction& instruction)
{
  out_ << "while (ctx_get_byte(&ctx))\n{\n";
  super_type::visit(instruction);
  out_ << "}\n";
}

void Compiler::visit(instruction::OutByteInstruction&)
{
  out_ << "ctx_out_byte(&ctx);\n";
}
