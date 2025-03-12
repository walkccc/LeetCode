class Solution {
  public boolean canBeEqual(int[] target, int[] arr) {
    return Arrays.stream(arr)
        .boxed()
        .collect(Collectors.groupingBy(Integer::intValue, Collectors.counting()))
        .equals(Arrays.stream(target).boxed().collect(
            Collectors.groupingBy(Integer::intValue, Collectors.counting())));
  }
}
