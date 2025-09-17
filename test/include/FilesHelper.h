#ifndef FILESHELPER_H
#define FILESHELPER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class FilesHelper {
public:
    static void clearFile(const string& fileName) {
        ofstream file(fileName, ios::trunc);
        file.close();
    }

    static void saveLine(const string& fileName, const string& line) {
        ofstream file(fileName, ios::app);
        file << line << endl;
        file.close();
    }

    static vector<string> readFile(const string& fileName) {
        vector<string> lines;
        ifstream file(fileName);
        string line;
        while (getline(file, line)) {
            if (!line.empty()) lines.push_back(line);
        }
        file.close();
        return lines;
    }
};

#endif
