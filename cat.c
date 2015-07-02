#include <stdio.h>
#include <unistd.h>

int catFiles(int argc, char * argv[]) {
    int i;
    FILE * fp;
    int ch;

    for (i = 1; i < argc; i++) {
        fp = fopen(argv[i], "r");
        if (fp == NULL) {
            fprintf(stderr, "%s: %s: No such file or directory\n", argv[0], argv[i]);
        } else {
            while((ch = fgetc(fp)) != EOF) {
                fprintf(stdout, "%c", ch);
            }
            fclose(fp);
        }
    }

    return 0;
}

int main(int argc, char * argv[]) {
    if (argc <= 1) {
        int ch;
        while((ch = fgetc(stdin)) != EOF) {
            fprintf(stdout, "%c", ch);
        }
        return 0;
    } else {
        return catFiles(argc, argv);
    }
}
