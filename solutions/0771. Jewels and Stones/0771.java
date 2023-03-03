class Solution {
  public int numJewelsInStones(String jewels, String stones) {
    int ans = 0;
    Set<Character> jewelsSet = jewels.chars().mapToObj(c -> (char) c).collect(Collectors.toSet());

    for (final char stone : stones.toCharArray())
      if (jewelsSet.contains(stone))
        ++ans;

    return ans;
  }
}
