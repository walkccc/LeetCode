class Solution {
  public int[] fairCandySwap(int[] A, int[] B) {
    int diff = (IntStream.of(A).sum() - IntStream.of(B).sum()) / 2;
    Set<Integer> set = new HashSet<>();
    for (int b : B)
      set.add(b);

    for (int a : A)
      if (set.contains(a - diff))
        return new int[] {a, a - diff};

    throw new IllegalArgumentException();
  }
}
