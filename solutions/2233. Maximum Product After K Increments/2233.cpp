class Solution {
 public:
  int maximumProduct(vector<int>& nums, int k) {
    constexpr int kMod = 1'000'000'007;
    long ans = 1;
    priority_queue<int, vector<int>, greater<>> minHeap;

    for (const int num : nums)
      minHeap.push(num);

    for (int i = 0; i < k; ++i) {
      const int minNum = minHeap.top();
      minHeap.pop();
      minHeap.push(minNum + 1);
    }

    while (!minHeap.empty()) {
      ans *= minHeap.top(), minHeap.pop();
      ans %= kMod;
    }

    return ans;
  }
};
