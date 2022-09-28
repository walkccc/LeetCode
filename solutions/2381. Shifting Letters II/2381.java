class Solution {
  public String shiftingLetters(String s, int[][] shifts) {
    StringBuilder sb = new StringBuilder();
    int currShift = 0;
    int[] timeline = new int[s.length() + 1];

    for (int[] shift : shifts) {
      final int start = shift[0];
      final int end = shift[1];
      final int direction = shift[2];
      final int diff = direction == 1 ? 1 : -1;
      timeline[start] += diff;
      timeline[end + 1] -= diff;
    }

    for (int i = 0; i < s.length(); ++i) {
      currShift = (currShift + timeline[i]) % 26;
      final int num = (s.charAt(i) - 'a' + currShift + 26) % 26;
      sb.append((char) ('a' + num));
    }

    return sb.toString();
  }
}
