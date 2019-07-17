#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
	int fd;

	char* myfifo = "/tmp/tmp_fifo";

	int ok = mkfifo(myfifo, 0666);
	if (ok < 0) {
		fprintf(stderr, "%s\n", "error with mkfifo;");
		return -1;
	}

	char buf_1[80], buf_2[80];
	while (1) {

		fd = open(myfifo, O_RDONLY);
		read(fd, buf_1, 80);

		printf("User first: %s\n", buf_1);
		close(fd);

		fd = open(myfifo, O_WRONLY);
		fgets(buf_2, 80, stdin);
		write(fd, buf_2, strlen(buf_2) + 1);
		close(fd);
	}
	return 0;
}
