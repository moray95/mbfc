#pragma once
#include <iostream>
#include <map>
#include <memory>

namespace options
{
  const std::map<std::string, std::string> options{
      {"-h, --help", "Displays this help."},
      {"-o FILE", "Sets the file to compile. If absent, reads from stdin."},
      {"-i", "Interprets the code instead of compiling."}};

  class Options
  {
  public:
    bool& help();
    bool& interpret();
    std::ostream& out();
    std::istream& in();
    void set_in(std::shared_ptr<std::istream> stream);
    void set_out(std::shared_ptr<std::ostream> stream);

  private:
    bool help_ = false;
    bool interpret_ = false;
    std::shared_ptr<std::ostream> out_ = nullptr;
    std::shared_ptr<std::istream> in_ = nullptr;
  };
}
