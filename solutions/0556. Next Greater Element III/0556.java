class Solution {
  public int nextGreaterElement(int n) {
    String s = nextPermutation(String.valueOf(n).toCharArray());
    long ans = Long.valueOf(s);

    return ans > Integer.MAX_VALUE || ans <= (long) n ? -1 : (int) ans;
  }

  private String nextPermutation(char[] chars) {
    int i;
    for (i = chars.length - 2; i >= 0; --i)
      if (chars[i] < chars[i + 1])
        break;

    if (i >= 0) {
      int j;
      for (j = chars.length - 1; j > i; --j)
        if (chars[j] > chars[i])
          break;
      swap(chars, i, j);
    }

    reverse(chars, i + 1, chars.length - 1);

    return new String(chars);
  }

  private void reverse(char[] chars, int l, int r) {
    while (l < r)
      swap(chars, l++, r--);
  }

  private void swap(char[] chars, int i, int j) {
    char temp = chars[i];
    chars[i] = chars[j];
    chars[j] = temp;
  }
}