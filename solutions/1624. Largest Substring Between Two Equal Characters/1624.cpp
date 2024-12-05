class Solution {
 public:
  int maxLengthBetweenEqualCharacters(string s) {
    int ans = -1;
    vector<int> lastSeen(26, -1);

    for (int i = 0; i < s.length(); ++i) {
      const int c = s[i] - 'a';
      if (lastSeen[c] == -1)
        lastSeen[c] = i;
      else
        ans = max(ans, i - lastSeen[c] - 1);
    }

    return ans;
  }
};
