class Solution {
  public int maximumSwap(int num) {
    char[] s = Integer.toString(num).toCharArray();
    int[] digitToIndex = new int[10];

    for (int i = 0; i < s.length; ++i)
      digitToIndex[s[i] - '0'] = i;

    for (int i = 0; i < s.length; ++i)
      for (char digit = '9'; digit > s[i]; --digit)
        if (digitToIndex[digit - '0'] > i) {
          s[digitToIndex[digit - '0']] = s[i];
          s[i] = digit;
          return Integer.valueOf(new String(s));
        }

    return num;
  }
}