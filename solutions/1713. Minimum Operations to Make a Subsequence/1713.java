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
    // tail[i] := the minimum tail of all the increasing subsequences with
    // length i + 1
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
    final int i = Collections.binarySearch(A, target);
    return i < 0 ? -i - 1 : i;
  }
}
