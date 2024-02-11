#ifndef TEXTANALYZER_H
#define TEXTANALYZER_H

#include <string>
#include <map>
#include <unordered_set>

class TextAnalyzer {
public:
    TextAnalyzer(const std::string& inputFile, const std::string& databaseFile);
    void generateJSON(const std::string& outputJsonFile);

private:
    std::unordered_set<std::string> wordDatabase;
    std::map<std::string, int> properNouns;
    std::string textData;
    void WordDatabase(const std::string& databaseFile);
    void processTextFile(const std::string& textFile);
};

#endif // TEXTANALYZER_H