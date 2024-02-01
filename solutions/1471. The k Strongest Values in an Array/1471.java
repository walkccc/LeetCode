class Solution {
  public int[] getStrongest(int[] arr, int k) {
    Arrays.sort(arr);

    final int n = arr.length;
    final int median = arr[(n - 1) / 2];
    int[] ans = new int[k];

    for (int i = 0, l = 0, r = n - 1; i < k; ++i)
      if (median - arr[l] > arr[r] - median)
        ans[i] = arr[l++];
      else
        ans[i] = arr[r--];

    return ans;
  }
}
