struct T {
  int i;
  int j;
  int num;  // nums[i][j]
};

class Solution {
 public:
  vector<int> smallestRange(vector<vector<int>>& nums) {
    auto compare = [&](const T& a, const T& b) { return a.num > b.num; };
    priority_queue<T, vector<T>, decltype(compare)> minHeap(compare);
    int mn = INT_MAX;
    int mx = INT_MIN;

    for (int i = 0; i < nums.size(); ++i) {
      const int num = nums[i][0];
      minHeap.emplace(i, 0, num);
      mn = min(mn, num);
      mx = max(mx, num);
    }

    int minRange = mn;
    int maxRange = mx;

    while (minHeap.size() == nums.size()) {
      const auto [i, j, _] = minHeap.top();
      minHeap.pop();
      if (j + 1 < nums[i].size()) {
        minHeap.emplace(i, j + 1, nums[i][j + 1]);
        mx = max(mx, nums[i][j + 1]);
        mn = minHeap.top().num;
        if (mx - mn < maxRange - minRange) {
          minRange = mn;
          maxRange = mx;
        }
      }
    }

    return {minRange, maxRange};
  }
};
