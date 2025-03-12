class Solution {
  public int countConsistentStrings(String allowed, String[] words) {
    return (int) Arrays.stream(words)
        .filter(word -> word.matches(String.format("[%s]*", allowed)))
        .count();
  }
}
