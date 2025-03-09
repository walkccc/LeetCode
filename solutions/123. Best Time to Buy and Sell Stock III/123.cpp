class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int sellTwo = 0;
    int holdTwo = INT_MIN;
    int sellOne = 0;
    int holdOne = INT_MIN;

    for (const int price : prices) {
      sellTwo = max(sellTwo, holdTwo + price);
      holdTwo = max(holdTwo, sellOne - price);
      sellOne = max(sellOne, holdOne + price);
      holdOne = max(holdOne, -price);
    }

    return sellTwo;
  }
};
