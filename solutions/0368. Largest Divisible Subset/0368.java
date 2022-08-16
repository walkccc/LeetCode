class Solution {
  public List<Integer> largestDivisibleSubset(int[] nums) {
    final int n = nums.length;
    List<Integer> ans = new ArrayList<>();
    // sizeEndsAt[i] := largest size ends at nums[i]
    int[] sizeEndsAt = new int[n];
    // prevIndex[i] := the best index s.t.
    // 1. nums[i] % nums[prevIndex[i]] == 0 and
    // 2. can increase the size of the subset
    int[] prevIndex = new int[n];
    int maxSize = 0; // max size of the subset
    int index = -1;  // track the best ending index

    Arrays.fill(sizeEndsAt, 1);
    Arrays.fill(prevIndex, -1);
    Arrays.sort(nums);

    // fix max ending num in the subset first
    for (int i = 0; i < n; ++i) {
      for (int j = i - 1; j >= 0; --j)
        if (nums[i] % nums[j] == 0 && sizeEndsAt[i] < sizeEndsAt[j] + 1) {
          sizeEndsAt[i] = sizeEndsAt[j] + 1;
          prevIndex[i] = j;
        }
      // find a new subset that has a bigger size
      if (maxSize < sizeEndsAt[i]) {
        maxSize = sizeEndsAt[i];
        index = i; // update the best ending index
      }
    }

    // loop from back to front
    while (index != -1) {
      ans.add(nums[index]);
      index = prevIndex[index];
    }

    return ans;
  }
}
