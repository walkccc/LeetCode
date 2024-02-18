class Solution {
 public:
  int minimumDeviation(vector<int>& nums) {
    int ans = INT_MAX;
    int mini = INT_MAX;
    priority_queue<int> maxHeap;

    for (const int num : nums) {
      const int evenNum = num % 2 == 0 ? num : num * 2;
      mini = min(mini, evenNum);
      maxHeap.push(evenNum);
    }

    while (maxHeap.top() % 2 == 0) {
      const int maxi = maxHeap.top();
      maxHeap.pop();
      ans = min(ans, maxi - mini);
      mini = min(mini, maxi / 2);
      maxHeap.push(maxi / 2);
    }

    return min(ans, maxHeap.top() - mini);
  }
};
