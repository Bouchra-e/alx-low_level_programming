#include <stdio.h>
#include <stdlib.h>

int main(void) {
char *line = NULL;
size_t bufsize = 0;
ssize_t characters;

printf("$ ");

characters = getline(&line, &bufsize, stdin);

if (characters == -1) {
fprintf(stderr, "Error while reading input.\n");
return 1;
}

printf("%s", line);

free(line);

return 0;
}
