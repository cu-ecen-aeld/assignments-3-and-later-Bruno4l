#include <stdio.h>
#include <syslog.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){

	openlog(NULL, 0, LOG_USER);

	if(argc < 3){
		syslog(LOG_ERR, "Missing arguments: writer path/to/file.txt \"string to write\" ");
		printf("Missing arguments: writer path/to/file.txt \"string to write\" \n");
		return 1;
	}

	int fd = open(argv[1], O_CREAT|O_WRONLY, 0644);
	if(fd == -1){
		syslog(LOG_ERR, "Failed to open file!");
		printf("Failed to open file!\n");
		return 1;
	}

	ssize_t bytes_wr = write(fd, argv[2], strlen(argv[2]));
	if(bytes_wr == -1){
		syslog(LOG_ERR, "Failde to write file!");
		printf("Failed to write file!\n");
		close(fd);
		return 1;
	}

	close(fd);

	syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);
	printf("Writing %s to %s\n", argv[2], argv[1]);

	return 0;
}
