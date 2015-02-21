CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS =

SOURCES = main.cpp creature.cpp goblin.cpp barbarian.cpp reptile.cpp shadow.cpp blueMen.cpp dice.cpp 

HEADERS = creature.h goblin.h barbarian.h reptile.h shadow.h blueMen.h dice.h

OUTPUT = assignment3

LAB5: ${SOURCES} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SOURCES} -o ${OUTPUT}

clean:
	rm -f ${OUTPUT}