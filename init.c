#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <limits.h>

int init(char* file_path, char* flags) {
	// Format filepath if directory is specified using flag

	// Get filepath for .git directory to be created
	char git_dir_path[PATH_MAX];
	strncpy(git_dir_path, file_path, sizeof(git_dir_path));
	strcat(git_dir_path, "/.git");	
	printf("Git directory filepath: %s\n", git_dir_path);

	// Create .git directory under specified filepath
	int fd = mkdir(file_path, S_IRWXU);

	// Handle errors
	if (fd == -1) {
		if (errno == EACCES) {
			printf("Error: Write permissions denied for parent directory\n");
			return EXIT_FAILURE;
		} else if (errno == EEXIST) {
			printf("Error: .git directory already exsits in specified parent directory\n");
		} else if (errno == ENOSPC) {
			printf("Error: file system does not have sufficient space\n");
		} else if (errno == EROFS) {
			printf("Error: parent directory is read-only\n");
		} else {
			printf("Error: an unknown error occured");
		}

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
