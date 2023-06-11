class Solution {
  public int minimumOperations(int[] nums) {
    Set<Integer> seen = Arrays.stream(nums).boxed().collect(Collectors.toSet());
    return seen.size() - (seen.contains(0) ? 1 : 0);
  }
}
