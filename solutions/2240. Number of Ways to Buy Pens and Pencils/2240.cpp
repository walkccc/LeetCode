class Solution {
 public:
  long long waysToBuyPensPencils(int total, int cost1, int cost2) {
    long long ans = 0;
    const int maxPen = total / cost1;

    for (int i = 0; i <= maxPen; ++i)
      ans += (total - i * cost1) / cost2 + 1;

    return ans;
  }
};
