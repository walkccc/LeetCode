class Solution {
  public int[] circularGameLosers(int n, int k) {
    List<Integer> ans = new ArrayList<>();
    boolean[] seen = new boolean[n];

    for (int friendIndex = 0, turn = 1; !seen[friendIndex];) {
      seen[friendIndex] = true;
      friendIndex += turn++ * k;
      friendIndex %= n;
    }

    for (int friendIndex = 0; friendIndex < n; ++friendIndex)
      if (!seen[friendIndex])
        ans.add(friendIndex + 1);

    return ans.stream().mapToInt(Integer::intValue).toArray();
  }
}
