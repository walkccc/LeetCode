class Solution {
  public int subarrayBitwiseORs(int[] arr) {
    List<Integer> s = new ArrayList<>();
    int l = 0;

    for (final int a : arr) {
      final int r = s.size();
      s.add(a);
      // s[l..r) are values generated in the previous iteration
      for (int i = l; i < r; ++i)
        if (s.get(s.size() - 1) != (s.get(i) | a))
          s.add(s.get(i) | a);
      l = r;
    }

    return new HashSet<>(s).size();
  }
}
