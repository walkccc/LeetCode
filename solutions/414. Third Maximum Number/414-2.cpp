class Solution {
 public:
  int thirdMax(vector<int>& nums) {
    priority_queue<int, vector<int>, greater<>> minHeap;
    unordered_set<int> seen;

    for (const int num : nums)
      if (!seen.contains(num)) {
        seen.insert(num);
        minHeap.push(num);
        if (minHeap.size() > 3)
          minHeap.pop();
      }

    if (minHeap.size() == 2)
      minHeap.pop();

    return minHeap.top();
  }
};
