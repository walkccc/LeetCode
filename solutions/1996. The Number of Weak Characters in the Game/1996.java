class Solution {
  public int numberOfWeakCharacters(int[][] properties) {
    // Sort properties by attack descendingly, then by defense ascendingly.
    Arrays.sort(properties, (a, b) -> a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]);

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
