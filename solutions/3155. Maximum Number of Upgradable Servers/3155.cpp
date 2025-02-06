class Solution {
 public:
  vector<int> maxUpgrades(vector<int>& count, vector<int>& upgrade,
                          vector<int>& sell, vector<int>& money) {
    // If there's enough money, upgrade all servers; otherwise, optimize by
    // upgrading x servers. We have x * upgrade <= money + (count - x) * sell.
    // Therefore, x = (money + count * sell) / (sell + upgrade).
    vector<int> ans;
    for (int i = 0; i < count.size(); ++i)
      ans.push_back(min(
          count[i],
          static_cast<int>((money[i] + static_cast<long>(count[i]) * sell[i]) /
                           (sell[i] + upgrade[i]))));
    return ans;
  }
};
