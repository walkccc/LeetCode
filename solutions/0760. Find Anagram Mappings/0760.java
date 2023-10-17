class Solution {
  public int[] anagramMappings(int[] nums1, int[] nums2) {
    int[] ans = new int[nums1.length];
    Map<Integer, Deque<Integer>> numToIndices = new HashMap<>();

    for (int i = 0; i < nums2.length; ++i) {
      numToIndices.putIfAbsent(nums2[i], new ArrayDeque<>());
      numToIndices.get(nums2[i]).push(i);
    }

    for (int i = 0; i < nums1.length; ++i)
      ans[i] = numToIndices.get(nums1[i]).pop();

    return ans;
  }
}
