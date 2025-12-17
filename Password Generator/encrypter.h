#ifndef ENCRYPTER_H
#define ENCRYPTER_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <random>

char characters[94] = {
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
	'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
	'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
	'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '!', '@', '#',
	'$', '%', '^', '&', '*', '(', ')', '_', '-', '+', '=', '{', '}',
	'[', ']', '\\', '|', ':', ';', '"', '<', '>', ',', '.', '?', '/',
	'`', '~', ' '
};

int lookupCharacter(char character) {
	int characterIndex;

	for (int i = 0; i < 93; i++) {
		if (characters[i] == character) {
			return i;
		}
	}

	return -1;
}

std::string generateKey(int keyLength) {
	std::string key = "";
	for (int i = 0; i < keyLength; i++) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distrib(0, 9);

		int randomValue = distrib(gen);

//		std::cout << std::to_string(randomValue) << '\n';

		key += std::to_string(randomValue);
	}
	return key;
}

std::string EncryptString(std::string string, std::string key) {
	std::string encryptedString = "";
	int length = string.length();

	int i2 = 0;

	for (int i = 0; i < length; i++) {

		int charIndex = lookupCharacter(string.at(i));
		//std::cout << charIndex;

		if (i2 == key.length()) {
			i2 = 0;
		}
		char keyNumChar = key[i2];
		int keyNum = keyNumChar - '0';

		int newCharIndex = (charIndex + keyNum);

		if (newCharIndex > 93) {
			newCharIndex = newCharIndex - 93;
		}

		encryptedString += characters[newCharIndex];

		i2++;
	}

	return encryptedString;
}

std::string DecryptString(std::string string, std::string key) {
	std::string decryptedString = "";
	int length = string.length();
	int i2 = 0;

	for (int i = 0; i < length; i++) {
		int charIndex = lookupCharacter(string.at(i));
		//	std::cout << '\n' << "charinx: " << charIndex;
		if (i2 == key.length()) {
			i2 = 0;
		}
		char keyNumChar = key[i2];
		int keyNum = keyNumChar - '0';
		//	std::cout << '\n' << "keynum: " << keyNum;

		int newCharIndex = charIndex - keyNum;

		if (newCharIndex < 0) {
			newCharIndex = 93 + newCharIndex;
		}

		decryptedString += characters[newCharIndex];
		i2++;
	}

	return decryptedString;
}

#endif