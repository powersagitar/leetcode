#include <cstddef>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int longestPalindrome(string s) {
    unordered_map<char, size_t> frequencies;
    for (const char c : s) {
      ++frequencies[c];
    }

    size_t length = 0;

    for (auto it = frequencies.begin(); it != frequencies.end(); ++it) {
      while (it->second > 1) {
        length += 2;
        it->second -= 2;
      }
    }

    for (auto it = frequencies.cbegin(); it != frequencies.cend(); ++it) {
      if (it->second == 1) {
        ++length;
        break;
      }
    }

    return length;
  }
};
