class Solution {
  public List<Integer> findClosestElements(int[] arr, int k, int x) {
    int l = 0;
    int r = arr.length - k;

    while (l < r) {
      final int m = (l + r) / 2;
      if (x - arr[m] <= arr[m + k] - x)
        r = m;
      else
        l = m + 1;
    }

    return Arrays.stream(arr, l, l + k).boxed().collect(Collectors.toList());
  }
}
