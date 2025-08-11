class Solution {
 public:
  long long minEliminationTime(vector<int>& timeReq, int splitTime) {
    priority_queue<long, vector<long>, greater<>> minHeap{timeReq.begin(),
                                                          timeReq.end()};
    minHeap.pop();

    while (true) {
      const long bacterial = splitTime + minHeap.top();
      minHeap.pop();
      if (minHeap.empty())
        return bacterial;
      if (bacterial > minHeap.top()) {
        minHeap.pop();
        minHeap.push(bacterial);
      }
    }

    throw;
  }
};
