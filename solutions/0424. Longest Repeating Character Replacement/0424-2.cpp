class Solution {
 public:
  int characterReplacement(string s, int k) {
    int ans = 0;
    int maxCount = 0;
    vector<int> count(128);

    // l and r track max window instead of valid window.
    int l = 0;
    int r = 0;

    for (r = 0; r < s.length(); ++r) {
      maxCount = max(maxCount, ++count[s[r]]);
      if (maxCount + k < r - l + 1)
        --count[s[l++]];
    }

    return r - l;
  }
};
