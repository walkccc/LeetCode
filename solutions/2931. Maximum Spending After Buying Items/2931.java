class Solution {
  public long maxSpending(int[][] values) {
    int[] sorted = Arrays.stream(values)
                       .flatMapToInt(Arrays::stream) //
                       .sorted()                     //
                       .toArray();                   //
    return LongStream.range(0, sorted.length)
        .map(i -> (i + 1) * sorted[(int) i]) //
        .sum();                              //
  }
}
