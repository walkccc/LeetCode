class Solution {
 public:
  int minimumDeviation(vector<int>& nums) {
    int ans = INT_MAX;
    int mn = INT_MAX;
    priority_queue<int> maxHeap;

    for (const int num : nums) {
      const int evenNum = num % 2 == 0 ? num : num * 2;
      mn = min(mn, evenNum);
      maxHeap.push(evenNum);
    }

    while (maxHeap.top() % 2 == 0) {
      const int mx = maxHeap.top();
      maxHeap.pop();
      ans = min(ans, mx - mn);
      mn = min(mn, mx / 2);
      maxHeap.push(mx / 2);
    }

    return min(ans, maxHeap.top() - mn);
  }
};
