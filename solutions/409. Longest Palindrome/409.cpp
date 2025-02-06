class Solution {
 public:
  int longestPalindrome(string s) {
    int ans = 0;
    vector<int> count(128);

    for (const char c : s)
      ++count[c];

    for (const int freq : count)
      ans += freq % 2 == 0 ? freq : freq - 1;

    const bool hasOddCount =
        ranges::any_of(count, [](int c) { return c % 2 == 1; });
    return ans + hasOddCount;
  }
};
