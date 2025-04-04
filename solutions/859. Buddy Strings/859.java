class Solution {
  public boolean buddyStrings(String s, String goal) {
    if (s.length() != goal.length())
      return false;
    if (s.equals(goal) && hasDuplicateLetters(s))
      return true;

    List<Integer> diffIndices = new ArrayList<>();

    for (int i = 0; i < s.length(); ++i)
      if (s.charAt(i) != goal.charAt(i))
        diffIndices.add(i);

    return diffIndices.size() == 2 &&
        s.charAt(diffIndices.get(0)) == goal.charAt(diffIndices.get(1)) &&
        s.charAt(diffIndices.get(1)) == goal.charAt(diffIndices.get(0));
  }

  private boolean hasDuplicateLetters(String s) {
    int[] count = new int[26];
    for (char c : s.toCharArray())
      ++count[c - 'a'];
    return Arrays.stream(count).anyMatch(freq -> freq > 1);
  }
}
