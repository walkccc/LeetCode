class Solution {
 public:
  int earliestSecondToMarkIndices(vector<int>& nums,
                                  vector<int>& changeIndices) {
    int l = 0;
    int r = changeIndices.size() + 1;

    while (l < r) {
      const int m = (l + r) / 2;
      if (canMark(nums, changeIndices, m))
        r = m;
      else
        l = m + 1;
    }

    return l <= changeIndices.size() ? l : -1;
  }

 private:
  // Returns true if all indices of `nums` can be marked within `second`.
  bool canMark(const vector<int>& nums, const vector<int>& changeIndices,
               int second) {
    int numMarked = 0;
    int decrement = 0;
    // indexToLastSecond[i] := the last second to mark the index i
    vector<int> indexToLastSecond(nums.size(), -1);

    for (int i = 0; i < second; ++i)
      indexToLastSecond[changeIndices[i] - 1] = i;

    for (int i = 0; i < second; ++i) {
      const int index = changeIndices[i] - 1;  // Convert to 0-indexed.
      if (i == indexToLastSecond[index]) {
        // Reach the last occurrence of the number.
        // So, the current second will be used to mark the index.
        if (nums[index] > decrement)
          // The decrement is less than the number to be marked.
          return false;
        decrement -= nums[index];
        ++numMarked;
      } else {
        ++decrement;
      }
    }

    return numMarked == nums.size();
  }
};
