OBJECTS =task1Main.o EVector.o
CC = CC
CFLAGS = -c
LDFLAGS = 

all:	EVec
EVec:	$(OBJECTS)
	$(CC) -o EVec $(OBJECTS)
task1Main.o:	task1Main.cpp EVector.h
	$(CC) $(CFLAGS) task1Main.cpp
EVector.o:	EVector.cpp EVector.h
	$(CC) $(CFLAGS) EVector.cpp

clean:
	rm -rf *.o
