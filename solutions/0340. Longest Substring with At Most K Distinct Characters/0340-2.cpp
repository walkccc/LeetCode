class Solution {
 public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    int ans = 0;
    map<int, char> lastSeen;          // {last index: char}
    unordered_map<char, int> window;  // {char: index}

    for (int l = 0, r = 0; r < s.length(); ++r) {
      const int inChar = s[r];
      if (window.count(inChar))
        lastSeen.erase(window[inChar]);
      lastSeen[r] = inChar;
      window[inChar] = r;
      if (window.size() > k) {
        const auto [lastIndex, outChar] = *begin(lastSeen);
        lastSeen.erase(begin(lastSeen));
        window.erase(outChar);
        l = lastIndex + 1;
      }
      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};
