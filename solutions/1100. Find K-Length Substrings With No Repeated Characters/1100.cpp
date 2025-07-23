class Solution {
 public:
  int numKLenSubstrNoRepeats(string s, int k) {
    int ans = 0;
    int unique = 0;
    vector<int> count(26);

    for (int i = 0; i < s.length(); ++i) {
      if (++count[s[i] - 'a'] == 1)
        ++unique;
      if (i >= k && --count[s[i - k] - 'a'] == 0)
        --unique;
      if (unique == k)
        ++ans;
    }

    return ans;
  }
};
