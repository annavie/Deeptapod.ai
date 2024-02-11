#include "TextAnalyzer.h"

int main() {
    TextAnalyzer analyzer("input.txt", "database.txt");
    analyzer.generateJSON("data.json");

    return 0;
}