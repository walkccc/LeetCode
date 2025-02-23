class Solution {
  public long countPairs(int[] nums1, int[] nums2) {
    long ans = 0;
    int[] arr = new int[nums1.length]; // arr[i] = nums1[i] - nums2[i]

    for (int i = 0; i < arr.length; ++i)
      arr[i] = nums1[i] - nums2[i];

    Arrays.sort(arr);

    for (int i = 0; i < arr.length; ++i) {
      final int index = firstGreater(arr, -arr[i]);
      ans += arr.length - Math.max(i + 1, index);
    }

    return ans;
  }

  private int firstGreater(int[] arr, int target) {
    int l = 0;
    int r = arr.length;
    while (l < r) {
      final int m = (l + r) / 2;
      if (arr[m] > target)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
}
