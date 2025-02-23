class Solution {
  public int[] getFinalState(int[] nums, int k, int multiplier) {
    if (multiplier == 1)
      return nums;

    final int n = nums.length;
    final int maxNum = Arrays.stream(nums).max().getAsInt();
    int[] ans = new int[n];
    // (nums[i], i)
    Queue<int[]> minHeap = new PriorityQueue<>(
        (a, b) -> a[0] == b[0] ? Integer.compare(a[1], b[1]) : Integer.compare(a[0], b[0]));

    for (int i = 0; i < n; ++i)
      minHeap.offer(new int[] {nums[i], i});

    // Keep multiplying the minimum number as close as possible to the maximum
    // number in the array. After that, stop multiplying the minimum number
    // because it will be greater than the maximum number in the array and break
    // the circularity.
    while (k > 0 && (long) minHeap.peek()[0] * multiplier <= maxNum) {
      final int num = minHeap.peek()[0];
      final int i = minHeap.poll()[1];
      minHeap.offer(new int[] {num * multiplier, i});
      --k;
    }

    List<int[]> sortedIndexedNums = new ArrayList<>(minHeap);
    Collections.sort(
        sortedIndexedNums,
        (a, b) -> a[0] == b[0] ? Integer.compare(a[1], b[1]) : Integer.compare(a[0], b[0]));

    final int multipliesPerNum = k / n;
    final int remainingK = k % n;

    // Evenly distribute the remaining multiplications to each number by using
    // fast exponentiation.
    for (int[] indexedNums : sortedIndexedNums)
      indexedNums[0] = (int) ((long) indexedNums[0] * modPow(multiplier, multipliesPerNum) % kMod);

    // Distribute the remaining multiplications to the minimum `remainingK`
    // numbers.
    for (int i = 0; i < remainingK; ++i)
      sortedIndexedNums.get(i)[0] = (int) ((long) sortedIndexedNums.get(i)[0] * multiplier % kMod);

    for (int[] indexedNums : sortedIndexedNums) {
      final int num = indexedNums[0];
      final int i = indexedNums[1];
      ans[i] = num;
    }

    return ans;
  }

  private static final int kMod = 1_000_000_007;

  private long modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x, n - 1) % kMod;
    return modPow(x * x % kMod, n / 2);
  }
}
