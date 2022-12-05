# VUT FIT ISA - feedreader.
#
# Feedreader Makefile.
# Author - Maksym Koval <xkoval20@stud.fit.vutbr.cz>
#

# the compiler: gcc for C program, define as g++ for C++
CC = g++
LOGIN = 09_xgolik00_xkoval20
# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall
#LDLIBS =

ARCH = tar
# The build target
TARGET = main
OUT = out.txt
LIST = PointN.cpp NystromN.cpp FlyingBall.cpp Wind.cpp Test.cpp
HEADERS = PointN.h NystromN.h FlyingBall.h Wind.h Test.h
ADDITIONS = Makefile

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp $(LIST) $(LDLIBS)

all: clean $(TARGET) tar

clean:
	$(RM) $(TARGET) $(LOGIN).tar $(OUT)

tar:
	$(ARCH) cvf $(LOGIN).tar $(TARGET).cpp $(LIST) $(HEADERS) $(ADDITIONS)

test1:
	./$(TARGET) 1 0 45 70 0 0 0 0 0 600 0.1

test2:
	./$(TARGET) 1 0 45 70 0.5 0 0 0 0 600 0.1

test3:
	./$(TARGET) 1 0 45 70 0.5 1 0 0 5 600 0.1

test4:
	./$(TARGET) 1 0 45 70 0.5 -1 0 0 5 600 0.1