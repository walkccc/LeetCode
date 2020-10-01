class Solution {
  public int maxChunksToSorted(int[] arr) {
    final int n = arr.length;

    int ans = 0;
    int max = Integer.MIN_VALUE;
    int[] min = new int[n];
    min[n - 1] = arr[n - 1];

    for (int i = n - 2; i >= 0; --i)
      min[i] = Math.min(min[i + 1], arr[i]);

    for (int i = 0; i < n - 1; ++i) {
      max = Math.max(max, arr[i]);
      if (max <= min[i + 1])
        ++ans;
    }

    return ans + 1;
  }
}