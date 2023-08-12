class Solution {
  public String reorderSpaces(String text) {
    final String[] words = text.trim().split("\\s+");
    final int spaces = (int) text.chars().filter(c -> c == ' ').count();
    final int n = words.length;
    final int gapSize = n == 1 ? 0 : spaces / (n - 1);
    final int remains = n == 1 ? spaces : spaces % (n - 1);
    return String.join(" ".repeat(gapSize), words) + " ".repeat(remains);
  }
}
