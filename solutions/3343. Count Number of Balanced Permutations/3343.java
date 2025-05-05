class Solution {
  public int countBalancedPermutations(String num) {
    int[] nums = getNums(num);
    final int sum = Arrays.stream(nums).sum();
    if (sum % 2 == 1)
      return 0;

    Arrays.sort(nums);
    reverse(nums, 0, nums.length - 1);

    final int even = (nums.length + 1) / 2;
    final int odd = nums.length / 2;
    final int evenBalance = sum / 2;
    Long[][][] mem = new Long[even + 1][odd + 1][evenBalance + 1];
    final long perm = getPerm(nums);
    return (
        int) ((countBalancedPermutations(nums, even, odd, evenBalance, mem) * modInverse(perm)) %
              MOD);
  }

  private static final int MOD = 1_000_000_007;

  // Returns the number of permutations where there are `even` even indices
  // left, `odd` odd indices left, and `evenBalance` is the target sum of the
  // remaining numbers to be placed in even indices.
  private long countBalancedPermutations(int[] nums, int even, int odd, int evenBalance,
                                         Long[][][] mem) {
    if (evenBalance < 0)
      return 0;
    if (even == 0)
      return evenBalance == 0 ? factorial(odd) : 0;
    final int index = nums.length - (even + odd);
    if (odd == 0) {
      long remainingSum = 0;
      for (int i = index; i < nums.length; ++i)
        remainingSum += nums[i];
      return remainingSum == evenBalance ? factorial(even) : 0;
    }
    if (mem[even][odd][evenBalance] != null)
      return mem[even][odd][evenBalance];
    final long placeEven =
        countBalancedPermutations(nums, even - 1, odd, evenBalance - nums[index], mem) * even % MOD;
    final long placeOdd =
        countBalancedPermutations(nums, even, odd - 1, evenBalance, mem) * odd % MOD;
    return mem[even][odd][evenBalance] = (placeEven + placeOdd) % MOD;
  }

  private int[] getNums(String num) {
    int[] nums = new int[num.length()];
    for (int i = 0; i < num.length(); ++i)
      nums[i] = num.charAt(i) - '0';
    return nums;
  }

  private long getPerm(int[] nums) {
    long res = 1;
    int[] count = new int[10];
    for (final int num : nums)
      ++count[num];
    for (final int freq : count)
      res = res * factorial(freq) % MOD;
    return res;
  }

  private long factorial(int n) {
    long res = 1;
    for (int i = 2; i <= n; ++i)
      res = res * i % MOD;
    return res;
  }

  private long modInverse(long a) {
    long m = MOD;
    long y = 0;
    long x = 1;
    while (a > 1) {
      final long q = a / m;
      long t = m;
      m = a % m;
      a = t;
      t = y;
      y = x - q * y;
      x = t;
    }

    return x < 0 ? x + MOD : x;
  }

  private void reverse(int[] nums, int l, int r) {
    while (l < r)
      swap(nums, l++, r--);
  }

  private void swap(int[] nums, int i, int j) {
    final int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }
}
