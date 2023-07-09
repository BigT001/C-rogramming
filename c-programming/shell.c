#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_TOKENS 64
#define TOKEN_DELIMITERS " \t\r\n\a"

int executeCommand(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Forking error
        perror("Error forking process");
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

int executeBuiltInCommand(char **args) {
    if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "Expected argument to \"cd\"\n");
        } else {
            if (chdir(args[1]) != 0) {
                perror("Error changing directory");
            }AiA`ZZ
        }
        return 1;
    } else if (strcmp(args[0], "exit") == 0) {
        return 0;
    }

    return -1; // Not a built-in command
}

void shellLoop() {
    char *input;
    char *tokens[MAX_TOKENS];
    int status;

    do {
        printf("> ");
        fflush(stdout);

        input = (char *)malloc(MAX_INPUT_LENGTH * sizeof(char));
        if (input == NULL) {
            perror("Error allocating memory");
            exit(EXIT_FAILURE);
        }

        if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL) {
            perror("Error reading input");
            exit(EXIT_FAILURE);
        }

        int numTokens = 0;
        tokens[numTokens] = strtok(input, TOKEN_DELIMITERS);
        while (tokens[numTokens] != NULL) {
            numTokens++;
            tokens[numTokens] = strtok(NULL, TOKEN_DELIMITERS);
        }

        if (numTokens > 0) {
            if ((status = executeBuiltInCommand(tokens)) == -1) {
                status = executeCommand(tokens);
            }
        }

        free(input);
    } while (status);

}

int main() {
    shellLoop();

    return EXIT_SUCCESS;
}

