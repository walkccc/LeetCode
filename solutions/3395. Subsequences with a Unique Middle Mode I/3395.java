class Solution {
  public int subsequencesWithMiddleMode(int[] nums) {
    int n = nums.length;
    long ans = 0;
    Map<Integer, Integer> left = new HashMap<>();
    Map<Integer, Integer> right = new HashMap<>();

    for (int i = 0; i < 2; ++i)
      left.merge(nums[i], 1, Integer::sum);

    for (int i = 2; i < n; ++i)
      right.merge(nums[i], 1, Integer::sum);

    for (int i = 2; i < n - 2; ++i) {
      final int num = nums[i];
      if (right.merge(num, -1, Integer::sum) == 0)
        right.remove(num);

      final int leftCount = left.getOrDefault(num, 0);
      final int rightCount = right.getOrDefault(num, 0);
      final int leftOther = i - leftCount;
      final int rightOther = n - 1 - i - rightCount;

      // count[mode] = 5 -- [a a] a [a a]
      ans = (ans + nC2(leftCount) * nC2(rightCount)) % kMod;

      // count[mode] = 4 -- [a a] a [a ?]
      ans = (ans + nC2(leftCount) * rightCount % kMod * rightOther % kMod) % kMod;

      // count[mode] = 4 -- [a ?] a [a a]
      ans = (ans + leftCount * leftOther % kMod * nC2(rightCount) % kMod) % kMod;

      // count[mode] = 3 -- [a a] a [? ?]
      ans = (ans + nC2(leftCount) * nC2(rightOther) % kMod) % kMod;

      // count[mode] = 3 -- [? ?] a [a a]
      ans = (ans + nC2(leftOther) * nC2(rightCount) % kMod) % kMod;

      // count[mode] = 3 -- [a ?] a [a ?]
      ans = (ans + leftCount * leftOther % kMod * rightCount % kMod * rightOther % kMod) % kMod;

      // count[mode] = 2 -- [a ?] a [? ?]
      ans = (ans + leftCount * calc(num, leftOther, rightOther, left, right) % kMod) % kMod;

      // count[mode] = 2 -- [? ?] a [a ?]
      ans = (ans + rightCount * calc(num, rightOther, leftOther, right, left) % kMod) % kMod;

      // Update left map
      left.merge(num, 1, Integer::sum);
    }

    return (int) (ans % kMod);
  }

  private static final int kMod = 1_000_000_007;

  // Returns C(n, 2)
  private long nC2(long n) {
    return n * (n - 1) / 2 % kMod;
  }

  // Returns the count of subsequences that have 'a' as the middle number, where
  // invalid subsequences are excluded
  private long calc(int a, long other1, long other2, Map<Integer, Integer> count1,
                    Map<Integer, Integer> count2) {
    // [a ?] a [? ?]
    long res = other1 * nC2(other2) % kMod;

    for (Map.Entry<Integer, Integer> entry : count1.entrySet()) {
      final int b = entry.getKey();
      final long b1 = entry.getValue();
      if (b == a)
        continue;
      final long b2 = count2.getOrDefault(b, 0);
      // Exclude triples -- [a b] a [b b]
      res = (res - b1 * nC2(b2) % kMod + kMod) % kMod;
      // Exclude doubles -- [a b] a [b ?]
      res = (res - b1 * b2 % kMod * (other2 - b2) % kMod + kMod) % kMod;
    }

    for (Map.Entry<Integer, Integer> entry : count2.entrySet()) {
      final int b = entry.getKey();
      final long b2 = entry.getValue();
      if (b == a)
        continue;
      final long b1 = count1.getOrDefault(b, 0);
      // Exclude doubles -- [a ?] a [b b]
      res = (res - (other1 - b1) * nC2(b2) % kMod + kMod) % kMod;
    }

    return res;
  }
}
