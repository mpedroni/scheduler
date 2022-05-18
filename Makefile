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

rr: driver.o list.o CPU.o schedule_rr.o
	mkdir -p bin
	$(CC) $(CFLAGS) -o bin/rr driver.o schedule_rr.o list.o CPU.o
	./bin/rr rr-schedule.txt

priority_rr: driver.o list.o CPU.o schedule_rrp.o
	$(CC) $(CFLAGS) -o priority_rr driver.o schedule_priority_rr.o list.o CPU.o

driver.o: driver.c
	$(CC) $(CFLAGS) -c driver.c

schedule_rr.o: schedule_rr.c
	$(CC) $(CFLAGS) -c schedule_rr.c
	
schedule_rrp.o: schedule_rrp.c
	$(CC) $(CFLAGS) -c schedule_rrp.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

CPU.o: CPU.c CPU.h
	$(CC) $(CFLAGS) -c CPU.c
