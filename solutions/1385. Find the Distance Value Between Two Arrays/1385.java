class Solution {
  public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
    int ans = 0;

    Arrays.sort(arr2);

    for (final int a : arr1) {
      int i = Arrays.binarySearch(arr2, a);
      i = i < 0 ? -i - 1 : i;
      if ((i == arr2.length || arr2[i] - a > d) && (i == 0 || a - arr2[i - 1] > d))
        ++ans;
    }

    return ans;
  }
}
