// http://lotabout.me/2015/write-a-C-interpreter-1/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int token;			// current token
char *src, *old_src; 	// pointer to source code string
int poolsize;			// default size of text/data/stack
int line;				// line number

void next() {
	token = *src++; // increment the value pointed by src
	return;
}

void expression(int level) {

}

void program() {
	next();
	while (token > 0) {
		printf("token is: %c\n", token);
		next();
	}
}

int eval() {
	return 0;
}

int main(int argc, char **argv) {
	int i, fd;

	argc--;
	argv++;

	poolsize = 256 * 1024; // arbitrary size
	line = 1;

	if((fd = open(*argv, 0)) < 0) {
		printf("could not open(%s)\n", *argv);
		return -1;
	}
	printf("%d\n",fd);

	if(!(src = old_src = malloc(poolsize))) {
		printf("could not malloc (%d) for source area\n", poolsize);
		return -1;
	}
	printf("%d\n", *src);

	if((i = read(fd, src, poolsize-1)) <= 0) {
		printf("read() return %d\n", i);
		return -1;
	}
	printf("%d\n", i);

	src[i] = 0; // add EOF character
	close(fd);

	program();
	return eval();
}