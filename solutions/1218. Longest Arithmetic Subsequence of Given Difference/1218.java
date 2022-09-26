class Solution {
  public int longestSubsequence(int[] arr, int difference) {
    int ans = 0;
    Map<Integer, Integer> lengthAt = new HashMap<>();

    for (int a : arr) {
      lengthAt.put(a, lengthAt.getOrDefault(a - difference, 0) + 1);
      ans = Math.max(ans, lengthAt.get(a));
    }

    return ans;
  }
}
