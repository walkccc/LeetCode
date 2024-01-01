class Solution {
  public int maxCount(int[] banned, int n, int maxSum) {
    int ans = 0;
    int sum = 0;
    Set<Integer> bannedSet = Arrays.stream(banned).boxed().collect(Collectors.toSet());

    for (int i = 1; i <= n; ++i)
      if (!bannedSet.contains(i) && sum + i <= maxSum) {
        ++ans;
        sum += i;
      }

    return ans;
  }
}
