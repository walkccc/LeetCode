class Solution {
  public int[] closestDivisors(int num) {
    for (int root = (int) Math.sqrt(num + 2); root > 0; --root)
      for (int cand : new int[] {num + 1, num + 2})
        if (cand % root == 0)
          return new int[] {root, cand / root};

    throw new IllegalArgumentException();
  }
}
