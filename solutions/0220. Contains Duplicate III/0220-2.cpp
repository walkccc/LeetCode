class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if (nums.empty() || k <= 0 || t < 0)
      return false;

    const long min = *min_element(begin(nums), end(nums));
    const long diff = t + 1L;  // in case of t = 0
    // use long because corner case INT_MAX - (-1) will overflow
    unordered_map<long, long> bucket;

    for (int i = 0; i < nums.size(); ++i) {
      const long num = nums[i];
      const long key = getKey(num, min, diff);
      if (bucket.count(key))  // current bucket
        return true;
      if (bucket.count(key - 1) &&
          num - bucket[key - 1] < diff)  // left adjacent bucket
        return true;
      if (bucket.count(key + 1) &&
          bucket[key + 1] - num < diff)  // right adjacent bucket
        return true;
      bucket[key] = num;
      if (i >= k)
        bucket.erase(getKey(nums[i - k], min, diff));
    }

    return false;
  }

 private:
  int getKey(long num, long min, long diff) {
    return (num - min) / diff;
  }
};
