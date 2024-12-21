class Solution {
 public:
  int maximumLengthSubstring(string s) {
    int ans = 0;
    vector<int> count(26);

    for (int l = 0, r = 0; r < s.length(); ++r) {
      ++count[s[r] - 'a'];
      while (count[s[r] - 'a'] > 2)
        --count[s[l++] - 'a'];
      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};
