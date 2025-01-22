class Solution {
 public:
  int countKConstraintSubstrings(string s, int k) {
    int ans = 0;
    vector<int> count(2);

    for (int l = 0, r = 0; r < s.length(); ++r) {
      ++count[s[r] - '0'];
      while (count[0] > k && count[1] > k)
        --count[s[l++] - '0'];
      ans += r - l + 1;
    }

    return ans;
  }
};
