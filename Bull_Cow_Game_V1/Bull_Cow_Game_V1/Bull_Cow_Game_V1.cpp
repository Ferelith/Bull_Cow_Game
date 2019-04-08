/*
	Created by Artur Partyka 07.04.2019.
	Copyrights All rights reserved. 
*/
// Bull_Cow_Game_V1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>

// Header files.
#include "FBullCowGame.h"


using FText = std::string; // Using Unreal Engine's naming convention for strings as user output
using int32 = int; // Using Unreal Engine's naming convention for integers

FBullCowGame BCGame; // Instantiate a new game.

void print_intro();
void play_game();
FText get_guess();
bool ask_to_play_again();

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
	FText response = "";

	std::cout << "Do you want to play the game again? (y = Yes / n = No): ";
	std::getline(std::cin, response); // Store the character entered by the player. 

	return (response[0] == 'y') || (response[0] == 'Y');
}
void play_game() {
	BCGame.reset();
	int32 max_tries = BCGame.get_max_tries(); // get the maxium number of tries.

	// Get the guess from the player & print back x5 times from the function.
	for (int32 guess_count = 1; guess_count <= max_tries; guess_count++) { // TODO: Change from 'for' to 'while' loop once we have a validated guess / tries.
		FText guess = get_guess(); // Variable to store the guess from the 'get_guess()' function.
		// Check if the entered guess is valid.
		EGuessStatus Status = BCGame.check_guess_validity(guess);
		// Submit valid guess to the game & receive counts.
		FBullCowCount BullCowCount = BCGame.SubmitGuess(guess);
		// Print number of Bulls & Cows.
		std::cout << "Bulls = " << BullCowCount.bulls << std::endl;
		std::cout << "Cows = " << BullCowCount.cows << std::endl;
		// Return the guess back to the player.
		std::cout << "Your guess was: " << guess << std::endl;
		std::cout << std::endl;
	}

	// TODO: Summarise game.

}

FText get_guess() { // TODO: Check for valid guesses.
	FText guess = "";
	int32 current_try = BCGame.get_current_try();

	// Get the guess from the player & store it in a variable.
	std::cout << "Try " << current_try <<  ". Enter your guess: ";
	std::getline(std::cin, guess);

	return guess;
}

void print_intro() {
	// Main introduction for the player once the game starts.
	std::cout << "Welcome to Bulls & Cows - The fun 'guess the word' game\n";
	std::cout << "Can you guess the " << BCGame.get_hidden_word_length() << " letter isogram?\n\n";

	return;
}