class Solution {
 public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    int ans = 0;
    int distinct = 0;
    vector<int> count(128);

    for (int l = 0, r = 0; r < s.length(); ++r) {
      if (++count[s[r]] == 1)
        ++distinct;
      while (distinct == k + 1)
        if (--count[s[l++]] == 0)
          --distinct;
      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};
