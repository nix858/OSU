CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS =

SOURCES = main.cpp bounty.cpp game.cpp gameEntity.cpp 
					gameState.cpp location.cpp menu.cpp person.cpp 
					planet.cpp planet.cpp question.cpp

HEADERS = bounty.h game.h gameEntity.h gameState.h
					location.h menu.h person.h planet.h planet.h question.h

OUTPUT = finalProject

finalProject: ${SOURCES} ${HEADERS}
  ${CXX} ${CXXFLAGS} ${SOURCES} -o ${OUTPUT}

clean:
  rm -f ${OUTPUT}