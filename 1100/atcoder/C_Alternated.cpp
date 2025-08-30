#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    int score(std::vector<std::string>& cards, char x) {
        std::unordered_map<char, int> rankCounts;
        for (const auto& card : cards) {
            if (card[1] == x) {
                rankCounts[card[0]]++;
            }
        }
        int totalPairs = 0;
        for (const auto& pair : rankCounts) {
            int count = pair.second;
            totalPairs += count / 2;
        }
        return totalPairs;
    }
};

int main() {
    Solution sol;
    
    std::vector<std::string> cards1 = {"aa","ab","ba","ac"};
    char x1 = 'a';
    std::cout << sol.score(cards1, x1) << std::endl;

    std::vector<std::string> cards2 = {"aa","ab","ba"};
    char x2 = 'a';
    std::cout << sol.score(cards2, x2) << std::endl;

    std::vector<std::string> cards3 = {"aa","ab","ba","ac"};
    char x3 = 'b';
    std::cout << sol.score(cards3, x3) << std::endl;

    return 0;
}
