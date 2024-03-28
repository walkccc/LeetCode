class Solution {
 public:
  int makePrefSumNonNegative(vector<int>& nums) {
    int ans = 0;
    long long prefix = 0;
    priority_queue<int, vector<int>, greater<>> minHeap;

    for (const int num : nums) {
      prefix += num;
      if (num < 0)
        minHeap.push(num);
      while (prefix < 0) {
        prefix -= minHeap.top(), minHeap.pop();
        ++ans;
      }
    }

    return ans;
  }
};
