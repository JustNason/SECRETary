#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#include <iostream>
#include <random>

std::string GeneratePassword (int length) {
    std::string password = "";
  	for (int i = 0; i < length; i++) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distrib(0, 92);

		int randomValue = distrib(gen);

		password += characters[randomValue];
	}  
	return password;
}
	
#endif