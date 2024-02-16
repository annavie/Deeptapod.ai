#include "TextAnalyzer.h"

// Overall, the code is well-structured and organized, the application of STL containers is praiseworthy. 
// Start to use <regex> library as well. Well done!

int main() {
    // use try catch here to catch exceptions for better performance
    TextAnalyzer analyzer("input.txt", "database.txt");
    analyzer.generateJSON("data.json");

    return 0;
}
