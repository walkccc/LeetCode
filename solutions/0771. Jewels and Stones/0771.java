class Solution {
  public int numJewelsInStones(String J, String S) {
    int ans = 0;
    Set<Character> jewels = new HashSet<>();

    for (char j : J.toCharArray())
      jewels.add(j);

    for (final char s : S.toCharArray())
      if (jewels.contains(s))
        ++ans;

    return ans;
  }
}
