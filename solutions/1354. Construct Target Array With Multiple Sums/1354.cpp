class Solution {
 public:
  bool isPossible(vector<int>& target) {
    if (target.size() == 1)
      return target[0] == 1;

    long sum = accumulate(begin(target), end(target), 0L);
    priority_queue<int> maxHeap;

    for (const int num : target)
      maxHeap.push(num);

    while (maxHeap.top() > 1) {
      const long max = maxHeap.top();
      maxHeap.pop();
      const long restSum = sum - max;
      // Only occurs if n == 2.
      if (restSum == 1)
        return true;
      const long updated = max % restSum;
      // updated == 0 (invalid) or didn't change.
      if (updated == 0 || updated == max)
        return false;
      maxHeap.push(updated);
      sum = sum - max + updated;
    }

    return true;
  }
};
