class Solution {
 public:
  int minimumKeypresses(string s) {
    int ans = 0;
    vector<int> count(26);

    for (const char c : s)
      ++count[c - 'a'];

    sort(begin(count), end(count), greater<>());

    for (int i = 0; i < 26; ++i)
      ans += count[i] * (i / 9 + 1);

    return ans;
  }
};
