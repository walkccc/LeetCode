class Solution {
 public:
  int uniqueLetterString(string s) {
    const int n = s.length();
    int ans = 0;
    // lastSeen[c] := the index of the last time ('a' + i) appeared
    vector<int> lastSeen(26, -1);
    // prevSeen[c] := the previous index of the last time ('a' + i) appeared
    vector<int> prevLastSeen(26, -1);

    for (int i = 0; i < n; ++i) {
      const int c = s[i] - 'A';
      if (lastSeen[c] != -1)
        ans += (i - lastSeen[c]) * (lastSeen[c] - prevLastSeen[c]);
      prevLastSeen[c] = lastSeen[c];
      lastSeen[c] = i;
    }

    for (int c = 0; c < 26; ++c)
      ans += (n - lastSeen[c]) * (lastSeen[c] - prevLastSeen[c]);

    return ans;
  }
};
