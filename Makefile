
CC= gcc
CWD= $(shell pwd)

all:
	$(CC) *.c -o problems
clean:
	rm problems
buildrun:
	$(CC) *.c -o problems
	$(CWD)/problems
