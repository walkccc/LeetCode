class Solution {
  public int numberOfWeakCharacters(int[][] properties) {
    // Sort properties by `attack` in descending order, then by `defense` in
    // ascending order.
    Arrays.sort(properties, Comparator.comparingInt((int[] property) -> - property[0])
                                .thenComparingInt((int[] property) -> property[1]));

    int ans = 0;
    int maxDefense = 0;

    for (int[] property : properties) {
      final int defense = property[1];
      if (defense < maxDefense)
        ++ans;
      maxDefense = Math.max(maxDefense, defense);
    }

    return ans;
  }
}
