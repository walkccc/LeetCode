class Solution {
  public int minOperations(String s1, String s2, int x) {
    List<Integer> diffIndices = getDiffIndices(s1, s2);
    if (diffIndices.isEmpty())
      return 0;
    // It's impossible to make two strings equal if there are odd number of
    // differences.
    if (diffIndices.size() % 2 == 1)
      return -1;
    Double[] mem = new Double[diffIndices.size()];
    return (int) minOperations(diffIndices, 0, x, mem);
  }

  private double minOperations(List<Integer> diffIndices, int i, double x, Double[] mem) {
    if (i == diffIndices.size())
      return 0;
    if (i == diffIndices.size() - 1)
      return x / 2;
    if (mem[i] != null)
      return mem[i];
    return mem[i] = Math.min(minOperations(diffIndices, i + 1, x, mem) + x / 2,
                             minOperations(diffIndices, i + 2, x, mem) + diffIndices.get(i + 1) -
                                 diffIndices.get(i));
  }

  private List<Integer> getDiffIndices(final String s1, final String s2) {
    List<Integer> diffIndices = new ArrayList<>();
    for (int i = 0; i < s1.length(); ++i)
      if (s1.charAt(i) != s2.charAt(i))
        diffIndices.add(i);
    return diffIndices;
  }
}
