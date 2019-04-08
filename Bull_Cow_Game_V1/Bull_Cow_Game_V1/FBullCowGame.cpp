/*
	Created by Artur Partyka 07.04.2019.
	Copyrights All rights reserved.
*/
#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { reset(); } // Constructor used to reset the game values once the game begins. 

int32 FBullCowGame::get_max_tries() const { return max_tries; }
int32 FBullCowGame::get_current_try() const { return current_tries; }
int32 FBullCowGame::get_hidden_word_length() const { return hidden_word.length(); }
bool FBullCowGame::is_game_won() const { return false; }

EGuessStatus FBullCowGame::check_guess_validity(FString guess) const
{
	FString _guess = guess;

	if (false) { // If the guess is not an isogram,
		// return an error code.
		return EGuessStatus::NOT_ISOGRAM;
	} else if (false) { // If the guess is not lowercase, 
		// return an error code.
		return EGuessStatus::NOT_LOWERCASE;
	} else if (_guess.length() != get_hidden_word_length()) { // If the guess has wrong length,
		// return an error.
		return EGuessStatus::WRONG_LENGTH;
	} else { // If the guess does not match any error codes
	 // proceed OK
		return EGuessStatus::OK; // TODO: Display actual error referring to the error codes. 
	}
}

void FBullCowGame::reset()
{
	current_tries = 1;
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";
	max_tries = MAX_TRIES;
	hidden_word = HIDDEN_WORD;
	
	return;
}
// Receives a valid guess, increments turn and returns count.
FBullCowCount FBullCowGame::SubmitGuess(FString guess)
{
	int32 word_length = hidden_word.length();
	FString _guess = guess;
	// Increment turn number.
	current_tries++;
	// setup a return variable.
	FBullCowCount BullCowCount;
	// loop through all letters in the guess.
	for (int32 i = 0; i < word_length; i++) {
		// compare letters against the hidden word.
		for (int32 j = 0; j < word_length; j++) {
			// If there's a match then
			if (_guess[j] == hidden_word[i]) { // Compare 'i' & 'j' as they will both have the same index.
				// If the letters are in the same place...
				if (i == j) {
					BullCowCount.bulls++; // Increment Bulls. 
				}
				else {
					BullCowCount.cows++; // Increment Cows
				}
			}
		}
	}
		
	return BullCowCount;
}

