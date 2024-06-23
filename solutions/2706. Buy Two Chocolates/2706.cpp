class Solution {
 public:
  int buyChoco(vector<int>& prices, int money) {
    int min1 = INT_MAX;
    int min2 = INT_MAX;

    for (const int price : prices)
      if (price <= min1) {
        min2 = min1;
        min1 = price;
      } else if (price < min2) {
        min2 = price;
      }

    const int minCost = min1 + min2;
    return minCost > money ? money : money - minCost;
  }
};
