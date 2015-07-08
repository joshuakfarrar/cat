#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int printStdin(int argc, char *argv[]) {
    int ch;

    while((ch = fgetc(stdin)) != EOF) {
       fprintf(stdout, "%c", ch);
    }

    return 0;
}

int getFileLength(FILE *fp) {
    int length;

    fseek(fp, 0L, SEEK_END);
    length = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    return length;
}

int catFiles(int argc, char *argv[]) {
    int i;
    FILE *fp;
    int length;
    char *buffer;

    for (i = 1; i < argc; i++) {
        fp = fopen(argv[i], "r");
        if (fp == NULL) {
            fprintf(stderr, "%s: %s: No such file or directory\n", argv[0], argv[i]);
            exit(1);
        } else {
            length = getFileLength(fp);
            buffer = malloc(sizeof(char) * (length + 1));
            fread(buffer, sizeof(char), length, fp);
            fprintf(stdout, "%s", buffer);
            fclose(fp);
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return printStdin(argc, argv);
    } else {
        return catFiles(argc, argv);
    }
}
