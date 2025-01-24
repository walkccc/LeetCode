class Solution {
 public:
  int minimumLength(string s) {
    int ans = 0;
    vector<int> count(26);

    for (const char c : s)
      ++count[c - 'a'];

    for (int i = 0; i < 26; ++i)
      if (count[i] > 0)
        ans += count[i] % 2 == 0 ? 2 : 1;

    return ans;
  }
};
