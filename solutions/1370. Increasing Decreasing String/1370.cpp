class Solution {
 public:
  string sortString(string s) {
    string ans;
    vector<int> count(26);

    for (const char c : s)
      ++count[c - 'a'];

    while (ans.length() < s.size()) {
      for (int i = 0; i < 26; ++i) {
        if (count[i] == 0)
          continue;
        ans += 'a' + i;
        --count[i];
      }
      for (int i = 25; i >= 0; --i) {
        if (count[i] == 0)
          continue;
        ans += 'a' + i;
        --count[i];
      }
    }

    return ans;
  }
};
