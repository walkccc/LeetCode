class Solution {
  public int countRangeSum(int[] nums, int lower, int upper) {
    final int n = nums.length;

    long[] prefixSum = new long[n + 1];

    for (int i = 1; i <= n; ++i)
      prefixSum[i] += prefixSum[i - 1] + (long) nums[i - 1];

    mergeSort(prefixSum, 0, n, lower, upper);

    return count;
  }

  private int count = 0;

  private void mergeSort(long[] prefixSum, int l, int r, int lower, int upper) {
    if (l >= r)
      return;

    final int m = l + (r - l) / 2;
    mergeSort(prefixSum, l, m, lower, upper);
    mergeSort(prefixSum, m + 1, r, lower, upper);
    merge(prefixSum, l, m, r, lower, upper);
  }

  private void merge(long[] prefixSum, int l, int m, int r, int lower, int upper) {
    int lo = m + 1; // 1st index s.t. prefixSum[lo] - prefixSum[i] >= lower
    int hi = m + 1; // 1st index s.t. prefixSum[hi] - prefixSum[i] > upper

    // for each index i in range [l, m], add hi - lo to count
    for (int i = l; i <= m; ++i) {
      while (lo <= r && prefixSum[lo] - prefixSum[i] < lower)
        ++lo;
      while (hi <= r && prefixSum[hi] - prefixSum[i] <= upper)
        ++hi;
      count += hi - lo;
    }

    long[] sorted = new long[r - l + 1];
    int k = 0; // point to sorted
    int i = l; // point to left
    int j = m + 1; // point to right

    while (i <= m && j <= r)
      if (prefixSum[i] < prefixSum[j])
        sorted[k++] = prefixSum[i++];
      else
        sorted[k++] = prefixSum[j++];

    // put possible remaining left part to the sorted array
    while (i <= m)
      sorted[k++] = prefixSum[i++];

    // put possible remaining right part to the sorted array
    while (j <= r)
      sorted[k++] = prefixSum[j++];

    System.arraycopy(sorted, 0, prefixSum, l, sorted.length);
  }
}