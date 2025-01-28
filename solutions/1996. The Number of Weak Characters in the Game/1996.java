class Solution {
  public int numberOfWeakCharacters(int[][] properties) {
    // Sort properties by `attack` in descending order, then by `defense` in
    // ascending order.
    Arrays.sort(properties,
                (a, b) -> a[0] == b[0] ? Integer.compare(a[1], b[1]) : Integer.compare(b[0], a[0]));

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
