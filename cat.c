#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

int printStdin(int argc, char *argv[]) {
    int ch;

    while((ch = fgetc(stdin)) != EOF) {
       fprintf(stdout, "%c", ch);
    }

    return 0;
}

void cat(int fd) {
    struct stat sbuf;
    char *buffer;

    fstat(fd, &sbuf);

    buffer = mmap(NULL, sbuf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (buffer == MAP_FAILED) {
        printf("derp\n");
        exit(2);
    }

    fwrite(buffer, sizeof(char), sbuf.st_size, stdout);

    return;
}

int catFiles(int argc, char *argv[]) {
    int i;
    int fd;

    for (i = 1; i < argc; i++) {
        fd = open(argv[i], O_RDONLY);
        if (fd < 0) {
            fprintf(stderr, "%s: %s: No such file or directory\n", argv[0], argv[i]);
            exit(1);
        } else {
            cat(fd);
            close(fd);
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
