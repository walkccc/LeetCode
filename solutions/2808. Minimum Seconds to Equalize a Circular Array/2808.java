class Solution {
  public int minimumSeconds(List<Integer> nums) {
    int n = nums.size();
    int ans = n;
    Map<Integer, List<Integer>> numToIndices = new HashMap<>();

    for (int i = 0; i < n; ++i) {
      numToIndices.putIfAbsent(nums.get(i), new ArrayList<>());
      numToIndices.get(nums.get(i)).add(i);
    }

    for (List<Integer> indices : numToIndices.values()) {
      int seconds = getSeconds(indices.get(0) + n, indices.get(indices.size() - 1));
      for (int i = 1; i < indices.size(); ++i)
        seconds = Math.max(seconds, getSeconds(indices.get(i), indices.get(i - 1)));
      ans = Math.min(ans, seconds);
    }

    return ans;
  }

  // Returns the number of seconds required to make nums[i..j] the same.
  private int getSeconds(int i, int j) {
    return (i - j) / 2;
  }
}
