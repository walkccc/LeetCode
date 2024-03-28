class Solution {
 public:
  long long countSubstrings(string s, char c) {
    const int freq = ranges::count(s, c);
    return static_cast<long long>(freq) * (freq + 1) / 2;
  }
};
