class Solution {
  public int minAddToMakeValid(String s) {
    int l = 0;
    int r = 0;

    for (final char c : s.toCharArray())
      if (c == '(') {
        ++l;
      } else {
        if (l == 0)
          ++r;
        else
          --l;
      }

    return l + r;
  }
}
