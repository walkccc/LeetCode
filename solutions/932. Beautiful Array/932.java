class Solution {
  public int[] beautifulArray(int n) {
    int[] arr = new int[n];
    for (int i = 0; i < n; ++i)
      arr[i] = i + 1;
    divide(arr, 0, n - 1, 1);
    return arr;
  }

  private void divide(int[] arr, int l, int r, int mask) {
    if (l >= r)
      return;
    final int m = partition(arr, l, r, mask);
    divide(arr, l, m, mask << 1);
    divide(arr, m + 1, r, mask << 1);
  }

  private int partition(int[] arr, int l, int r, int mask) {
    int nextSwapped = l;
    for (int i = l; i <= r; ++i)
      if ((arr[i] & mask) > 0)
        swap(arr, i, nextSwapped++);
    return nextSwapped - 1;
  }

  private void swap(int[] arr, int i, int j) {
    final int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}
