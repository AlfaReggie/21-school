#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    srand(time(NULL) * atoi(argv[1]));
    for (int i = 2; i < argc; i++) {
        generateFiles(argv[i]);
    }
    return 0;
}

void generateFiles(char *fileName) {
    FILE *file = fopen(fileName, "w");
    if (!strstr(fileName, "rand")) {
        generateRand(file);
    }
}

void generateRand(FILE *file) {
    int n = rand() % 254 + 1;
    if (rand() % 2) {
        generateLines(file);
        generateSpaces(file);
    }
}
