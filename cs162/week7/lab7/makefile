CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS =

CFSOURCES = createFiles.cpp  
CFOUTPUT = createFiles

SSOURCES = searcher.cpp  
SOUTPUT = searcher

createFiles: ${CFSOURCES}
	${CXX} ${CXXFLAGS} ${CFSOURCES} -o ${CFOUTPUT}

searcher: ${SSOURCES} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SSOURCES} -o ${SOUTPUT}

clean:
	rm -f ${OUTPUT}