class Solution {
 public:
  int getMaximumConsecutive(vector<int>& coins) {
    int ans = 1;  // next value we want to make

    sort(coins.begin(), coins.end());

    for (const int coin : coins) {
      if (coin > ans)
        return ans;
      ans += coin;
    }

    return ans;
  }
};
