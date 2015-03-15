CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS =

SOURCES = main.cpp 

HEADERS = 

OUTPUT = lab10

L10: ${SOURCES} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SOURCES} -o ${OUTPUT}

clean:
	rm -f ${OUTPUT}