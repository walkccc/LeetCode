class Solution {
  public int minOperations(int[] target, int[] arr) {
    List<Integer> indices = new ArrayList<>();
    Map<Integer, Integer> numToIndex = new HashMap<>();

    for (int i = 0; i < target.length; ++i)
      numToIndex.put(target[i], i);

    for (final int a : arr)
      if (numToIndex.containsKey(a))
        indices.add(numToIndex.get(a));

    return target.length - lengthOfLIS(indices);
  }

  // Same as 300. Longest Increasing Subsequence
  private int lengthOfLIS(List<Integer> nums) {
    // tail[i] := the min tail of all increasing subseqs with length i + 1
    // It's easy to see that tail must be an increasing array.
    List<Integer> tail = new ArrayList<>();

    for (final int num : nums)
      if (tail.isEmpty() || num > tail.get(tail.size() - 1))
        tail.add(num);
      else
        tail.set(firstGreaterEqual(tail, num), num);

    return tail.size();
  }

  private int firstGreaterEqual(List<Integer> A, int target) {
    int l = 0;
    int r = A.size();
    while (l < r) {
      final int m = (l + r) / 2;
      if (A.get(m) >= target)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
}
