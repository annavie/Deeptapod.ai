#include "TextAnalyzer.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip> //for std::setw
#include <sstream>
#include "json.hpp"

using json = nlohmann::json;

TextAnalyzer::TextAnalyzer(const std::string& inputFile, const std::string& databaseFile) {
    WordDatabase(databaseFile);
    processTextFile(inputFile);
}

void TextAnalyzer::generateJSON(const std::string& outputJsonFile) {
    json jsonData;
    jsonData["Text"] = textData;
    jsonData["ProperNouns"] = properNouns;

    std::ofstream dataJson(outputJsonFile);
    if (!dataJson.is_open()) {
        std::cerr << "Error opening JSON file" << std::endl;
        return;
    }
    dataJson << std::setw(4) << jsonData;
    dataJson.close();
}

void TextAnalyzer::WordDatabase(const std::string& databaseFile) {
    std::ifstream databaseTxt(databaseFile);
    if (!databaseTxt.is_open()) {
        std::cerr << "Error opening database file" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(databaseTxt, line)) {
        std::stringstream ss(line);
        std::string word;
        while (std::getline(ss, word, ',')) {
            word.erase(std::remove_if(word.begin(), word.end(), ::isspace), word.end());
            word.erase(std::remove(word.begin(), word.end(), '\"'), word.end());
            wordDatabase.insert(word);
        }
    }
    databaseTxt.close();
}

void TextAnalyzer::processTextFile(const std::string& textFile) {
    std::ifstream textFileTxt(textFile);
    if (!textFileTxt.is_open()) {
        std::cerr << "Error opening text file" << std::endl;
        return;
    }

    std::ofstream outputTxt("output.txt");
    if (!outputTxt.is_open()) {
        std::cerr << "Error opening output file" << std::endl;
        return;
    }

    std::string word;
    while (textFileTxt >> word) {
        if (std::isupper(word[0])) {
            if (!std::isalpha(word.back())) {
                word.pop_back();
            }
            if (wordDatabase.find(word) != wordDatabase.end()) {
                properNouns[word]++;
                word = "X";
            }
        }
        textData += word + " ";
        outputTxt << word << " ";
    }

    textFileTxt.close();
    outputTxt.close();
}
