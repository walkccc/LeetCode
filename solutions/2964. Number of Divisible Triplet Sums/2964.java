class Solution {
  // Similar to 1995. Count Special Quadruplets
  public int divisibleTripletCount(int[] nums, int d) {
    int ans = 0;
    Map<Integer, Integer> count = new HashMap<>();

    for (int j = nums.length - 1; j > 0; --j) { // 'j' also represents k.
      for (int i = j - 1; i >= 0; --i)
        ans += count.getOrDefault((-(nums[i] + nums[j]) % d + d) % d, 0);
      count.merge(nums[j] % d, 1, Integer::sum); // j := k
    }

    return ans;
  }
}
