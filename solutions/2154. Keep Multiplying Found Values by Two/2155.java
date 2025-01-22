class Solution {
  public int findFinalValue(int[] nums, int original) {
    Set<Integer> numsSet = Arrays.stream(nums).boxed().collect(Collectors.toSet());
    while (numsSet.contains(original))
      original *= 2;
    return original;
  }
}
