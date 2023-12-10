#include <fstream>
#include <string>
#include <utility>

using namespace std;

const string DIGITS[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int64_t part1(string& line) {
    int64_t first = 0, last = 0;

    for (int64_t i = 0; i < line.size(); i++) {
        if (isdigit(line[i])) {
            first = line[i] - '0';
            break;
        }
    }

    for (int64_t i = line.size() - 1; i >= 0; i--) {
        if (isdigit(line[i])) {
            last = line[i] - '0';
            break;
        }
    }

    return first * 10 + last;
}

int64_t part2(string& line) {
    int64_t first = 0, last = 0;

    for (int64_t i = 0; i < line.size(); i++) {
        if (isdigit(line[i])) {
            first = line[i] - '0';
            break;
        }

        bool found = false;
        for (int64_t j = 0; j < 9; j++) {
            if (line.substr(i, DIGITS[j].size()) == DIGITS[j]) {
                first = j + 1;
                found = true;
                break;
            }
        }

        if (found) break;
    }

    for (int64_t i = line.size() - 1; i >= 0; i--) {
        if (isdigit(line[i])) {
            last = line[i] - '0';
            break;
        }

        bool found = false;
        for (int64_t j = 0; j < 9; j++) {
            if (line.substr(i, DIGITS[j].size()) == DIGITS[j]) {
                last = j + 1;
                found = true;
                break;
            }
        }

        if (found) break;
    }

    return first * 10 + last;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    string line;
    int64_t result1 = 0, result2 = 0;

    while (getline(fin, line)) {
        if (line.empty()) continue;
        result1 += part1(line);
        result2 += part2(line);
    }

    fout << "Part 1: " << result1 << endl;
    fout << "Part 2: " << result2 << endl;

    fin.close();
    fout.close();

    return 0;
}