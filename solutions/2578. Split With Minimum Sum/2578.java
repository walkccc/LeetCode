class Solution {
  public int splitNum(int num) {
    StringBuilder sb1 = new StringBuilder();
    StringBuilder sb2 = new StringBuilder();
    char[] chars = String.valueOf(num).toCharArray();

    Arrays.sort(chars);

    for (int i = 0; i < chars.length; ++i)
      if (i % 2 == 0)
        sb1.append(chars[i]);
      else
        sb2.append(chars[i]);

    return Integer.parseInt(sb1.toString()) + Integer.parseInt(sb2.toString());
  }
}
