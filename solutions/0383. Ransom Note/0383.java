class Solution {
  public boolean canConstruct(String ransomNote, String magazine) {
    int[] count = new int[128];

    for (final char c : magazine.toCharArray())
      ++count[c];

    for (final char c : ransomNote.toCharArray())
      if (--count[c] < 0)
        return false;

    return true;
  }
}
