#pragma once
#include <stdexcept>
#include <string>

namespace exception
{
  class MBFCException : public std::exception
  {
  public:
    MBFCException() = delete;
    MBFCException(const std::string& message);
    virtual const char* what() const noexcept override;
    virtual ~MBFCException() = default;

  private:
    const std::string message_;
  };
}
