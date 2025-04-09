class Solution {
  public int maximumScore(List<Integer> nums, int k) {
    final int n = nums.size();
    final int mx = Collections.max(nums);
    final int[] minPrimeFactors = sieveEratosthenes(mx + 1);
    final int[] primeScores = getPrimeScores(nums, minPrimeFactors);
    int ans = 1;
    // left[i] := the next index on the left (if any)
    //            s.t. primeScores[left[i]] >= primeScores[i]
    int[] left = new int[n];
    Arrays.fill(left, -1);
    // right[i] := the next index on the right (if any)
    //             s.t. primeScores[right[i]] > primeScores[i]
    int[] right = new int[n];
    Arrays.fill(right, n);
    Deque<Integer> stack = new ArrayDeque<>();

    // Find the next indices on the left where `primeScores` are greater or equal.
    for (int i = n - 1; i >= 0; --i) {
      while (!stack.isEmpty() && primeScores[stack.peek()] <= primeScores[i])
        left[stack.pop()] = i;
      stack.push(i);
    }

    stack.clear();

    // Find the next indices on the right where `primeScores` are greater.
    for (int i = 0; i < n; ++i) {
      while (!stack.isEmpty() && primeScores[stack.peek()] < primeScores[i])
        right[stack.pop()] = i;
      stack.push(i);
    }

    Pair<Integer, Integer>[] numAndIndexes = new Pair[n];

    for (int i = 0; i < n; ++i)
      numAndIndexes[i] = new Pair<>(nums.get(i), i);

    Arrays.sort(numAndIndexes,
                Comparator.comparing(Pair<Integer, Integer>::getKey, Comparator.reverseOrder())
                    .thenComparingInt(Pair<Integer, Integer>::getValue));

    for (Pair<Integer, Integer> numAndIndex : numAndIndexes) {
      final int num = numAndIndex.getKey();
      final int i = numAndIndex.getValue();
      // nums[i] is the maximum value in the range [left[i] + 1, right[i] - 1]
      // So, there are (i - left[i]) * (right[i] - 1) ranges where nums[i] will
      // be chosen.
      final long rangeCount = (long) (i - left[i]) * (right[i] - i);
      final long actualCount = Math.min(rangeCount, (long) k);
      k -= actualCount;
      ans = (int) ((1L * ans * modPow(num, actualCount)) % MOD);
    }

    return ans;
  }

  private static final int MOD = 1_000_000_007;

  private long modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x, n - 1) % MOD;
    return modPow(x * x % MOD, n / 2);
  }

  // Gets the minimum prime factor of i, where 1 < i <= n.
  private int[] sieveEratosthenes(int n) {
    int[] minPrimeFactors = new int[n + 1];
    for (int i = 2; i <= n; ++i)
      minPrimeFactors[i] = i;
    for (int i = 2; i * i < n; ++i)
      if (minPrimeFactors[i] == i) // `i` is prime.
        for (int j = i * i; j < n; j += i)
          minPrimeFactors[j] = Math.min(minPrimeFactors[j], i);
    return minPrimeFactors;
  }

  private int[] getPrimeScores(List<Integer> nums, int[] minPrimeFactors) {
    int[] primeScores = new int[nums.size()];
    for (int i = 0; i < nums.size(); ++i)
      primeScores[i] = getPrimeScore(nums.get(i), minPrimeFactors);
    return primeScores;
  }

  private int getPrimeScore(int num, int[] minPrimeFactors) {
    Set<Integer> primeFactors = new HashSet<>();
    while (num > 1) {
      final int divisor = minPrimeFactors[num];
      primeFactors.add(divisor);
      while (num % divisor == 0)
        num /= divisor;
    }
    return primeFactors.size();
  }
}
