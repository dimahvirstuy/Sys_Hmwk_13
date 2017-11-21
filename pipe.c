#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
  int WRITE = 1;
  int READ = 0;
  
  int child[2];
  int parent[2];
  pipe(child);
  pipe(parent);
  
  srand(time(NULL));
  
  if (fork() == 0) {
		close(parent[WRITE]);
		close(child[READ]);
		int get;
		read(parent[READ], &get, sizeof(get));
		printf("[parent] sending: [%d]\n", get);
		get *= 25; 
		write(child[WRITE], &get, sizeof(get));
  } 
  else {
    close(parent[READ]);
    close(child[WRITE]);
    int num = rand() % 100;
    write(parent[WRITE], &num, sizeof(num));
      	printf("[child] doing maths on: [%d]\n", num);
      	read(child[READ], &num, sizeof(num)); 
      	printf("[parent] received: [%d]\n", num);
  }
}
