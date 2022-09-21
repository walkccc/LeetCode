struct Bucket {
  int min;
  int max;
};

class Solution {
 public:
  int maximumGap(vector<int>& nums) {
    if (nums.size() < 2)
      return 0;

    const int mini = *min_element(begin(nums), end(nums));
    const int maxi = *max_element(begin(nums), end(nums));
    if (mini == maxi)
      return 0;

    const int gap = ceil((maxi - mini) / (double)(nums.size() - 1));
    const int bucketSize = (maxi - mini) / gap + 1;
    vector<Bucket> buckets(bucketSize, {INT_MAX, INT_MIN});

    for (const int num : nums) {
      const int i = (num - mini) / gap;
      buckets[i].min = min(buckets[i].min, num);
      buckets[i].max = max(buckets[i].max, num);
    }

    int ans = 0;
    int prevMax = mini;

    for (const Bucket& bucket : buckets) {
      if (bucket.min == INT_MAX)
        continue;  // empty bucket
      ans = max(ans, bucket.min - prevMax);
      prevMax = bucket.max;
    }

    return ans;
  }
};
