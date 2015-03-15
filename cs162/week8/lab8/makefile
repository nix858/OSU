CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS =

SOURCES = lab8.cpp 

HEADERS = 

OUTPUT = lab8

L8: ${SOURCES} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SOURCES} -o ${OUTPUT}

clean:
	rm -f ${OUTPUT}