class Solution {
  public int minImpossibleOR(int[] nums) {
    int ans = 1;
    Set<Integer> numsSet = Arrays.stream(nums).boxed().collect(Collectors.toSet());

    while (numsSet.contains(ans))
      ans <<= 1;

    return ans;
  }
}
