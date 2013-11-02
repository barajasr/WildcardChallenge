#include <fstream>  // ifstream
#include <iostream> // cout
#include <vector>   // vector

using namespace std;

int factorial(int n) {
    if (n > 0){
        int result = 1;
        for (int i=2; i<= n; i++)
            result *= i;

        return result; 
    }else if (n == 0){
        return 1;
    }

    return -1;
}

int uniqueOrderings(const int goal=5, string&& filename="problem1input.txt") {
    ifstream file(filename);

    // Read file and sum horizontal permutations in one pass
    string line;
    vector<vector<char>> data;
    int solutions = 0;
    while(getline(file, line)) {
        vector<char> tmp;
        int spots = 0;
        for (auto card : line) {
            tmp.emplace_back(card);
            if (card == '*')
                spots += 1;
        }

        if (spots >= goal) {
            // number of permutations
            solutions += factorial(spots)/factorial(spots-goal);
        }

        data.emplace_back(move(tmp));
    }

    // vertical checking
    for (int col{0}; col < data.at(0).size(); ++col) {
        int spots = 0;
        for (int row{0}; row < data.size(); ++row) {
            if (data.at(row).at(col) == '*')
                spots += 1;
        }

        if (spots >= goal) {
            // number of permutations
            solutions += factorial(spots)/factorial(spots-goal);
        } 
    }

    return solutions;
}

int main(void) {
    cout << "Solution: " << uniqueOrderings() << endl;

    return 0;
}
