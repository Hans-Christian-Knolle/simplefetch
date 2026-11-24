#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "arguments.h"

int main(int argc, char *argv[]) {
    // Handle arguments
    if (argc == 2) {
        // --help (-h) is the only valid argument
        if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
            show_help_message();
            return EXIT_SUCCESS;
        }
    } else if (argc > 2) {
        fprintf(stderr, "Too many arguments!\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
