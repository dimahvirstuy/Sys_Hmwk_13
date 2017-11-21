all: pipe.c
	gcc -o pipe pipe.c

run: pipe
	./pipe
