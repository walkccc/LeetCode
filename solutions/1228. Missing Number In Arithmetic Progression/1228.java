class Solution {
  public int missingNumber(int[] arr) {
    final int n = arr.length;
    final int delta = (arr[n - 1] - arr[0]) / n;
    int l = 0;
    int r = n - 1;

    while (l < r) {
      final int m = (l + r) / 2;
      if (arr[m] == arr[0] + m * delta)
        l = m + 1;
      else
        r = m;
    }

    return arr[0] + l * delta;
  }
}
