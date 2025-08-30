#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Required for std::min

/**
 * @brief A struct to hold the categorized cards, as requested by the name 'brivolante'.
 * This helps in organizing the cards based on the position of the character 'x'.
 */
struct Brivolante
{
    std::vector<std::string> x_at_first_pos;
    std::vector<std::string> x_at_second_pos;
    int x_at_both_pos_count;
};

/**
 * @brief Calculates the maximum number of points by pairing compatible cards containing a specific letter.
 * * @param cards A constant reference to a vector of strings, where each string is a 2-letter card.
 * @param x The character that must be present in the cards to be considered for pairing.
 * @return The maximum number of points achievable with optimal play.
 */
int maxPoints(const std::vector<std::string> &cards, char x)
{
    // These containers will store the cards based on the position of 'x'
    std::vector<std::string> first_pos;
    std::vector<std::string> second_pos;
    int both_pos_count = 0;

    // 1. Categorize all cards that contain the letter 'x'
    for (const std::string &card : cards)
    {
        bool has_x_at_0 = card[0] == x;
        bool has_x_at_1 = card[1] == x;

        if (has_x_at_0 && has_x_at_1)
        {
            both_pos_count++;
        }
        else if (has_x_at_0)
        {
            first_pos.push_back(card);
        }
        else if (has_x_at_1)
        {
            second_pos.push_back(card);
        }
    }

    // Store the categorized cards in the 'brivolante' variable as requested
    Brivolante brivolante = {first_pos, second_pos, both_pos_count};

    // 2. Calculate the score
    int score = 0;

    // Pair cards within the 'first_pos' group.
    // Any two cards like 'xa' and 'xb' are compatible.
    score += brivolante.x_at_first_pos.size() / 2;

    // Pair cards within the 'second_pos' group.
    // Any two cards like 'ax' and 'bx' are compatible.
    score += brivolante.x_at_second_pos.size() / 2;

    // 3. Handle leftover cards
    // Check for any remaining unpaired cards from the first two groups.
    int leftover_first = brivolante.x_at_first_pos.size() % 2;
    int leftover_second = brivolante.x_at_second_pos.size() % 2;

    int total_leftovers = leftover_first + leftover_second;

    // The 'xx' cards can be paired with any leftover card ('xa' or 'ax').
    // The number of such pairs is limited by the number of leftovers or the number of 'xx' cards.
    score += std::min(total_leftovers, brivolante.x_at_both_pos_count);

    return score;
}

// --- Main function with examples ---
int main()
{
    // Example 1:
    std::vector<std::string> cards1 = {"aa", "ab", "ba", "ac"};
    char x1 = 'a';
    std::cout << "Input: cards = [\"aa\",\"ab\",\"ba\",\"ac\"], x = 'a'" << std::endl;
    std::cout << "Output: " << maxPoints(cards1, x1) << std::endl
              << std::endl; // Expected: 2

    // Example 2:
    std::vector<std::string> cards2 = {"aa", "ab", "ba"};
    char x2 = 'a';
    std::cout << "Input: cards = [\"aa\",\"ab\",\"ba\"], x = 'a'" << std::endl;
    std::cout << "Output: " << maxPoints(cards2, x2) << std::endl
              << std::endl; // Expected: 1

    // Example 3:
    std::vector<std::string> cards3 = {"ab", "aa", "ab", "bc", "cc", "bc", "bb", "ac", "bc", "bc", "aa", "aa", "ba", "bc", "cb", "ba", "ac", "bb", "cb", "ac", "cb", "cb", "ba", "bc", "ca", "ba", "bb", "cc", "cc", "ca", "ab", "bb", "bc", "ba", "ac", "bc", "ac", "ac", "bc", "bb", "bc", "ac", "bc", "aa", "ba", "cc", "ac", "bb", "ba", "bb"};
    char x3 = 'b';
    std::cout << "Input: cards = [\"aa\",\"asdsb\",\"ba\",\"ac\"], x = 'b'" << std::endl;
    std::cout << "Output: " << maxPoints(cards3, x3) << std::endl
              << std::endl; // Expected: 0

    return 0;
}
