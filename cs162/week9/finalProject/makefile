CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS =

SOURCES = main.cpp area.cpp bounty.cpp game.cpp gameEntity.cpp invitem.cpp location.cpp menu.cpp person.cpp planet.cpp question.cpp random.cpp

HEADERS = area.h bounty.h game.h gameEntity.h gameState.h invitem.h location.h menu.h person.h planet.h question.h random.h

OUTPUT = bebop

bebop: ${SOURCES} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SOURCES} -o ${OUTPUT}

clean:
	rm -f ${OUTPUT}