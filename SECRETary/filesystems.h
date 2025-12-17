#ifndef FILESYSTEMS_H
#define FILESYSTEMS_H

#include <iostream>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <string>
#include <vector>

namespace fs = std::filesystem;

bool find_file(const fs::path& directory, const std::string& file_name) {
	// Use recursive_directory_iterator to go through all subdirectories
	for (const auto& entry : fs::recursive_directory_iterator(directory)) {
		if (entry.is_regular_file() && entry.path().filename() == file_name) {
			// std::cout << "Found file: " << entry.path() << std::endl;
			return true; // Stop after finding the first match
		}
	}
	return false;
	// std::cout << "File not found: " << file_name << std::endl;
}

std::string readFile(const std::string& file_name) {
	std::ifstream inputFile(file_name);
    std::string readFile = "";
	std::string line;
	while (std::getline(inputFile, line)) {
	// Process the line (e.g., print it to the console)
	// std::cout << line << std::endl;
	readFile += line;
    }
    return readFile;
}


std::vector<std::string> listFiles(const std::string& directoryPath) {
    std::vector<std::string> fileList;
    for (const auto& entry : fs::directory_iterator(directoryPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ".password") {
            // std::cout << entry.path().filename() << std::endl;
			fileList.push_back(entry.path().filename().string());
        }
    }
    return fileList;
}

#endif