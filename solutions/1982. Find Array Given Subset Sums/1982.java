class Solution {
  public int[] recoverArray(int n, int[] sums) {
    Arrays.sort(sums);
    return recover(sums).stream().mapToInt(Integer::intValue).toArray();
  }

  private List<Integer> recover(int[] sums) {
    if (sums.length == 1) // sums[0] must be 0.
      return new ArrayList<>();

    Map<Integer, Long> count = Arrays.stream(sums).boxed().collect(
        Collectors.groupingBy(Function.identity(), Collectors.counting()));

    // Either num or -num must be in the final array.
    //  num + sumsExcludingNum = sumsIncludingNum
    // -num + sumsIncludingNum = sumsExcludingNum
    final int num = sums[1] - sums[0];
    int i = 0; // sumsExcludingNum/sumsIncludingNum's index
    int[] sumsExcludingNum = new int[sums.length / 2];
    int[] sumsIncludingNum = new int[sums.length / 2];
    boolean chooseSumsIncludingNum = false;

    for (final int sum : sums) {
      if (count.get(sum) == 0)
        continue;
      count.merge(sum, -1L, Long::sum);
      count.merge(sum + num, -1L, Long::sum);
      sumsExcludingNum[i] = sum;
      sumsIncludingNum[i] = sum + num;
      ++i;
      if (sum + num == 0)
        chooseSumsIncludingNum = true;
    }

    // Choose `sumsExludingNum` by default since we want to gradually strip
    // `num` from each sum in `sums` to have the final array. However, we should
    // always choose the group of sums with 0 since it's a must-have.
    List<Integer> recovered = recover(chooseSumsIncludingNum ? sumsIncludingNum : sumsExcludingNum);
    recovered.add(chooseSumsIncludingNum ? -num : num);
    return recovered;
  }
}
