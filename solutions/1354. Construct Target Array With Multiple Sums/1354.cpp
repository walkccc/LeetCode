class Solution {
 public:
  bool isPossible(vector<int>& target) {
    if (target.size() == 1)
      return target[0] == 1;

    long sum = accumulate(target.begin(), target.end(), 0L);
    priority_queue<int> maxHeap;

    for (const int num : target)
      maxHeap.push(num);

    while (maxHeap.top() > 1) {
      const long mx = maxHeap.top();
      maxHeap.pop();
      const long restSum = sum - mx;
      // Only occurs if n == 2.
      if (restSum == 1)
        return true;
      const long updated = mx % restSum;
      // updated == 0 (invalid) or didn't change.
      if (updated == 0 || updated == mx)
        return false;
      maxHeap.push(updated);
      sum = sum - mx + updated;
    }

    return true;
  }
};
