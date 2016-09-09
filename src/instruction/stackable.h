#include <stddef.h>

namespace instruction
{
  class Stackable
  {
  public:
    size_t get_count() const;
    void increment_count();

  private:
    size_t count_ = 0;
  };
}
