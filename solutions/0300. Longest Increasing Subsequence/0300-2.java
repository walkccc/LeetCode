class Solution {
  public int lengthOfLIS(int[] nums) {
    int ans = 0;
    // tail[i] := the minimum tail of all increasing subseqs with length i + 1
    // it's easy to see that tail must be an increasing array
    int[] tail = new int[nums.length];

    for (final int num : nums) {
      // find the first index i in tail[0..ans) s.t. tail[i] >= num
      int i = Arrays.binarySearch(tail, 0, ans, num);
      // i = -(insertion point) - 1
      // insertion point = -(i + 1)
      if (i < 0)
        i = -(i + 1);
      tail[i] = num;
      // if didn't find any number in tail[0..ans) that is >= num, it means we
      // can append num in the current increasing subsequence
      if (i == ans)
        ++ans;
    }

    return ans;
  }
}
