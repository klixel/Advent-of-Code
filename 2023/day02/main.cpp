#include <fstream>
#include <regex>
#include <string>

using namespace std;

const regex color(R"((\d+) (red|green|blue))");

bool part1(string& s) {
    for (sregex_iterator it(s.begin(), s.end(), color), end; it != end; it++) {
        switch (it->str(2)[0]) {
            case 'r': {
                if (stoull(it->str(1)) > 12) return false;
                break;
            }

            case 'g': {
                if (stoull(it->str(1)) > 13) return false;
                break;
            }

            case 'b': {
                if (stoull(it->str(1)) > 14) return false;
                break;
            }
        }
    }

    return true;
}

uint64_t part2(string& s) {
    uint64_t red = 0, green = 0, blue = 0;
    for (sregex_iterator it(s.begin(), s.end(), color), end; it != end; it++) {
        switch (it->str(2)[0]) {
            case 'r': {
                red = max(red, stoull(it->str(1)));
                break;
            }

            case 'g': {
                green = max(green, stoull(it->str(1)));
                break;
            }

            case 'b': {
                blue = max(blue, stoull(it->str(1)));
                break;
            }
        }
    }

    return red * green * blue;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    string line;
    uint64_t result1 = 0, result2 = 0;
    uint64_t i = 0;

    while (getline(fin, line)) {
        if (line.empty()) continue;
        ++i;
        if (part1(line)) result1 += i;
        result2 += part2(line);
    }

    fout << "Part 1: " << result1 << endl;
    fout << "Part 2: " << result2 << endl;

    fin.close();
    fout.close();

    return 0;
}