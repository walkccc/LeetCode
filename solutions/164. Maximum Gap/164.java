class Bucket {
  public int mn;
  public int mx;
  public Bucket(int mn, int mx) {
    this.mn = mn;
    this.mx = mx;
  }
}

class Solution {
  public int maximumGap(int[] nums) {
    if (nums.length < 2)
      return 0;

    final int mn = Arrays.stream(nums).min().getAsInt();
    final int mx = Arrays.stream(nums).max().getAsInt();
    if (mn == mx)
      return 0;

    final int gap = (int) Math.ceil((double) (mx - mn) / (nums.length - 1));
    final int bucketsLength = (mx - mn) / gap + 1;
    Bucket[] buckets = new Bucket[bucketsLength];

    for (int i = 0; i < buckets.length; ++i)
      buckets[i] = new Bucket(Integer.MAX_VALUE, Integer.MIN_VALUE);

    for (final int num : nums) {
      final int i = (num - mn) / gap;
      buckets[i].mn = Math.min(buckets[i].mn, num);
      buckets[i].mx = Math.max(buckets[i].mx, num);
    }

    int ans = 0;
    int prevMax = mn;

    for (final Bucket bucket : buckets) {
      if (bucket.mn == Integer.MAX_VALUE) // empty bucket
        continue;
      ans = Math.max(ans, bucket.mn - prevMax);
      prevMax = bucket.mx;
    }

    return ans;
  }
}
