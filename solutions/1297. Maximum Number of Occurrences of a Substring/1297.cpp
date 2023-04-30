class Solution {
 public:
  int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
    // Greedily consider strings with `minSize`, so ignore `maxSize`.
    int ans = 0;
    int letters = 0;
    vector<int> count(26);
    unordered_map<string, int> substringCount;

    for (int l = 0, r = 0; r < s.length(); ++r) {
      if (++count[s[r] - 'a'] == 1)
        ++letters;
      while (letters > maxLetters || r - l + 1 > minSize)
        if (--count[s[l++] - 'a'] == 0)
          --letters;
      if (r - l + 1 == minSize)
        ans = max(ans, ++substringCount[s.substr(l, minSize)]);
    }

    return ans;
  }
};
