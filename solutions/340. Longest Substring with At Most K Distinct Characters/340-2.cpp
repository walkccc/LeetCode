class Solution {
 public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    int ans = 0;
    map<int, char> lastSeen;          // {last index: letter}
    unordered_map<char, int> window;  // {letter: index}

    for (int l = 0, r = 0; r < s.length(); ++r) {
      const int inChar = s[r];
      if (const auto it = window.find(inChar); it != window.cend())
        lastSeen.erase(it->second);
      lastSeen[r] = inChar;
      window[inChar] = r;
      if (window.size() > k) {
        const auto [lastIndex, outChar] = *lastSeen.begin();
        lastSeen.erase(lastSeen.begin());
        window.erase(outChar);
        l = lastIndex + 1;
      }
      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};
