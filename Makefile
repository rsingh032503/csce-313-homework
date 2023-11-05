CXX=g++
CXXFLAGS=-std=c++17 -g -pedantic -Wall -Wextra -Werror -fsanitize=address,undefined -fno-omit-frame-pointer

q1: q1.cpp q1.s
	$(CXX) $(CXXFLAGS) -o q1 q1.cpp q1.s

q2: q2.cpp
	$(CXX) $(CXXFLAGS) -o q2 q2.cpp

q3: q3.cpp
	$(CXX) $(CXXFLAGS) -o q3 q3.cpp

q4:
	$(CXX) $(CXXFLAGS) -o q4 q4.cpp

q5:
	$(CXX) $(CXXFLAGS) -o q5 q5.cpp

clean:
	rm -f q1 q2 q3 q4 q5