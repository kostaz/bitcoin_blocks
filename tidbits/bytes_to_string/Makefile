CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-std=c++11

SRCS=$(wildcard *.cpp)
EXECS=$(subst .cpp,,$(SRCS))

all: $(EXECS)

$(EXECS):
	$(CXX) $(CPPFLAGS) -o $@ $@.cpp

clean:
	$(RM) $(EXECS)
