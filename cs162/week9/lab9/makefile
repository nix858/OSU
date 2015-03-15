CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS =

SOURCES = intstack.cpp main.cpp intqueue.cpp

HEADERS = intstack.h intqueue.h

OUTPUT = lab9

L9: ${SOURCES} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SOURCES} -o ${OUTPUT}

clean:
	rm -f ${OUTPUT}