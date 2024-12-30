#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    for (const string_view str : strs) {
      if (str.length() == 0) {
        return "";
      }

      Push(str);
    }

    string prefix;
    const TrieNode *trie_node = &trie_;

    while (trie_node->children.size() == 1) {
      const auto it = trie_node->children.cbegin();
      const char c = it->first;
      const TrieNode *next_node = &it->second;

      prefix += c;

      if (trie_node->is_end) {
        break;
      }

      trie_node = next_node;
    }

    return prefix;
  }

private:
  struct TrieNode {
    bool is_end;
    unordered_map<char, TrieNode> children;
  };

  void Push(const string_view str) {
    TrieNode *trie_node = &trie_;

    for (size_t i = 0; i < str.length(); ++i) {
      const char c = str[i];

      if (!trie_node->children.contains(c)) {
        trie_node->children.insert({c, {.is_end = false, .children{}}});
      }

      if (i == str.length() - 1) {
        trie_node->is_end = true;
      }

      trie_node = &trie_node->children[c];
    }
  }

  TrieNode trie_;
};
