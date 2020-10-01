class Solution {
  public String shiftingLetters(String S, int[] shifts) {
    StringBuilder ans = new StringBuilder();

    for (int i = shifts.length - 2; i >= 0; --i)
      shifts[i] = (shifts[i] + shifts[i + 1]) % 26;

    for (int i = 0; i < S.length(); ++i)
      ans.append((char) ((S.charAt(i) - 'a' + shifts[i]) % 26 + 'a'));

    return ans.toString();
  }
}