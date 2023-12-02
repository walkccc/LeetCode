class Solution {
 public:
  int minIncrements(int n, vector<int>& cost) {
    int ans = 0;

    for (int i = n / 2 - 1; i >= 0; --i) {
      const int l = i * 2 + 1;
      const int r = i * 2 + 2;
      ans += abs(cost[l] - cost[r]);
      // Record the information in the parent from the children. So, there's
      // need to actually update the values in the children.
      cost[i] += max(cost[l], cost[r]);
    }

    return ans;
  }
};
