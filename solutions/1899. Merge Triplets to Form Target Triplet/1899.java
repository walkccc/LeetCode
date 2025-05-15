class Solution {
  public boolean mergeTriplets(int[][] triplets, int[] target) {
    int[] merged = new int[target.length];

    for (int[] triplet : triplets)
      if (triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2])
        for (int i = 0; i < target.length; ++i)
          merged[i] = Math.max(merged[i], triplet[i]);

    return Arrays.equals(merged, target);
  }
}
