class Solution {
  public int countPrefixes(String[] words, String s) {
    return (int) Arrays.stream(words).filter(word -> s.startsWith(word)).count();
  }
}
