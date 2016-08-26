CXX     ?= gcc
CFLAGS   = -std=c++14 -pedantic -Wextra -Wall -Isrc
OPTFLAGS = -O3 -faggressive-loop-optimizations -mtune=native
DBGFLAGS = -g3 -fno-inline
EXEC     = mbfc
SRC      = $(shell find src | grep '.cpp')
OBJS     = $(addsuffix .o, $(basename $(SRC)))

$(EXEC): release

release: $(CFLAGS) += $(OPTFLAGS)
release: $(OBJS)
	$(CXX) $(OPTFLAGS) $^ -o $(EXEC)

debug: $(CFLAGS) += $(DBGFLAGS)
debug: $(OBJS)
	$(CXX) $(OPTFLAGS) $^ -o $(EXEC)

clean:
	$(RM) $(OBJS) $(EXEC)

.PHONY: release debug clean
