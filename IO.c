#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define BUFFER_SIZE 701

int main() {

	int in_fd, out_fd;
	char buffer [BUFFER_SIZE];
	ssize_t readBytes, writeBytes;

	// OPEN System Call
	in_fd = open("sample.txt", O_RDONLY);

	if (in_fd == -1) {
		printf("Failed to open file\n");
	}
	
	else {
		printf("File opened with Read-Only option\n");
	}

	// CREAT System Call
	out_fd = creat("sample2.txt", S_IRWXU);
	
	if (out_fd == -1) {
		printf("Failed to create file\n");
	}
	
	else {
		printf("New file created\n");
	}
	
	// READ and WRITE System Call
	for (;;) {
		readBytes = read(in_fd, buffer, BUFFER_SIZE);
		if (readBytes <= 0) break;
		writeBytes = write(out_fd, buffer, BUFFER_SIZE);
		printf("Wrote %li bytes in new file\n", writeBytes);
		if (writeBytes <=0){
		 	return 1;
		};
	}
	
	if (readBytes < 0) return 2;
	else
		printf("Successfully copied text from one file to another\n");
	
	
	
	return 0;

}
