class Solution {
  public int maxSatisfaction(int[] satisfaction) {
    int ans = 0;
    int sumSatisfaction = 0;

    satisfaction = Arrays.stream(satisfaction)
                       .boxed()
                       .sorted(Collections.reverseOrder())
                       .mapToInt(Integer::intValue)
                       .toArray();

    for (final int s : satisfaction) {
      sumSatisfaction += s;
      if (sumSatisfaction <= 0)
        return ans;
      ans += sumSatisfaction;
    }

    return ans;
  }
}
