#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    char line[1024];
    char *args[64];

    while (1) {
        printf("2Shell> ");
        fflush(stdout);

        if (fgets(line, sizeof(line), stdin) == NULL) {
            printf("\n");
            break;
        }

        line[strcspn(line, "\n")] = '\0';

        int count = 0;
        char *word = strtok(line, " \t");
        while (word != NULL && count < 63) {
            args[count] = word;
            count++;
            word = strtok(NULL, " \t");
        }
        args[count] = NULL;

        if (count == 0) {
            continue;
        }

        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        pid_t pid = fork();

        if (pid == 0) {
            execvp(args[0], args);
            perror("2sh");
            _exit(1);
        } else if (pid > 0) {
            waitpid(pid, NULL, 0);
        } else {
            perror("fork");
        }
    }

    return 0;
}
