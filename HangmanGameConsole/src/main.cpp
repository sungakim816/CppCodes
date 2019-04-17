/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.cc
 * Copyright (C) 2019 Kim S. Sunga <sungakim816@gmail.com>
	 * 
 * HangmanGame is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
	 * 
 * HangmanGame is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <string>
#include <cstdlib>

std::string toLowerWord(std::string word)
{
	for (unsigned int i = 0; i < word.length(); i++)
	{
		word[i] = tolower(word[i]);
	}
	return word;
}

std::string maskMysteryWord(std::string word)
{
	char characterMasked = '_';
	std::string maskedWord = "";
	for (unsigned int i = 0; i < word.length(); i++)
	{
		if (tolower(word[i]) >= 97 && tolower(word[i]) <= 122)
		{
			maskedWord += characterMasked;
		}
		else
		{
			maskedWord += word[i];
		}
	}
	return maskedWord;
}

int main(int argc, char *argv[])
{
	std::string inputSet = "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
	std::string mysteryWord, mysteryWordLower, userProgress, userGuess;
	unsigned short lifePoint = 5;
	bool isWinner = false;
	std::cout << "Enter a word: " << std::flush;
	std::getline(std::cin, mysteryWord);
	if (system("cls"))
		system("clear");
	mysteryWordLower = toLowerWord(mysteryWord);
	userProgress = maskMysteryWord(mysteryWord);
	std::cout << "Myster Word: " << userProgress << std::flush;
	std::cout << "\nPress Enter to continue....." << std::flush;
	std::cin.get();
	if (system("cls"))
		system("clear");
	while (lifePoint && !isWinner)
	{
		std::cout << inputSet << "\n\n"
				  << std::flush;
		std::cout << "Life Point: " << lifePoint << "\n\n"
				  << std::flush;
		std::cout << "Mystery Word: " << userProgress << "\n\n"
				  << std::flush;
		std::cout << "Guess: " << std::flush;
		std::getline(std::cin, userGuess);
		std::cout << "\n";
		if (inputSet.find(toupper(userGuess[0])) == std::string::npos || userGuess.length() != 1 || userGuess == " ")
		{
			// if userGuess is not on the possible inputs, do nothing...
		}
		else if (mysteryWordLower.find(tolower(userGuess[0])) == std::string::npos)
		{
			lifePoint--;
			std::cout << userGuess << " is not on the Mystery Word\n"
					  << std::flush;
			std::cout << "Press Enter to continue....." << std::flush;
			std::cin.get();
			inputSet.replace(inputSet.find(toupper(userGuess[0])), 1, "_");
		}
		else if (mysteryWordLower.find(tolower(userGuess[0])) != std::string::npos)
		{
			for (unsigned int i = 0; i < mysteryWord.length(); i++)
			{
				if (mysteryWordLower[i] == tolower(userGuess[0]))
				{
					userProgress[i] = mysteryWord[i];
				}
			}
			inputSet.replace(inputSet.find(toupper(userGuess[0])), 1, "_");
		}
		if (userProgress == mysteryWord)
			isWinner = true;
		if (system("cls"))
			system("clear");
	}

	if (isWinner)
		std::cout << "Congratulations!\nMystery word: " << userProgress << "\n"
				  << std::flush;
	else
		std::cout << "Sorry!\nMystery word: " << mysteryWord << "\n"
				  << std::flush;
	std::cout << "Press Enter to continue....." << std::flush;
	std::cin.get();
	return 0;
}
