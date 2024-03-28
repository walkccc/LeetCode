class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff,
                                     int valueDiff) {
    if (nums.empty() || indexDiff <= 0 || valueDiff < 0)
      return false;

    const long min = ranges::min(nums);
    const long diff = valueDiff + 1L;  // In case that `valueDiff` equals 0.
    // Use long because the corner case INT_MAX - (-1) will overflow.
    unordered_map<long, long> bucket;

    for (int i = 0; i < nums.size(); ++i) {
      const long num = nums[i];
      const long key = getKey(num, min, diff);
      if (bucket.count(key))  // the current bucket
        return true;
      if (bucket.count(key - 1) &&
          num - bucket[key - 1] < diff)  // the left adjacent bucket
        return true;
      if (bucket.count(key + 1) &&
          bucket[key + 1] - num < diff)  // the right adjacent bucket
        return true;
      bucket[key] = num;
      if (i >= indexDiff)
        bucket.erase(getKey(nums[i - indexDiff], min, diff));
    }

    return false;
  }

 private:
  int getKey(long num, long min, long diff) {
    return (num - min) / diff;
  }
};
