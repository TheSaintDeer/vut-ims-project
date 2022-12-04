# VUT FIT ISA - feedreader.
#
# Feedreader Makefile.
# Author - Maksym Koval <xkoval20@stud.fit.vutbr.cz>
#

# the compiler: gcc for C program, define as g++ for C++
CC = g++
LOGIN = xgolik00_xkoval20
# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall
#LDLIBS =

ARCH = tar
# The build target
TARGET = main
LIST = PointN.cpp NystromN.cpp FlyingBall.cpp Wind.cpp Test.cpp
HEADERS = PointN.h NystromN.h FlyingBall.h Wind.h Test.h
ADDITIONS = Makefile

all: clean $(TARGET) tar

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp $(LIST) $(LDLIBS)

clean:
	$(RM) $(TARGET) $(LOGIN).tar

tar:
	$(ARCH) cvf $(LOGIN).tar $(TARGET).cpp $(LIST) $(HEADERS) $(ADDITIONS)