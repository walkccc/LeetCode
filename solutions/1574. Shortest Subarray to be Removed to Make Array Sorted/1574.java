class Solution {
  public int findLengthOfShortestSubarray(int[] arr) {
    final int n = arr.length;
    int l = 0;
    int r = n - 1;

    // arr[0..l] is non-decreasing prefix.
    while (l < n - 1 && arr[l + 1] >= arr[l])
      ++l;
    // arr[r..n - 1] is non-decreasing suffix.
    while (r > 0 && arr[r - 1] <= arr[r])
      --r;
    // Remove arr[l + 1..n - 1] or arr[0..r - 1]
    int ans = Math.min(n - 1 - l, r);

    // Since arr[0..l] and arr[r..n - 1] are non-decreasing, we place pointers
    // at the rightmost indices, l and n - 1, and greedily shrink them toward
    // the leftmost indices, 0 and r, respectively. By removing arr[i + 1..j],
    // we ensure that `arr` becomes non-decreasing.
    int i = l;
    int j = n - 1;
    while (i >= 0 && j >= r && j > i) {
      if (arr[i] <= arr[j])
        --j;
      else
        --i;
      ans = Math.min(ans, j - i);
    }

    return ans;
  }
}
