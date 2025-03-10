class Solution {
  public int maxDifference(String s, int k) {
    int ans = Integer.MIN_VALUE;

    for (Pair<Character, Character> pair : getPermutations()) {
      final char a = pair.getKey();
      final char b = pair.getValue();

      // minDiff[parityA][parityB] := min(a - b) of all valid windows with
      // parityA and parityB
      int[][] minDiff = new int[2][2];
      Arrays.stream(minDiff).forEach(A -> Arrays.fill(A, Integer.MAX_VALUE / 2));
      // prefixA[i] := the number of 'a's in s[0..i)
      List<Integer> prefixA = new ArrayList<>(List.of(0));
      // prefixB[i] := the number of 'b's in s[0..i)
      List<Integer> prefixB = new ArrayList<>(List.of(0));
      for (int l = 0, r = 0; r < s.length(); ++r) {
        prefixA.add(prefixA.get(prefixA.size() - 1) + (s.charAt(r) == a ? 1 : 0));
        prefixB.add(prefixB.get(prefixB.size() - 1) + (s.charAt(r) == b ? 1 : 0));
        while (r - l + 1 >= k &&                                   // the window size >= k
               prefixA.get(l) < prefixA.get(prefixA.size() - 1) && // the number of 'a's > 0
               prefixB.get(l) < prefixB.get(prefixB.size() - 1)) { // the number of 'b's > 0
          minDiff[prefixA.get(l) % 2][prefixB.get(l) % 2] = Math.min(
              minDiff[prefixA.get(l) % 2][prefixB.get(l) % 2], prefixA.get(l) - prefixB.get(l));
          ++l;
        }
        ans = Math.max(ans, (prefixA.get(prefixA.size() - 1) - prefixB.get(prefixB.size() - 1)) -
                                minDiff[1 - prefixA.get(prefixA.size() - 1) % 2]
                                       [prefixB.get(prefixB.size() - 1) % 2]);
      }
    }

    return ans;
  }

  private List<Pair<Character, Character>> getPermutations() {
    List<Pair<Character, Character>> permutations = new ArrayList<>();
    for (final char a : "01234".toCharArray())
      for (final char b : "01234".toCharArray())
        if (a != b)
          permutations.add(new Pair<>(a, b));
    return permutations;
  }
}
