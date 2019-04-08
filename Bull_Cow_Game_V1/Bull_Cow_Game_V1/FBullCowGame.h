/*
	Created by Artur Partyka 07.04.2019.
	Copyrights All rights reserved.
*/
#include <string>
#pragma once

using FString = std::string; // Using Unreal Engine's naming convention for strings 
using int32 = int; // Using Unreal Engine's naming convention for integers

struct FBullCowCount { // Struct used to return a pair of values.
	int32 bulls = 0;
	int32 cows = 0;
};

enum class EGuessStatus { // Possible statuses to output for the inputted guesses.
	OK,
	NOT_ISOGRAM,
	WRONG_LENGTH,
	NOT_LOWERCASE
};

class FBullCowGame {
public:
	FBullCowGame(); // Constructor.

	int32 get_max_tries() const;
	int32 get_current_try() const;
	int32 get_hidden_word_length() const;
	bool is_game_won() const;
	EGuessStatus check_guess_validity(FString) const;
	void reset();
	FBullCowCount SubmitGuess(FString); // Counts Bulls & Cows and increases the number of remaining tries assuming valid guess.
private:
	// See constructor for initialisation. 
	int32 current_tries;
	int32 max_tries;
	FString hidden_word;
};

