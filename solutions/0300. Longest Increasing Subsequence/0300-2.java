class Solution {
  public int lengthOfLIS(int[] nums) {
    // tail[i] := the minimum tail of all increasing subseqs with length i + 1
    // it's easy to see that tail must be an increasing array
    List<Integer> tail = new ArrayList<>();

    for (final int num : nums)
      if (tail.isEmpty() || num > tail.get(tail.size() - 1))
        tail.add(num);
      else
        tail.set(firstGreaterEqual(tail, num), num);

    return tail.size();
  }

  // find the first index l s.t A.get(l) >= target
  // return nums.size() if can't find
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
