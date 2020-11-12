#include "init.h"

#include <stdlib.h>
// For I/O operations
#include <stdio.h>
// For comparing command line arguments
#include <string.h>
// For retreiving current file path
#include <unistd.h>
// For PATH_MAX
#include <limits.h>

// For using command line flags
//#include <ctype.h>

int main(int argc, char** argv) {
	if(argc == 1) {
		// Display menu if insufficient command line arguments provided
		printf("usage: git [--version] [--help] [-C <path>] [-c <name>=<value>]\n");
          	printf("           [--exec-path[=<path>]] [--html-path] [--man-path] [--info-path]\n");
          	printf("           [-p | --paginate | -P | --no-pager] [--no-replace-objects] [--bare]\n");
          	printf("           [--git-dir=<path>] [--work-tree=<path>] [--namespace=<name>]\n");
          	printf("           <command> [<args>]\n\n");

		return EXIT_SUCCESS;
	}

	// Add flag handling

	if (!strcmp("init", argv[1])) {
		// Initialise a new git repository
		char cur_path[PATH_MAX];

		if (getcwd(cur_path, sizeof(cur_path)) != NULL) {
			printf("Current Directory: %s\n", cur_path);
			int status = init(cur_path, argv[1]);
			if (status == EXIT_SUCCESS) {
				printf("New git repository initialised\n");
			}
		} else {
			printf("Error: unable to retreive current filepath");
			return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;
}
