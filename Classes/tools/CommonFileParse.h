#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <sstream>


void split(const std::string& s, char delim, std::vector<std::string>& elems) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

std::vector < std::vector<std::string>> parse_tsv(const char* filepath) {
    std::ifstream infile(filepath);
    std::string line;
    std::vector < std::vector<std::string>> lines;

    while (std::getline(infile, line))
    {
        std::vector<std::string> row_values;
        split(line, '\t', row_values);
        lines.push_back(row_values);
    }

    infile.close();

    return lines;
}