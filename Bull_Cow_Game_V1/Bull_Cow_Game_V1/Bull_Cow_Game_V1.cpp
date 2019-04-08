// Bull_Cow_Game_V1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

// Header files.
#include "main.h"

int main() {
	// Print introduction for the game.
	print_intro();

	bool bplayer_wants_to_play = false;
	do {
		// Play the game.
		play_game();
		// Ask the player to play the game again.
		bplayer_wants_to_play = ask_to_play_again();
		std::cout << std::endl; // End line
	} while (bplayer_wants_to_play);

	return 0; // Exit the application.
}

bool ask_to_play_again() {
	std::string response = "";

	std::cout << "Do you want to play the game again? (y = Yes / n = No): ";
	std::getline(std::cin, response); // Store the character entered by the player. 

	return (response[0] == 'y') || (response[0] == 'Y');
}
void play_game() {
	constexpr int MAX_GUESS_COUNT = 5; // Maximum number of guesses available.

	// Get the guess from the player & print back x5 times from the function.
	for (int guess_count = 1; guess_count <= MAX_GUESS_COUNT; guess_count++) {
		std::string guess = get_guess(); // Variable to store the guess from the get_guess() function.
		// Return the guess back to the player.
		std::cout << "Your guess was: " << guess << std::endl;
		std::cout << std::endl;
	}
}

std::string get_guess() {
	std::string guess = "";

	// Get the guess from the player & store it in a variable.
	std::cout << "Enter your guess: ";
	std::getline(std::cin, guess);

	return guess;
}

void print_intro() {
	constexpr int WORD_LENGTH = 9; // Constant for a word length of the isogram.

	// Main introduction for the player once the game starts.
	std::cout << "Welcome to Bulls & Cows - The fun 'guess the word' game\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram?\n\n";

	return;
}