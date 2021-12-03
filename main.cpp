#include <iostream>

int main() {
    char wordArray{};
    int attempts{8}; //number of guess to get the word right.
    std::string gameWord = "none"; //the word that the user needs to guess right
    srand(time(nullptr)); // Used to generate a random number to pick which word to use in the array of strings.
    std::string wordList[10] = {"VANUATU", "MAURITIUS", "CRICKET", "SPARKLEMUFFIN", "COATIMUNDI", "POTATOES", "TURKEY",
                                "FOOTBALL", "OCEAN", "MOUNTAIN"};
    int randomNumber = rand() % 10; // returns 1 - 10
    char userGuess = 'n';
    bool correctGuess = false;
    char pastGuess[9];
    bool playAgain = true;
    std::string again;

    pastGuess[0] = '\0';

    for (int i = 1; i < 8; i++) {
        pastGuess[i] = '-';
    }
    pastGuess[8] = '\0';

//the first thing I planned to do is to draw out the hangman to make the game look more realistic.
    while (playAgain == true) {
        std::cout << "WELCOME TO HANGMAN!!" << std::endl;
        std::cout << "If you are not familiar with the game which I highly doubt, the point of it is to ";
        std::cout << "guess the word!!" << std::endl;

        std::cout << " Hangman " << std::endl;
        std::cout << "-------------     " << std::endl;
        std::cout << "|           |     " << std::endl;
        std::cout << "|           O     " << std::endl;
        std::cout << "|           |     " << std::endl;
        std::cout << "|         / | \\  " << std::endl;
        std::cout << "|           |     " << std::endl;
        std::cout << "|         /   \\  " << std::endl;
        std::cout << "|        /     \\ " << std::endl;
        std::cout << "|                 " << std::endl;
        std::cout << "|                 " << std::endl;
        std::cout << "--------------------" << std::endl;
        std::cout << std::endl;
        std::cout << "Enter a random key and hit enter to start" << std::endl;
        std::cout << "Lets begin..." << std::endl;
        std::cin >> wordArray;

        //To help loop through the guess and the amount of attempt, a while loop is used to keep track of the tries and the count.

        gameWord = wordList[randomNumber];
        std::cout << gameWord << " ";
        // have to hide word from the player.
        std::string hiddenWord(gameWord.length(),
                               '*'); // replacing each letter of the word with the star so that the user does not see.


        while (attempts >= 0) {

            correctGuess = false; //resetting the bool so that the while loop keeps proper track of the guess.

            std::cout << "The word of the game is: " << std::endl;
            std::cout << std::endl;
            std::cout << hiddenWord;
            std::cout << std::endl;
            std::cout << "You have " << attempts << " attempts left." << std::endl;
            std::cout << "Enter a guess, please enter just a letter" << std::endl;

            if (pastGuess[0] ==
                '\0') { //making it so that if the past guess is incorrect we get to show what they have guessed
                std::cout << std::endl;
            } else {
                std::cout << "You guessed " << pastGuess << std::endl;
            }

            std::cout << std::endl;

            std::cin >> userGuess;
            userGuess = toupper(userGuess);

            for (int i = 0; i < hiddenWord.length(); i++) { //checking to see if the letter is in the word
                if (gameWord[i] == userGuess) { // if it is we have to set the word until the word is revealed.
                    hiddenWord[i] = userGuess;
                    std::cout << "Correct!! " << userGuess << " is in the word, keep going" << std::endl;
                    correctGuess = true; // the boolean is to keep track of the while loop to see if the user won or lost.

                }
            }

            if (gameWord == hiddenWord) {
                std::cout << std::endl;

                break;
            }
            if (correctGuess == false) {
                attempts--;
                std::cout << "SORRY the letter " << userGuess << " is incorrect. Try again. . . " << std::endl;
            } else {
                std::cout << "CONGRATULATION!! You WON!! The word is: " << gameWord << std::endl;
            }

            switch (attempts) {
                case 8: {

                    std::cout << " Hangman " << std::endl;
                    std::cout << "-------------     " << std::endl;
                    std::cout << "|           |     " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "--------------------" << std::endl;

                    break;
                }
                case 7: {
                    std::cout << " Hangman " << std::endl;
                    std::cout << "-------------     " << std::endl;
                    std::cout << "|           |     " << std::endl;
                    std::cout << "|           O     " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "--------------------" << std::endl;
                    if (correctGuess == false) {
                        pastGuess[0] = userGuess;
                    }

                    break;
                }
                case 6: {
                    std::cout << " Hangman " << std::endl;
                    std::cout << "-------------     " << std::endl;
                    std::cout << "|           |     " << std::endl;
                    std::cout << "|           O     " << std::endl;
                    std::cout << "|           |     " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "--------------------" << std::endl;
                    if (correctGuess == false) {
                        pastGuess[1] = userGuess;
                    }

                    break;
                }
                case 5: {
                    std::cout << " Hangman " << std::endl;
                    std::cout << "-------------     " << std::endl;
                    std::cout << "|           |     " << std::endl;
                    std::cout << "|           O     " << std::endl;
                    std::cout << "|           |     " << std::endl;
                    std::cout << "|           |     " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "--------------------" << std::endl;
                    if (correctGuess == false) {
                        pastGuess[2] = userGuess;
                    }

                    break;
                }
                case 4: {
                    std::cout << " Hangman " << std::endl;
                    std::cout << "-------------     " << std::endl;
                    std::cout << "|           |     " << std::endl;
                    std::cout << "|           O     " << std::endl;
                    std::cout << "|           |     " << std::endl;
                    std::cout << "|         / |     " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "--------------------" << std::endl;
                    if (correctGuess == false) {
                        pastGuess[3] = userGuess;
                    }

                    break;

                }
                case 3: {
                    std::cout << " Hangman " << std::endl;
                    std::cout << "-------------     " << std::endl;
                    std::cout << "|           |     " << std::endl;
                    std::cout << "|           O     " << std::endl;
                    std::cout << "|           |     " << std::endl;
                    std::cout << "|         / | \\  " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "--------------------" << std::endl;
                    if (correctGuess == false) {
                        pastGuess[4] = userGuess;
                    }

                    break;
                }
                case 2: {
                    std::cout << " Hangman " << std::endl;
                    std::cout << "-------------     " << std::endl;
                    std::cout << "|           |     " << std::endl;
                    std::cout << "|           O     " << std::endl;
                    std::cout << "|           |     " << std::endl;
                    std::cout << "|         / | \\  " << std::endl;
                    std::cout << "|           |     " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "--------------------" << std::endl;
                    if (correctGuess == false) {
                        pastGuess[5] = userGuess;
                    }

                    break;
                }
                case 1: {
                    std::cout << " Hangman " << std::endl;
                    std::cout << "-------------     " << std::endl;
                    std::cout << "|           |     " << std::endl;
                    std::cout << "|           O     " << std::endl;
                    std::cout << "|           |     " << std::endl;
                    std::cout << "|         / | \\  " << std::endl;
                    std::cout << "|           |     " << std::endl;
                    std::cout << "|         /       " << std::endl;
                    std::cout << "|        /        " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "--------------------" << std::endl;
                    if (correctGuess == false) {
                        pastGuess[6] = userGuess;
                    }

                    break;
                }
                case 0: {
                    std::cout << " Hangman " << std::endl;
                    std::cout << "-------------     " << std::endl;
                    std::cout << "|           |     " << std::endl;
                    std::cout << "|           O     " << std::endl;
                    std::cout << "|           |     " << std::endl;
                    std::cout << "|         / | \\  " << std::endl;
                    std::cout << "|           |     " << std::endl;
                    std::cout << "|         /   \\  " << std::endl;
                    std::cout << "|        /     \\ " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "|                 " << std::endl;
                    std::cout << "--------------------" << std::endl;
                    std::cout << std::endl;

                    std::cout << "GAME OVER!!" << std::endl;

                    attempts = -1;

                    break;
                }
                default:
                    std::cout << "Check code error";

            }
        }

        std::cout << "Would you like to play again?? Enter 'yes' or 'no'." << std::endl;
        std::cin >> again;
        if (again == "yes") {
            attempts = 8;
        }
        else {
            playAgain = false;
        }


    }

    return 0;
}
