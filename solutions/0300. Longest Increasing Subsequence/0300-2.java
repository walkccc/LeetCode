class Solution {
  public int lengthOfLIS(int[] nums) {
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
    final int i = Collections.binarySearch(A, target);
    return i < 0 ? -i - 1 : i;
  }
}
