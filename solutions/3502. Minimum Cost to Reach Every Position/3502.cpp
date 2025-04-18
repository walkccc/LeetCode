class Solution {
 public:
  vector<int> minCosts(vector<int>& cost) {
    vector<int> ans;
    int minCost = INT_MAX;
    for (const int c : cost) {
      minCost = min(minCost, c);
      ans.push_back(minCost);
    }
    return ans;
  }
};
