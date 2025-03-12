class Solution {
 public:
  int maxIceCream(vector<int>& costs, int coins) {
    ranges::sort(costs);

    for (int i = 0; i < costs.size(); ++i)
      if (coins >= costs[i])
        coins -= costs[i];
      else
        return i;

    return costs.size();
  }
};
