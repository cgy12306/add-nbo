#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>

uint32_t change(uint32_t n){
	return (n & 0xFF000000) >> 24 | (n & 0x00FF0000) >>8 | (n & 0x0000FF00) << 8 | (n & 0x000000FF) << 24;
}

int main(int argc, char *argv[]){
	
	FILE *fd1, *fd2;
	uint32_t buf1[9], buf2[9];
	uint32_t *p1 = reinterpret_cast<uint32_t*>(buf1);
	uint32_t *p2 = reinterpret_cast<uint32_t*>(buf2);
	uint32_t sum;

	fd1 = fopen(argv[1], "r");
	fd2 = fopen(argv[2], "r");

	fread(buf1, 1, 8, fd1);
	fread(buf2, 1, 8, fd2);

	uint32_t n1 = change(*p1);
	uint32_t n2 = change(*p2);

	printf("%d(%p) + %d(%p) = %d(%p) \n", n1, n1, n2, n2, n1+n2, n1+n2);

	fclose(fd1);
	fclose(fd2);
	return 0;
}
