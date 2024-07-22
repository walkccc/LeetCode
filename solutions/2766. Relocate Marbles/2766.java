class Solution {
  public List<Integer> relocateMarbles(int[] nums, int[] moveFrom, int[] moveTo) {
    Set<Integer> numsSet = Arrays.stream(nums).boxed().collect(Collectors.toSet());

    for (int i = 0; i < moveFrom.length; ++i) {
      numsSet.remove(moveFrom[i]);
      numsSet.add(moveTo[i]);
    }

    return numsSet.stream().sorted().toList();
  }
}
