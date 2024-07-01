class Solution {
  public int longestString(int x, int y, int z) {
    final int mini = Math.min(x, y);
    if (x == y)
      return (mini * 2 + z) * 2;
    return (mini * 2 + 1 + z) * 2;
  }
}
