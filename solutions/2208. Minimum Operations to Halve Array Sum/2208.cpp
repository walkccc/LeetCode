class Solution {
 public:
  int halveArray(vector<int>& nums) {
    const double halfSum = accumulate(nums.begin(), nums.end(), 0.) / 2;
    int ans = 0;
    double runningSum = 0;
    priority_queue<double> maxHeap{nums.begin(), nums.end()};

    while (runningSum < halfSum) {
      const double maxValue = maxHeap.top() / 2;
      runningSum += maxValue, maxHeap.pop();
      maxHeap.push(maxValue);
      ++ans;
    }

    return ans;
  }
};
