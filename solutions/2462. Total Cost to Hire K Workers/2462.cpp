class Solution {
 public:
  long long totalCost(vector<int>& costs, int k, int candidates) {
    long long ans = 0;
    int i = 0;
    int j = costs.size() - 1;
    priority_queue<int, vector<int>, greater<>> minHeapL;
    priority_queue<int, vector<int>, greater<>> minHeapR;

    for (int hired = 0; hired < k; ++hired) {
      while (minHeapL.size() < candidates && i <= j)
        minHeapL.push(costs[i++]);
      while (minHeapR.size() < candidates && i <= j)
        minHeapR.push(costs[j--]);
      if (minHeapL.empty())
        ans += minHeapR.top(), minHeapR.pop();
      else if (minHeapR.empty())
        ans += minHeapL.top(), minHeapL.pop();
      // Both `minHeapL` and `minHeapR` are not empty.
      else if (minHeapL.top() <= minHeapR.top())
        ans += minHeapL.top(), minHeapL.pop();
      else
        ans += minHeapR.top(), minHeapR.pop();
    }

    return ans;
  }
};
