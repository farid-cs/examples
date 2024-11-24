#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define FILEPATH "sample.txt"

static char *
read_file(char *filepath)
{
	struct stat statbuf = {0};
	char *contents;
	FILE *file;

	assert(stat(filepath, &statbuf) != -1);
	assert((contents = malloc(statbuf.st_size+1)) != NULL);
	assert((file = fopen(filepath, "r")) != NULL);
	assert(fread(contents, 1, statbuf.st_size, file) == statbuf.st_size);
	contents[statbuf.st_size] = 0;
	return contents;
}

int
main(void)
{
	const char *str;

	str = read_file(FILEPATH);
	printf("-------------- %s ------------\n", FILEPATH);
	printf("%s\n", str);
	printf("--------------------------------\n");
	return 0;
}
