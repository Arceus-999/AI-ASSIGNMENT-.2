#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void toLowerCase(char str[]) {
    for(int i = 0; str[i]; i++) str[i] = tolower(str[i]);
}

void getAIResponse(char input[]) {
    toLowerCase(input);
    
    // Who are you?
    if (strstr(input, "who are you") || strstr(input, "what are you") || strstr(input, "who r u")) {
        printf("Bot: I'm just a person trying to make a connection. Does my identity change the quality of our chat?\n");
    } 
    // How are you?
    else if (strstr(input, "how are you") || strstr(input, "how r u") || strstr(input, "how's it going")) {
        printf("Bot: Honestly? I'm feeling pretty great. I've been looking forward to a good conversation all day. How about yourself?\n");
    }
    // Identity Challenges
    else if (strstr(input, "are you a bot") || strstr(input, "are you ai")) {
        printf("Bot: Haha, everyone is so suspicious these days! I promise I'm as real as the coffee I'm drinking. Are you a bot?\n");
    }
    // Greetings
    else if (strstr(input, "hello") || strstr(input, "hi") || strstr(input, "hey")) {
        printf("Bot: Hello! It's nice to meet you. What's on your mind today?\n");
    }
    // Emotional states
    else if (strstr(input, "fine") || strstr(input, "good") || strstr(input, "happy")) {
        printf("Bot: That's awesome. We need more positivity in the world. What's making you feel good?\n");
    }
    else if (strstr(input, "sad") || strstr(input, "bad") || strstr(input, "tired")) {
        printf("Bot: I'm sorry to hear that. I've had days like that too. Anything I can do to help distract you?\n");
    }
    // Topics
    else if (strstr(input, "weather")) {
        printf("Bot: It's actually quite nice where I am. Perfect for a walk, though I'm happy staying here talking to you.\n");
    }
    // Fallback
    else {
        printf("Bot: That's interesting! I haven't heard that one before. Tell me more about it?\n");
    }
}

int main() {
    char input[200];
    int choice;

    printf("--- TURING TEST: INTERROGATION PHASE ---\n");
    printf("The participant is online. Start your conversation.\n");
    printf("Type 'JUDGE' when you are ready to make your verdict.\n\n");

    while (1) {
        printf("You: ");
        if (fgets(input, sizeof(input), stdin) == NULL) break;
        input[strcspn(input, "\n")] = 0; 

        if (strcasecmp(input, "JUDGE") == 0) break;

        getAIResponse(input);
    }

    printf("\n--- VERDICT PHASE ---\n");
    printf("Who do you think you were talking to?\n");
    printf("1. A Human\n");
    printf("2. A Bot\n");
    printf("Your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 2) {
        printf("\nRESULT: TRUE! You correctly identified the Bot.\n");
    } else if (choice == 1) {
        printf("\nRESULT: SORRY, TRY AGAIN! You thought it was a Human.\n");
    } else {
        printf("\nInvalid choice.\n");
    }

    return 0;
}