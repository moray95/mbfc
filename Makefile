CXX     ?= gcc
CXXFLAGS = -std=c++14 -pedantic -Wextra -Wall -I./src
OPTFLAGS = -O3 -faggressive-loop-optimizations -mtune=native \
           -fstrict-aliasing -fdelete-null-pointer-checks
DBGFLAGS = -g3 -fno-inline
EXEC     = mbfc
SRC      = $(shell find src | grep '.cpp')
OBJS     = $(addsuffix .o, $(basename $(SRC)))


#$(EXEC): release

release: CXXFLAGS += $(OPTFLAGS)
release: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $(EXEC)

debug: CXXFLAGS += $(DBGFLAGS)
debug: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $(EXEC)

clean:
	$(RM) $(OBJS) $(EXEC)

.PHONY: release debug clean
