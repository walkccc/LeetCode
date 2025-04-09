class Solution {
  public int maxChunksToSorted(int[] arr) {
    int ans = 0;
    int mx = Integer.MIN_VALUE;

    for (int i = 0; i < arr.length; ++i) {
      mx = Math.max(mx, arr[i]);
      if (mx == i)
        ++ans;
    }

    return ans;
  }
}
