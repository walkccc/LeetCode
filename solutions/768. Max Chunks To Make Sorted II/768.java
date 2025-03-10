class Solution {
  public int maxChunksToSorted(int[] arr) {
    final int n = arr.length;
    int ans = 0;
    int[] maxL = new int[n]; // l[i] := max(arr[0..i])
    int[] minR = new int[n]; // r[i] := min(arr[i..n))

    for (int i = 0; i < n; ++i)
      maxL[i] = i == 0 ? arr[i] : Math.max(arr[i], maxL[i - 1]);

    for (int i = n - 1; i >= 0; --i)
      minR[i] = i == n - 1 ? arr[i] : Math.min(arr[i], minR[i + 1]);

    for (int i = 0; i + 1 < n; ++i)
      if (maxL[i] <= minR[i + 1])
        ++ans;

    return ans + 1;
  }
}
