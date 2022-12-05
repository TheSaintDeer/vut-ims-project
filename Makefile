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
	./$(TARGET) --mx 1 --my 0 --ma 45 --v 70 --cd 0 --wx 0 --wy 0 --wz 0 --wf 0 --d 600 --ro 0.1

test2:
	./$(TARGET) --mx 1 --my 0 --ma 45 --v 70 --cd 0.5 --wx 0 --wy 0 --wz 0 --wf 0 --d 600 --ro 0.1


test3:
	./$(TARGET) --mx 1 --my 0 --ma 45 --v 70 --cd 0.5 --wx 1 --wy 0 --wz 0 --wf 5 --d 600 --ro 0.1

test4:
	./$(TARGET) --mx 1 --my 0 --ma 45 --v 70 --cd 0.5 --wx -1 --wy 0 --wz 0 --wf 5 --d 600 --ro 0.1
