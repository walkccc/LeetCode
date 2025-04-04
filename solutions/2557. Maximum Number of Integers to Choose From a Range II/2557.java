class Solution {
  public int maxCount(int[] banned, int n, long maxSum) {
    Set<Integer> bannedSet = Arrays.stream(banned).boxed().collect(Collectors.toSet());
    int l = 1;
    int r = n;

    while (l < r) {
      final int m = (l + r + 1) / 2;
      if (getSum(bannedSet, m) > maxSum)
        r = m - 1;
      else
        l = m;
    }

    int ans = l;
    for (final int b : bannedSet)
      if (b <= l)
        --ans;
    return ans;
  }

  // Returns sum([1..m]) - sum(bannedSet).
  private long getSum(Set<Integer> bannedSet, long m) {
    long sum = m * (m + 1) / 2; // sum([1..m])
    for (final int b : bannedSet)
      if (b <= m)
        sum -= b;
    return sum;
  }
}
