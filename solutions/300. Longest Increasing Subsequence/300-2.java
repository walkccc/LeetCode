class Solution {
  public int lengthOfLIS(int[] nums) {
    // tails[i] := the minimum tail of all the increasing subsequences having
    // length i + 1
    // It's easy to see that `tails` must be an increasing array.
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
