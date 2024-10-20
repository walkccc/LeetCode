class Solution {
 public:
  bool canSortArray(vector<int>& nums) {
    // Divide the array into distinct segments where each segment is comprised
    // of consecutive elements sharing an equal number of set bits. Ensure that
    // for each segment, when moving from left to right, the maximum of a
    // preceding segment is less than the minimum of the following segment.
    int prevSetBits = 0;
    int prevMax = INT_MIN;  // the maximum of the previous segment
    int currMax = INT_MIN;  // the maximum of the current segment
    int currMin = INT_MAX;  // the minimum of the current segment

    for (const int num : nums) {
      const int setBits = __builtin_popcount(num);
      if (setBits != prevSetBits) {  // Start a new segment.
        if (prevMax > currMin)
          return false;
        prevSetBits = setBits;
        prevMax = currMax;
        currMax = num;
        currMin = num;
      } else {  // Continue with the current segment.
        currMax = max(currMax, num);
        currMin = min(currMin, num);
      }
    }

    return prevMax <= currMin;
  }
};
