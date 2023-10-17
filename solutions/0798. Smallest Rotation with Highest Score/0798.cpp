class Solution {
 public:
  int bestRotation(vector<int>& nums) {
    const int n = nums.size();
    // rotate[i] := how many points losing after rotating left i times
    vector<int> rotate(n);

    // Rotating i - nums[i] times makes nums[i] == its new index.
    // So, rotating i - nums[i] + 1 times will "start" to make nums[i] > its
    // index, Which is the starting index to lose point
    for (int i = 0; i < n; ++i)
      --rotate[(i - nums[i] + 1 + n) % n];

    // Each time we rotate, we make index 0 to index n - 1, so we get 1 point.
    for (int i = 1; i < n; ++i)
      rotate[i] += rotate[i - 1] + 1;

    return distance(rotate.begin(), ranges::max_element(rotate));
  }
};
