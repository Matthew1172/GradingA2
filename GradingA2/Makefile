CXX = g++
CXXFLAGS = -Wall -g

main: GradingA2.o sequence2.o node2.o
	$(CXX) $(CXXFLAGS) -o main GradingA2.o sequence2.o node2.o
GradingA2.o: GradingA2.cpp
	$(CXX) $(CXXFLAGS) -c GradingA2.cpp
sequence2.o: sequence2.h sequence2.cpp
	$(CXX) $(CXXFLAGS) -c sequence2.h sequence2.cpp
node2.o: node2.cpp node2.h
	$(CXX) $(CXXFLAGS) -c node2.h node2.cpp


#main: main_onlineshopping.o ItemToPurchase.o
#	$(CXX) $(CXXFLAGS) -o main main_onlineshopping.o ItemToPurchase.o
#main_onlineshopping.o: main_onlineshopping.cpp ItemToPurchase.cpp ItemToPurchase.h
#	$(CXX) $(CXXFAGS) -c main_onlineshopping.cpp
#ItemToPurchase.o: ItemToPurchase.h 