class Solution {
 public:
  long long numberOfSubstrings(string s) {
    long long ans = 0;
    vector<int> count(26);

    for (const char c : s)
      ans += ++count[c - 'a'];

    return ans;
  }
};
