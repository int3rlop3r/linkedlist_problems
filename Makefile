
CC= gcc
CWD= $(shell pwd)

all:
	$(CC) *.c -g -o problems
clean:
	rm problems
buildrun:
	$(CC) *.c -g -o problems
	$(CWD)/problems
