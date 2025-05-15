class Solution {
 public:
  int countQuadruples(const string& s1, const string& s2) {
    // To minimize j - a, the length of the substring should be 1. This is
    // because for substrings with a size greater than 1, a will decrease,
    // causing j - a to become larger.
    int ans = 0;
    int diff = INT_MAX;  // diff := j - a
    vector<int> firstJ(26, -1);
    vector<int> lastA(26, -1);

    for (int j = s1.length() - 1; j >= 0; --j)
      firstJ[s1[j] - 'a'] = j;

    for (int a = 0; a < s2.length(); ++a)
      lastA[s2[a] - 'a'] = a;

    for (int i = 0; i < 26; ++i) {
      if (firstJ[i] == -1 || lastA[i] == -1)
        continue;
      if (firstJ[i] - lastA[i] < diff) {
        diff = firstJ[i] - lastA[i];
        ans = 0;
      }
      if (firstJ[i] - lastA[i] == diff)
        ++ans;
    }

    return ans;
  }
};
