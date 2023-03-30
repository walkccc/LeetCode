class Solution {
 public:
  long long numberOfSubstrings(string s) {
    long long ans = 0;
    vector<int> count(128);

    for (const char c : s) {
      ans += count[c] + 1;
      ++count[c];
    }

    return ans;
  }
};
