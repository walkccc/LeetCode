class Solution {
  public int removeAlmostEqualCharacters(String word) {
    int ans = 0;

    int i = 1;
    while (i < word.length())
      if (Math.abs(word.charAt(i) - word.charAt(i - 1)) <= 1) {
        ++ans;
        i += 2;
      } else {
        i += 1;
      }

    return ans;
  }
}
