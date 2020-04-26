#include <fstream>
#include <vector>
#include <stdexcept>
#include <string>

#include "include/utils.h"

using namespace std;

namespace utils {
  vector<string> getGaniLines(ifstream &file) {

    vector<string> lines;

    while (!file.eof()) {
      string line;
      getline(file, line);
      lines.push_back(line);
    }

    return lines;
  }

  ifstream openFile(string fileName) {
    ifstream file;

    file.open(fileName);

    if (file.is_open()) {
      return file;
    } else {
      throw runtime_error("File could not be opened");
    }
  }

  vector<string> split(const string &text, char sep) {
    vector<string> tokens;
    size_t start = 0, end = 0;
    while ((end = text.find(sep, start)) != string::npos) {
      if (end != start) {
        tokens.push_back(text.substr(start, end - start));
      }
      start = end + 1;
    }
    if (end != start) {
      tokens.push_back(text.substr(start));
    }
    return tokens;
  }

  string concatenateSpacedFileName(vector<string> &currentLine) {
    string fileName;
    for (int i = 0; i < currentLine.size(); i++) {
      if (i > 0) {
        fileName += " ";
      }
      fileName += currentLine[i];
    }
    return fileName;
  }
}
