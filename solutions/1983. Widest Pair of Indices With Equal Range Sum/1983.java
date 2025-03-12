class Solution {
  public int widestPairOfIndices(int[] nums1, int[] nums2) {
    int ans = 0;
    int prefix = 0;
    Map<Integer, Integer> prefixToIndex = new HashMap<>();
    prefixToIndex.put(0, -1);

    for (int i = 0; i < nums1.length; ++i) {
      prefix += nums1[i] - nums2[i];
      if (prefixToIndex.containsKey(prefix))
        ans = Math.max(ans, i - prefixToIndex.get(prefix));
      else
        prefixToIndex.put(prefix, i);
    }

    return ans;
  }
}
