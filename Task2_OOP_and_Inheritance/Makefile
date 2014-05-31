OBJECTS =task2Main.o Bill.o ElectricityBill.o GasBill.o TelephoneBill.o
CC = CC
CFLAGS = -c
LDFLAGS = 

all:	Bill
Bill:	$(OBJECTS)
	$(CC) -o Bill $(OBJECTS)
task2Main.o:	task2Main.cpp GasBill.h ElectricityBill.h TelephoneBill.h
	$(CC) $(CFLAGS) task2Main.cpp
Bill.o:	Bill.cpp Bill.h
	$(CC) $(CFLAGS) Bill.cpp
ElectricityBill.o:	ElectricityBill.cpp ElectricityBill.h Bill.h
	$(CC) $(CFLAGS) ElectricityBill.cpp
GasBill.o:	GasBill.cpp GasBill.h Bill.h
	$(CC) $(CFLAGS) GasBill.cpp
TelephoneBill.o:	TelephoneBill.cpp TelephoneBill.h Bill.h
	$(CC) $(CFLAGS) TelephoneBill.cpp
clean:
	rm -rf *.o
