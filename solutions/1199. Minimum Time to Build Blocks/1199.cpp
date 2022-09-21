class Solution {
 public:
  int minBuildTime(vector<int>& blocks, int split) {
    priority_queue<int, vector<int>, greater<>> minHeap;

    for (const int block : blocks)
      minHeap.push(block);

    while (minHeap.size() > 1) {
      minHeap.pop();                // smallest
      const int x = minHeap.top();  // 2nd smallest
      minHeap.pop();
      minHeap.push(x + split);
    }

    return minHeap.top();
  }
};
