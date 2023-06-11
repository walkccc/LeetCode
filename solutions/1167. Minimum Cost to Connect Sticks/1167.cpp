class Solution {
 public:
  int connectSticks(vector<int>& sticks) {
    int ans = 0;
    priority_queue<int, vector<int>, greater<>> minHeap;

    for (const int stick : sticks)
      minHeap.push(stick);

    while (minHeap.size() > 1) {
      const int x = minHeap.top();
      minHeap.pop();
      const int y = minHeap.top();
      minHeap.pop();
      ans += x + y;
      minHeap.push(x + y);
    }

    return ans;
  }
};
