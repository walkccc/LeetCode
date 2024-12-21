class Solution {
  public boolean containsPattern(int[] arr, int m, int k) {
    int count = 0;
    for (int i = m; i < arr.length; ++i) {
      count = arr[i] == arr[i - m] ? count + 1 : 0;
      if (count == m * k - m)
        return true;
    }
    return false;
  }
}
