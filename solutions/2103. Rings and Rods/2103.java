class Solution {
  public int countPoints(String rings) {
    int[] colors = new int[10];

    for (int i = 0; i < rings.length(); i += 2) {
      final char c = rings.charAt(i);
      final int color = c == 'R' ? 1 : c == 'G' ? 2 : 4;
      colors[rings.charAt(i + 1) - '0'] |= color;
    }

    return (int) Arrays.stream(colors).filter(c -> c == 7).count();
  }
}
