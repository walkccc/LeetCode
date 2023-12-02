class Solution {
 public:
  int addRungs(vector<int>& rungs, int dist) {
    int ans = 0;
    int prev = 0;

    for (const int rung : rungs) {
      ans += (rung - prev - 1) / dist;
      prev = rung;
    }

    return ans;
  }
};
