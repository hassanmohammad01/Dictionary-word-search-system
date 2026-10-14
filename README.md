# Dictionary / Word Search System

**Team Name:** WordWise Warriors  
**Project Type:** Data Structures and Algorithms (DSA)  
**Programming Language:** C

## About the Project

The Dictionary / Word Search System is a simple menu-driven C program that searches for a word in a stored collection and displays its meaning. It demonstrates how data can be organized and retrieved using basic data structures and searching techniques.

## Features

- **Search a word:** Finds a word and displays its meaning.
- **Add a word:** Stores a new word and its meaning during the current program run.
- **Display all words:** Lists all words currently stored in the dictionary.
- **Delete a word:** Removes a word from the current dictionary.
- **Case-insensitive search:** For example, `Computer` and `computer` are treated as the same word.
- **Input validation:** Handles empty entries, duplicate words, and invalid menu choices.

## Technologies Used

- **Programming Language:** C
- **Compiler:** GCC (or any standard C compiler)
- **Data Structures:** Array of structures
- **Searching Technique:** Linear Search
- **String Handling:** Standard C string and character functions (`string.h`, `ctype.h`)
- **Input/Output:** Standard input/output functions (`stdio.h`)
- **Development Environment:** Any C-compatible IDE or text editor, such as Code::Blocks, VS Code, or Dev-C++.

## Data Structures and Concepts Used

- **Structure (`struct`):** Each dictionary entry stores a word and its meaning together.
- **Array of structures:** Holds multiple dictionary entries.
- **Linear Search:** Checks dictionary entries one by one until a matching word is found.
- **String handling:** Uses C string functions to read and compare words.
- **Functions:** Divides the program into smaller, reusable operations.

## How It Works

1. The user selects an operation from the menu.
2. For a search, the user enters a word.
3. The program compares the entered word with stored words using linear search.
4. If a match is found, the corresponding meaning is displayed.
5. If no match is found, the program displays **Word Not Found**.

## Requirements

- A C compiler, such as GCC
- A terminal or command prompt

## How to Compile and Run

### Windows (GCC / MinGW)

```bash
gcc dictionary.c -o dictionary
dictionary.exe
```

### Linux / macOS

```bash
gcc dictionary.c -o dictionary
./dictionary
```

## Sample Output

```text
======================================
 DICTIONARY / WORD SEARCH SYSTEM
        WORDWISE WARRIORS
======================================

--------------- MENU ---------------
1. Search a word
2. Add a word
3. Display all words
4. Delete a word
0. Exit
-------------------------------------
Enter your choice: 1
Enter word to search: computer

Word    : computer
Meaning : An electronic device that processes and stores data.
```

## Limitations

- Words added or deleted are kept only while the program is running.
- The dictionary uses a fixed-size array, with a maximum capacity of 200 entries.
- Linear search checks entries one by one, so searching can take longer as the dictionary grows.

## Future Scope

- Save dictionary entries permanently in a file.
- Add synonyms, example sentences, and pronunciation.
- Support multiple languages.
- Add autocomplete and suggestions for misspelled words.
- Use binary search on sorted data or hashing for faster lookup.

## Note

This is an educational group project created to practise C programming, structures, arrays, string handling, and searching concepts.

GitHub link:
https://github.com/hassanmohammad01/Dictionary-word-search-system/new/main?filename=README.md

