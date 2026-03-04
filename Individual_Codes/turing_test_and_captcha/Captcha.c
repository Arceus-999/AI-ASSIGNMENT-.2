#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generateCaptcha(char captcha[], int len) {
    char charset[] = "0123456789"
                     "abcdefghijklmnopqrstuvwxyz"
                     "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int charsetSize = strlen(charset);

    for (int i = 0; i < len; i++) {
        captcha[i] = charset[rand() % charsetSize];
    }
    captcha[len] = '\0';
}

int main() {
    char captcha[7];
    char userInput[10];
    int attempts = 0;
    const int maxAttempts = 3;

    srand(time(0));

    printf("--- CAPTCHA VERIFICATION ---\n");

    while (attempts < maxAttempts) {
        generateCaptcha(captcha, 6);

        printf("\nCAPTCHA: %s\n", captcha);
        printf("Enter the characters above: ");
        scanf("%s", userInput);

        if (strcmp(captcha, userInput) == 0) {
            printf("\nVERIFICATION SUCCESSFUL!\n");
            printf("ACCESS GRANTED. YOU ARE LIKELY A HUMAN.\n");
            return 0;
        } else {
            attempts++;
            printf("\nINCORRECT. Attempts remaining: %d\n", maxAttempts - attempts);
        }
    }

    printf("\nACCESS DENIED: Too many failed attempts.\n");
    return 0;
}