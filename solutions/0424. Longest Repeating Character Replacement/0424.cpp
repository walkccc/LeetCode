class Solution {
 public:
  int characterReplacement(string s, int k) {
    int ans = 0;
    int maxCount = 0;
    vector<int> count(128);

    for (int l = 0, r = 0; r < s.length(); ++r) {
      maxCount = max(maxCount, ++count[s[r]]);
      while (maxCount + k < r - l + 1)
        --count[s[l++]];
      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};
