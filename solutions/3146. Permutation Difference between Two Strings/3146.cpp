class Solution {
 public:
  int findPermutationDifference(string s, string t) {
    int ans = 0;
    vector<int> indices(26);

    for (int i = 0; i < s.length(); ++i)
      indices[s[i] - 'a'] = i;

    for (int i = 0; i < t.length(); ++i)
      ans += abs(indices[t[i] - 'a'] - i);

    return ans;
  }
};
