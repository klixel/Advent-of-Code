#include <algorithm>
#include <fstream>
#include <cstdint>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

pair<int64_t, int64_t> predict(vector<int64_t>& array) {
    if (all_of(array.begin(), array.end(), [](int64_t x){return x == 0;}))
        return {0, 0};
    vector<int64_t> diffs(array.size() - 1);
    for (size_t i = 0; i < array.size() - 1; i++)
        diffs[i] = array[i+1] - array[i];
    auto predictions = predict(diffs);
    return {array.front() - predictions.first, array.back() + predictions.second};
}

int main() {

#ifdef CMAKE
    ifstream fin("../2023/day09/input.txt");
    ofstream fout("../2023/day09/output.txt");
#else
    ifstream fin("input.txt");
    ofstream fout("output.txt");
#endif

    string line;
    int64_t result1 = 0, result2 = 0;

    while (getline(fin, line)) {
        stringstream stream(line);
        vector<int64_t> array;
        int64_t x;
        while (stream >> x) array.push_back(x);
        auto predictions = predict(array);
        result1 += predictions.second;
        result2 += predictions.first;
    }

    fout << "Part 1: " << result1 << endl;
    fout << "Part 2: " << result2 << endl;

    fin.close();
    fout.close();

    return 0;
}