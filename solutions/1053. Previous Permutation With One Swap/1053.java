class Solution {
  public int[] prevPermOpt1(int[] arr) {
    final int n = arr.length;
    int l = n - 2;
    int r = n - 1;

    while (l >= 0 && arr[l] <= arr[l + 1])
      l--;
    if (l < 0)
      return arr;
    while (arr[r] >= arr[l] || arr[r] == arr[r - 1])
      r--;
    swap(arr, l, r);

    return arr;
  }

  private void swap(int[] arr, int l, int r) {
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
  }
}
