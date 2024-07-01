class Bucket {
  public int min;
  public int max;
  public Bucket(int min, int max) {
    this.min = min;
    this.max = max;
  }
}

class Solution {
  public int maximumGap(int[] nums) {
    if (nums.length < 2)
      return 0;

    final int min = Arrays.stream(nums).min().getAsInt();
    final int max = Arrays.stream(nums).max().getAsInt();
    if (min == max)
      return 0;

    final int gap = (int) Math.ceil((double) (max - min) / (nums.length - 1));
    final int bucketsLength = (max - min) / gap + 1;
    Bucket[] buckets = new Bucket[bucketsLength];

    for (int i = 0; i < buckets.length; ++i)
      buckets[i] = new Bucket(Integer.MAX_VALUE, Integer.MIN_VALUE);

    for (final int num : nums) {
      final int i = (num - min) / gap;
      buckets[i].min = Math.min(buckets[i].min, num);
      buckets[i].max = Math.max(buckets[i].max, num);
    }

    int ans = 0;
    int prevMax = min;

    for (final Bucket bucket : buckets) {
      if (bucket.min == Integer.MAX_VALUE) // empty bucket
        continue;
      ans = Math.max(ans, bucket.min - prevMax);
      prevMax = bucket.max;
    }

    return ans;
  }
}
