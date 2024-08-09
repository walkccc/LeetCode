class Solution {
 public:
  int minBuildTime(vector<int>& blocks, int split) {
    priority_queue<int, vector<int>, greater<>> minHeap;

    for (const int block : blocks)
      minHeap.push(block);

    while (minHeap.size() > 1) {
      minHeap.pop();                // the minimum
      const int x = minHeap.top();  // the second minimum
      minHeap.pop();
      minHeap.push(x + split);
    }

    return minHeap.top();
  }
};
