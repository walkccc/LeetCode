class Solution {
 public:
  int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
    constexpr int kMod = 1e9 + 7;
    int ans = 0;

    // max-heap
    priority_queue<vector<int>> buys;

    // min-heap
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
        sells;

    for (const auto& order : orders) {
      if (order[2] == 0)
        buys.push(order);
      else
        sells.push(order);
      while (!buys.empty() && !sells.empty() &&
             buys.top()[0] >= sells.top()[0]) {
        const int minAmount = min(buys.top()[1], sells.top()[1]);
        vector<int> buysTop = buys.top();
        buys.pop();
        buysTop[1] -= minAmount;
        if (buysTop[1] > 0)
          buys.push(buysTop);

        vector<int> sellsTop = sells.top();
        sells.pop();
        sellsTop[1] -= minAmount;
        if (sellsTop[1] > 0)
          sells.push(sellsTop);
      }
    }

    while (!buys.empty())
      ans = (ans + buys.top()[1]) % kMod, buys.pop();

    while (!sells.empty())
      ans = (ans + sells.top()[1]) % kMod, sells.pop();

    return ans;
  }
};
