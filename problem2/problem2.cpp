#include <algorithm>    // sort
#include <iostream>     // cout
#include <utility>      // pair
#include <vector>       // vector

using namespace std;

bool comparePairs(const pair<int, int>& one, const pair<int, int>& two) {
    if(one.first > two.first)
        return false;
    if(two.first > one.first)
        return true;

    return two.second > one.second;
}

int maxCards(vector<pair<int, int>>&& pairs, const int budget=2912) {
    sort(pairs.begin(), pairs.end(), comparePairs);

    int cards = 0;
    int gentime = 0;
    int overheadtime = 0;
    int totaltime = 0;
    for (int index{0}; index < pairs.size(); ++index) {
        gentime += pairs.at(index).second;
        overheadtime += pairs.at(index).first;
        totaltime = gentime + (overheadtime * index);
        if (totaltime > budget)
            break;
        ++cards;
    }
    return cards;

}

int main(void) {
    const vector<int> generation = {9, 10, 21, 20, 7, 11, 4, 15, 7, 7, 14, 5,
                                    20, 6, 29, 8, 11, 19, 18, 22, 29, 14, 27,
                                    17, 6, 22, 12, 18, 18, 30};
    const vector<int> overhead = {21, 16, 19, 26, 26, 7, 1, 8, 17, 14, 15, 25,
                                  20, 3, 24, 5, 28, 9, 2, 14, 9, 25, 15, 13, 15,
                                  9, 6, 20, 27, 22};

    if (generation.size() != overhead.size())
        return 1;

    vector<pair<int, int>> weightedCards;
    for (int index{0}; index < generation.size(); ++index)
        weightedCards.emplace_back(overhead.at(index), generation.at(index));

    cout << "Solution: " << maxCards(move(weightedCards)) << endl;

    return 0;
}
