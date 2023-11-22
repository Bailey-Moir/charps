#include "fileutils.h"
#include <fstream>
#include <iostream>

using namespace Charps;
using namespace std;

string FileUtils::readFile(const char* filePath) {
    string content;
    ifstream fileStream(filePath, ios::in);

    if (!fileStream.is_open()) {
        cerr << "Could not read file " << filePath << ". File does not exist." << endl;
        return "";
    }

    string line = "";
    while (!fileStream.eof()) {
        getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();
    return content;
}