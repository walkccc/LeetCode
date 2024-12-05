class Solution {
  public long findScore(int[] nums) {
    long ans = 0;
    TreeSet<Pair<Integer, Integer>> numAndIndices =
        new TreeSet<>((a, b)
                          -> a.getKey().equals(b.getKey()) ? a.getValue().compareTo(b.getValue())
                                                           : a.getKey().compareTo(b.getKey()));
    boolean[] seen = new boolean[nums.length];

    for (int i = 0; i < nums.length; ++i)
      numAndIndices.add(new Pair<>(nums[i], i));

    for (Pair<Integer, Integer> pair : numAndIndices) {
      final int num = pair.getKey();
      final int i = pair.getValue();
      if (seen[i])
        continue;
      if (i > 0)
        seen[i - 1] = true;
      if (i + 1 < nums.length)
        seen[i + 1] = true;
      seen[i] = true;
      ans += num;
    }

    return ans;
  }
}
