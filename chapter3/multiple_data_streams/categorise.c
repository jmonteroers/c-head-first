#include <stdio.h>
#include <string.h>

FILE* safe_open(char path[]) {
    FILE *in;
    if (!(in = fopen(path, "r"))) {
        fprintf(stderr, "ERROR: Input file not found.\n");
    }
    return in;
}

int main(int argc, char *argv[]) {
    char line[80];
    FILE *out_file;

    FILE *in = safe_open(argv[1]);
    // if there was an error in read, stop execution with error code
    if (!in) return 1;
    FILE *file1 = fopen(argv[3], "w");
    FILE * file2 = fopen(argv[5], "w");
    FILE *others_file = fopen(argv[argc-1], "w");

    while (fscanf(in, "%79[^\n]\n", line) == 1) {
        if (strstr(line, argv[2]))
            out_file = file1;
        else if (strstr(line, argv[4]))
            out_file = file2;
        else
            out_file = others_file;
        fprintf(out_file, "%s\n", line);
    }

    fclose(in);
    fclose(file1);
    fclose(file2);
    fclose(others_file);
    return 0;
}