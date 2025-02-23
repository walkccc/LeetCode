struct Bucket {
  int mn;
  int mx;
};

class Solution {
 public:
  int maximumGap(vector<int>& nums) {
    if (nums.size() < 2)
      return 0;

    const int mn = ranges::min(nums);
    const int mx = ranges::max(nums);
    if (mn == mx)
      return 0;

    const int gap = ceil((mx - mn) / (double)(nums.size() - 1));
    const int bucketSize = (mx - mn) / gap + 1;
    vector<Bucket> buckets(bucketSize, {INT_MAX, INT_MIN});

    for (const int num : nums) {
      const int i = (num - mn) / gap;
      buckets[i].mn = min(buckets[i].mn, num);
      buckets[i].mx = max(buckets[i].mx, num);
    }

    int ans = 0;
    int prevMax = mn;

    for (const Bucket& bucket : buckets) {
      if (bucket.mn == INT_MAX)
        continue;  // empty bucket
      ans = max(ans, bucket.mn - prevMax);
      prevMax = bucket.mx;
    }

    return ans;
  }
};
