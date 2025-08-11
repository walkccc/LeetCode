class Solution {
 public:
  int characterReplacement(string s, int k) {
    int maxCount = 0;
    vector<int> count(26);

    // l and r track the maximum window instead of the valid window.
    int l = 0;
    int r = 0;

    for (r = 0; r < s.length(); ++r) {
      maxCount = max(maxCount, ++count[s[r] - 'A']);
      if (maxCount + k < r - l + 1)
        --count[s[l++] - 'A'];
    }

    return r - l;
  }
};
