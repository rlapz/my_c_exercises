/* @author rLapz <arthurlapz@gmail.com>
 * @license MIT
 *
 * Simple program for split file into pieces
 *
 * NOTE: True 0, False = -1
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#include <sys/stat.h>

#define BUFFER_SIZE 4096


static int
split_by_number(char **argv);


static int
split_by_number(char **argv)
{
	int8_t is_success	= 0;
	char filename[255]	= {0};
	char buffer[BUFFER_SIZE] = {0};
	int byte_splitted	= 0;
	int fd_read		= 0;
	int fd_write		= 0;
	int split_to		= 0;
	size_t file_size	= 0;
	size_t write_size	= 0;
	ssize_t read_bytes	= 0;
	ssize_t written_bytes	= 0;
	struct stat file_stat;

	if (stat(argv[1], &file_stat) < 0) {
		perror(argv[1]);
		return -1;
	}

	split_to = atoi(argv[2]);
	file_size = (size_t)file_stat.st_size;
	/* tolerance 1 byte for prevent part file not fully written */
	byte_splitted = ((int)file_size / split_to) +1; 
	write_size = (size_t)(byte_splitted < BUFFER_SIZE ? byte_splitted : BUFFER_SIZE);

	if ((fd_read = open(argv[1], O_RDONLY)) < 0) {
		perror("Open file");
		return -1;
	}

	for (int iter = 1; iter <= split_to; iter++) {
		snprintf(filename, 254, "%s.part%d", argv[1], iter);
		if ((fd_write = open(filename, O_WRONLY|O_CREAT|O_TRUNC,
						S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)) < 0) {
			perror("Open file target");
			is_success = -1;
			break;
		}
		int tmp = byte_splitted;
		while (tmp > 0) {
			if ((read_bytes = read(fd_read, buffer, write_size)) < 0) {
				perror("Read file");
				is_success = -1;
				goto cleanup;
			}
			if (read_bytes > 0) {
				if ((written_bytes = write(fd_write, buffer, (size_t)read_bytes)) < 0) {
					perror("Write file");
					is_success = -1;
					goto cleanup;
				}
				tmp -= read_bytes;
			} else {
				break;
			}
		}
		memset(buffer, 0, sizeof(buffer));
		close(fd_write);
	}

cleanup:
	if (fd_read > 0)
		close(fd_read);
	if (fd_write > 0)
		close(fd_write);
	if (is_success < 0)
		return -1;

	return 0;
}

int
main(int argc, char *argv[])
{
	const char help[] = "Usage: \n"
		"\t%s [file_source] [split_num]\n"
		"Example: \n"
		"\t%s file.mp4 5\n";

	if (argc != 3) {
		fprintf(stderr, help, argv[0], argv[0]);
		return EXIT_FAILURE;
	}
	if (split_by_number(argv))
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}

