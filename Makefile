CXX = g++
CXXFLAGS = -O3 -Wall

all: pi_estimator

clean:
	rm *.o pi_estimator

pi_estimator: main.o
	$(CXX) $(CXXFLAGS) main.o -o pi_estimator

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp
