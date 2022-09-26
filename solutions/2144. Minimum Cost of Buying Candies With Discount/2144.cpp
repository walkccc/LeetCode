class Solution {
 public:
  int minimumCost(vector<int>& cost) {
    int ans = 0;

    sort(begin(cost), end(cost),
         [](const int a, const int b) { return a > b; });

    for (int i = 0; i < cost.size(); ++i)
      if (i % 3 != 2)
        ans += cost[i];

    return ans;
  }
};
