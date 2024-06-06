class Solution {
  public int numberOfWeakCharacters(int[][] properties) {
    int ans = 0;
    final int maxAttack = Arrays.stream(properties).mapToInt(p -> p[0]).max().getAsInt();
    // maxDefenses[i] := the maximum defense for the i-th attack
    int[] maxDefenses = new int[maxAttack + 2];

    for (int[] property : properties) {
      final int attack = property[0];
      final int defense = property[1];
      maxDefenses[attack] = Math.max(maxDefenses[attack], defense);
    }

    for (int i = maxAttack; i >= 1; --i)
      maxDefenses[i] = Math.max(maxDefenses[i], maxDefenses[i + 1]);

    for (int[] property : properties) {
      final int attack = property[0];
      final int defense = property[1];
      if (maxDefenses[attack + 1] > defense)
        ++ans;
    }

    return ans;
  }
}
