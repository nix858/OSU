CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS =

SOURCES = main.cpp creature.cpp goblin.cpp barbarian.cpp reptile.cpp shadow.cpp blueMen.cpp dice.cpp battle.cpp

HEADERS = creature.h goblin.h barbarian.h reptile.h shadow.h blueMen.h dice.h battle.h

OUTPUT = a4

A4: ${SOURCES} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SOURCES} -o ${OUTPUT}

clean:
	rm -f ${OUTPUT}