class Solution {
 public:
  vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    vector<int> ans;
    unordered_map<int, vector<int>> numToAdjs;

    for (const auto& pair : adjacentPairs) {
      numToAdjs[pair[0]].push_back(pair[1]);
      numToAdjs[pair[1]].push_back(pair[0]);
    }

    for (const auto& [num, adjs] : numToAdjs)
      if (adjs.size() == 1) {
        ans.push_back(num);
        ans.push_back(adjs[0]);
        break;
      }

    while (ans.size() < adjacentPairs.size() + 1) {
      const int tail = ans.back();
      const int prev = ans[ans.size() - 2];
      const vector<int>& adjs = numToAdjs[tail];
      if (adjs[0] == prev)
        ans.push_back(adjs[1]);
      else
        ans.push_back(adjs[0]);
    }

    return ans;
  }
};
