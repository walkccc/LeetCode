class Solution {
 public:
  int uniqueLetterString(string s) {
    int ans = 0;
    int count = 0;
    vector<int> lastCount(26);
    vector<int> lastSeen(26, -1);

    for (int i = 0; i < s.length(); ++i) {
      const int c = s[i] - 'A';
      const int currentCount = i - lastSeen[c];
      count = count - lastCount[c] + currentCount;
      lastCount[c] = currentCount;
      lastSeen[c] = i;
      ans += count;
    }

    return ans;
  }
};
