class Solution {
 public:
  int getMaximumConsecutive(vector<int>& coins) {
    int ans = 1;  // the next value we want to make

    ranges::sort(coins);

    for (const int coin : coins) {
      if (coin > ans)
        return ans;
      ans += coin;
    }

    return ans;
  }
};
