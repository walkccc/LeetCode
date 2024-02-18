class Solution {
 public:
  bool canPermutePalindrome(string s) {
    unordered_set<char> seen;

    for (const char c : s)
      if (!seen.insert(c).second)
        seen.erase(c);

    return seen.size() <= 1;
  }
};
