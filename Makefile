# makefile for scheduling program
#
# make rr - for round-robin scheduling
# make priority_rr - for priority with round robin scheduling

CC=gcc
CFLAGS=-Wall

clean:
	rm -rf *.o
	rm -rf bin/

sjf: driver.o list.o CPU.o
	mkdir -p bin
	$(CC) $(CFLAGS) -o bin/sjf driver.o list.o CPU.o
	./bin/sjf sjf-schedule.txt

rr: driver.o list.o CPU.o
	mkdir -p bin
	$(CC) $(CFLAGS) -o bin/rr driver.o list.o CPU.o
	./bin/rr rr-schedule.txt

priority_rr: driver.o list.o CPU.o 
	mkdir -p bin
	$(CC) $(CFLAGS) -o bin/priority_rr driver.o list.o CPU.o
	./bin/priority_rr rr-schedule_pri.txt
driver.o: driver.c 
	$(CC) $(CFLAGS) -c driver.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

CPU.o: CPU.c CPU.h
	$(CC) $(CFLAGS) -c CPU.c
