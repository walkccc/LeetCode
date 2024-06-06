class Solution {
 public:
  long long countSubstrings(string s, char c) {
    const int freq = ranges::count(s, c);
    return 1L * freq * (freq + 1) / 2;
  }
};
