class FenwickTree {
 public:
  FenwickTree(int n) : vals(n + 1) {}

  void maximize(int i, int val) {
    while (i < vals.size()) {
      vals[i] = max(vals[i], val);
      i += lowbit(i);
    }
  }

  int get(int i) const {
    int res = 0;
    while (i > 0) {
      res = max(res, vals[i]);
      i -= lowbit(i);
    }
    return res;
  }

 private:
  vector<int> vals;

  static int lowbit(int i) {
    return i & -i;
  }
};

class Solution {
 public:
  // Same as 2907. Maximum Profitable Triplets With Increasing Prices I
  int maxProfit(vector<int>& prices, vector<int>& profits) {
    const int maxPrice = ranges::max(prices);
    int ans = -1;
    FenwickTree maxProfitTree1(maxPrice);
    FenwickTree maxProfitTree2(maxPrice);

    for (int i = 0; i < prices.size(); ++i) {
      const int price = prices[i];
      const int profit = profits[i];
      // max(proftis[i])
      const int maxProfit1 = maxProfitTree1.get(price - 1);
      // max(proftis[i]) + max(profits[j])
      const int maxProfit2 = maxProfitTree2.get(price - 1);
      maxProfitTree1.maximize(price, profit);
      if (maxProfit1 > 0)
        maxProfitTree2.maximize(price, profit + maxProfit1);
      if (maxProfit2 > 0)
        ans = max(ans, profit + maxProfit2);
    }

    return ans;
  }
};
