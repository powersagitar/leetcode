#include <string>
#include <vector>
#include <unordered_set>

class Solution {
public:
  std::string longestCommonPrefix(const std::vector<std::string> &strs) {
      std::unordered_set<size_t> str_lens;
      for (const std::string &str : strs) {
        str_lens.insert(str.size());
      }

      const size_t min_len = *str_lens.begin();
      size_t len = 0;

      for (; len < min_len; ++len) {
          for (size_t str = 1; str < strs.size(); ++str) {
              if (strs[str][len] != strs[0][len]) {
                  return strs[0].substr(0, len);
              }
          }
      }

      return strs[0].substr(0, len);
  }
};

int main() {
    Solution s;
    s.longestCommonPrefix(std::vector<std::string> {"ab", "a"});
    return 0;
}
