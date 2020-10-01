class Solution {
 public:
  int maxArea(vector<int>& height) {
    int ans = 0;
    int l = 0;
    int r = height.size() - 1;

    while (l < r) {
      const int h = min(height[l], height[r]);
      ans = max(ans, (r - l) * h);
      while (height[l] <= h && l < r) ++l;
      while (height[r] <= h && l < r) --r;
    }

    return ans;
  }
};