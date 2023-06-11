class Solution {
 public:
  int getMaximumConsecutive(vector<int>& coins) {
    int ans = 1;  // next value we want to make

    sort(begin(coins), end(coins));

    for (const int coin : coins) {
      if (coin > ans)
        return ans;
      ans += coin;
    }

    return ans;
  }
};
