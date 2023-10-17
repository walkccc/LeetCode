class Solution {
  public boolean canPermutePalindrome(String s) {
    Set<Character> seen = new HashSet<>();

    for (final char c : s.toCharArray())
      if (!seen.add(c))
        seen.remove(c);

    return seen.size() <= 1;
  }
}
