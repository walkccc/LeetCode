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
    // tails[i] := the minimum tail of all the increasing subsequences with
    // length i + 1
    List<Integer> tails = new ArrayList<>();
    for (final int num : nums)
      if (tails.isEmpty() || num > tails.get(tails.size() - 1))
        tails.add(num);
      else
        tails.set(firstGreaterEqual(tails, num), num);
    return tails.size();
  }

  private int firstGreaterEqual(List<Integer> A, int target) {
    final int i = Collections.binarySearch(A, target);
    return i < 0 ? -i - 1 : i;
  }
}
