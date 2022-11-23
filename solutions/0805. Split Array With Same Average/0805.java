class Solution {
  public boolean splitArraySameAverage(int[] A) {
    final int n = A.length;
    final int sum = Arrays.stream(A).sum();
    if (!isPossible(sum, n))
      return false;

    List<Set<Integer>> sums = new ArrayList<>();

    for (int i = 0; i < n / 2 + 1; ++i)
      sums.add(new HashSet<>());
    sums.get(0).add(0);

    for (final int a : A)
      for (int i = n / 2; i > 0; --i)
        for (final int num : sums.get(i - 1))
          sums.get(i).add(a + num);

    for (int i = 1; i < n / 2 + 1; ++i)
      if (i * sum % n == 0 && sums.get(i).contains(i * sum / n))
        return true;

    return false;
  }

  private boolean isPossible(int sum, int n) {
    for (int i = 1; i < n / 2 + 1; ++i)
      if (i * sum % n == 0)
        return true;
    return false;
  }
}
