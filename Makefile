CXX = g++
CXXFLAGS = -flto -march=native -mtune=native -O3 -Wall

all: pi_estimator

clean:
	rm *.o pi_estimator

pi_estimator: main.o
	$(CXX) $(CXXFLAGS) -o pi_estimator main.o 

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp
