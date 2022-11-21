struct T {
  int i;
  int j;
  int num;  // nums[i][j]
  T(int i, int j, int num) : i(i), j(j), num(num) {}
};

class Solution {
 public:
  vector<int> smallestRange(vector<vector<int>>& nums) {
    auto compare = [&](const T& a, const T& b) { return a.num > b.num; };
    priority_queue<T, vector<T>, decltype(compare)> minHeap(compare);
    int mini = INT_MAX;
    int maxi = INT_MIN;

    for (int i = 0; i < nums.size(); ++i) {
      const int num = nums[i][0];
      minHeap.emplace(i, 0, num);
      mini = min(mini, num);
      maxi = max(maxi, num);
    }

    int minRange = mini;
    int maxRange = maxi;

    while (minHeap.size() == nums.size()) {
      const auto [i, j, _] = minHeap.top();
      minHeap.pop();
      if (j + 1 < nums[i].size()) {
        minHeap.emplace(i, j + 1, nums[i][j + 1]);
        maxi = max(maxi, nums[i][j + 1]);
        mini = minHeap.top().num;
        if (maxi - mini < maxRange - minRange) {
          minRange = mini;
          maxRange = maxi;
        }
      }
    }

    return {minRange, maxRange};
  }
};
