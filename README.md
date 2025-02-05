# Hangman Game

Welcome to the Hangman game, a classic word guessing game implemented in C. The objective of the game is to guess a secret word by suggesting letters one at a time. If the guessed letter is in the word, it will be revealed; otherwise, you'll draw part of a stick figure. The game ends when the hangman is fully drawn or when all letters are correctly guessed.

## Features

- Randomly selects a word from a predefined list (`words.txt`).
- Allows players to suggest letters.
- Keeps track of incorrect guesses and draws the corresponding parts of the hangman.
- Indicates whether the player has won or lost at the end of the game.
- Option to add new words to the database after each game.

## How to Play

1. **Compile the Game**: Open your terminal and navigate to the directory containing the source files (`game.c` and `words.txt`). Compile the game using a C compiler, such as `gcc`.

    ```bash
    gcc -o hangman game.c
    ```

2. **Run the Game**: Execute the compiled program.

    ```bash
    ./hangman
    ```

3. **Follow the Prompts**:
   - The game will display the Hangman opening screen.
   - Guess letters by entering a single character at each turn.
   - You can add new words to the game's database after finishing a round.

4. **Exit**: The game will end once you either win or lose, and it will prompt you if you want to add a new word to the list.

## Files

- `game.c`: Contains the source code for the Hangman game.
- `words.txt`: A text file containing a list of words from which the secret word is randomly selected. The first line should contain an integer representing the number of words in the list, followed by the words themselves.

## Contributing

Feel free to contribute by adding new words to the `words.txt` file or by enhancing the game with additional features such as:

- Improved user interface.
- Multiplayer support.
- Difficulty levels.

## License

This project is open-source and available under the MIT License. Feel free to modify, distribute, and use it according to your needs.
