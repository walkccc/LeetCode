class Solution {
 public:
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    int ans = 0;
    unordered_map<int, int> count;

    for (vector<int>& domino : dominoes) {
      int key = min(domino[0], domino[1]) * 10 + max(domino[0], domino[1]);
      ans += count[key];
      ++count[key];
    }

    return ans;
  }
};
