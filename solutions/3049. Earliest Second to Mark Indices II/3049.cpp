class Solution {
 public:
  int earliestSecondToMarkIndices(vector<int>& nums,
                                  vector<int>& changeIndices) {
    const long numsSum = accumulate(nums.begin(), nums.end(), 0L);
    // {the second: the index of nums can be zeroed at the current second}
    const unordered_map<int, int> secondToIndex =
        getSecondToIndex(nums, changeIndices);
    int l = 0;
    int r = changeIndices.size() + 1;

    while (l < r) {
      const int m = (l + r) / 2;
      if (canMark(nums, secondToIndex, m, numsSum))
        r = m;
      else
        l = m + 1;
    }

    return l <= changeIndices.size() ? l : -1;
  }

 private:
  // Returns true if all indices of `nums` can be marked within `maxSecond`.
  bool canMark(const vector<int>& nums,
               const unordered_map<int, int>& secondToIndex, int maxSecond,
               const long numsSum) {
    // Use a min-heap to greedily pop out the minimum number, which yields the
    // least saving.
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int marks = 0;

    for (int second = maxSecond - 1; second >= 0; --second) {
      if (const auto it = secondToIndex.find(second);
          it != secondToIndex.end()) {
        // The number mapped by the index is a candidate to be zeroed out.
        const int index = it->second;
        minHeap.push(nums[index]);
        if (marks == 0) {
          // Running out of marks, so need to pop out the minimum number.
          // So, the current second will be used to mark an index.
          minHeap.pop();
          ++marks;
        } else {
          // There're enough marks.
          // So, the current second will be used to zero out a number.
          --marks;
        }
      } else {
        // There's no candidate to be zeroed out.
        // So, the current second will be used to mark an index.
        ++marks;
      }
    }

    const int heapSize = minHeap.size();
    const long decrementAndMarkCost =
        numsSum - getHeapSum(minHeap) + (nums.size() - heapSize);
    const long zeroAndMarkCost = heapSize + heapSize;
    return decrementAndMarkCost + zeroAndMarkCost <= maxSecond;
  }

  long getHeapSum(priority_queue<int, vector<int>, greater<int>>& heap) {
    long heapSum = 0;
    while (!heap.empty())
      heapSum += heap.top(), heap.pop();
    return heapSum;
  }

  unordered_map<int, int> getSecondToIndex(const vector<int>& nums,
                                           const vector<int>& changeIndices) {
    // {the `index` of nums: the earliest second to zero out nums[index]}
    unordered_map<int, int> indexToFirstSecond;
    unordered_map<int, int> secondToIndex;
    for (int zeroIndexedSecond = 0; zeroIndexedSecond < changeIndices.size();
         ++zeroIndexedSecond) {
      // Convert to 0-indexed.
      const int index = changeIndices[zeroIndexedSecond] - 1;
      if (nums[index] > 0 && !indexToFirstSecond.contains(index))
        indexToFirstSecond[index] = zeroIndexedSecond;
    }
    for (const auto& [index, second] : indexToFirstSecond)
      secondToIndex[second] = index;
    return secondToIndex;
  }
};
