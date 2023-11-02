CXX=g++
CXXFLAGS=-std=c++17 -g -pedantic -Wall -Wextra -Werror -fsanitize=address,undefined -fno-omit-frame-pointer

q1: q1.cpp q1.s
	$(CXX) $(CXXFLAGS) -o q1 q1.cpp q1.s

q2: q2.cpp
	$(CXX) $(CXXFLAGS) -o q2 q2.cpp

clean:
	rm -f q1 q2