#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
	int fd;
	char* myfifo = "/tmp/tmp_fifo";

	mkfifo(myfifo, 0666);

	char buf_1[80], buf_2[80];
	while (1) {

		fd = open(myfifo, O_WRONLY);

		fgets(buf_2, 80, stdin);

		write(fd, buf_2, strlen(buf_2) + 1);
		close(fd);

		fd = open(myfifo, O_RDONLY);

		read(fd, buf_1, sizeof(buf_1));
		printf("User second: %s\n", buf_1);

		close(fd);
	}

	return 0;
}
