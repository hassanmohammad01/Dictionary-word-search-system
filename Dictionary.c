/*
 * Dictionary / Word Search System
 * Team: WordWise Warriors
 * Language: C
 *
 * Features:
 *  - Search for a word and display its meaning
 *  - Add a new word
 *  - Display all stored words
 *  - Delete a word
 *  - Case-insensitive word searching
 *
 * DSA concepts: arrays of structures, linear search, string handling.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 200
#define WORD_LEN 50
#define MEANING_LEN 250

typedef struct {
    char word[WORD_LEN];
    char meaning[MEANING_LEN];
} DictionaryEntry;

DictionaryEntry dictionary[MAX_WORDS] = {
    {"algorithm", "A step-by-step procedure for solving a problem."},
    {"computer", "An electronic device that processes and stores data."},
    {"database", "An organized collection of related information."},
    {"program", "A set of instructions that tells a computer what to do."},
    {"software", "A collection of programs and related data."},
    {"variable", "A named memory location used to store a value."}
};

int wordCount = 6;

void trimNewline(char text[]) {
    text[strcspn(text, "\n")] = '\0';
}

void readLine(const char *prompt, char buffer[], int size) {
    printf("%s", prompt);
    if (fgets(buffer, size, stdin) != NULL) {
        trimNewline(buffer);
    } else {
        buffer[0] = '\0';
    }
}

int compareIgnoreCase(const char *a, const char *b) {
    while (*a && *b) {
        int ca = tolower((unsigned char)*a);
        int cb = tolower((unsigned char)*b);
        if (ca != cb) return ca - cb;
        a++;
        b++;
    }
    return tolower((unsigned char)*a) - tolower((unsigned char)*b);
}

int findWord(const char word[]) {
    int i;
    for (i = 0; i < wordCount; i++) {
        if (compareIgnoreCase(dictionary[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void searchWord(void) {
    char word[WORD_LEN];
    int index;

    readLine("Enter word to search: ", word, sizeof(word));
    if (word[0] == '\0') {
        printf("Please enter a word.\n");
        return;
    }

    index = findWord(word);
    if (index >= 0) {
        printf("\nWord    : %s\n", dictionary[index].word);
        printf("Meaning : %s\n", dictionary[index].meaning);
    } else {
        printf("\nWord Not Found. Try adding it to the dictionary.\n");
    }
}

void addWord(void) {
    char word[WORD_LEN];
    char meaning[MEANING_LEN];

    if (wordCount >= MAX_WORDS) {
        printf("Dictionary is full. Cannot add more words.\n");
        return;
    }

    readLine("Enter new word: ", word, sizeof(word));
    if (word[0] == '\0') {
        printf("Word cannot be empty.\n");
        return;
    }

    if (findWord(word) >= 0) {
        printf("This word already exists in the dictionary.\n");
        return;
    }

    readLine("Enter meaning: ", meaning, sizeof(meaning));
    if (meaning[0] == '\0') {
        printf("Meaning cannot be empty.\n");
        return;
    }

    snprintf(dictionary[wordCount].word, WORD_LEN, "%s", word);
    snprintf(dictionary[wordCount].meaning, MEANING_LEN, "%s", meaning);
    wordCount++;

    printf("Word added successfully.\n");
}

void displayAllWords(void) {
    int i;

    if (wordCount == 0) {
        printf("The dictionary is empty.\n");
        return;
    }

    printf("\n========== DICTIONARY WORDS ==========\n");
    for (i = 0; i < wordCount; i++) {
        printf("%d. %-20s : %s\n", i + 1,
               dictionary[i].word, dictionary[i].meaning);
    }
}

void deleteWord(void) {
    char word[WORD_LEN];
    int index, i;

    readLine("Enter word to delete: ", word, sizeof(word));
    index = findWord(word);

    if (index < 0) {
        printf("Word Not Found. Nothing was deleted.\n");
        return;
    }

    for (i = index; i < wordCount - 1; i++) {
        dictionary[i] = dictionary[i + 1];
    }
    wordCount--;

    printf("Word deleted successfully.\n");
}

int main(void) {
    char input[20];
    int choice;

    printf("======================================\n");
    printf(" DICTIONARY / WORD SEARCH SYSTEM\n");
    printf("        WORDWISE WARRIORS\n");
    printf("======================================\n");

    do {
        printf("\n--------------- MENU ---------------\n");
        printf("1. Search a word\n");
        printf("2. Add a word\n");
        printf("3. Display all words\n");
        printf("4. Delete a word\n");
        printf("0. Exit\n");
        printf("-------------------------------------\n");
        readLine("Enter your choice: ", input, sizeof(input));

        if (sscanf(input, "%d", &choice) != 1) {
            choice = -1;
        }

        switch (choice) {
            case 1: searchWord(); break;
            case 2: addWord(); break;
            case 3: displayAllWords(); break;
            case 4: deleteWord(); break;
            case 0: printf("Thank you for using the Dictionary System!\n"); break;
            default: printf("Invalid choice. Please enter 0 to 4.\n");
        }
    } while (choice != 0);

    return 0;
}
