class Solution {
  public int magicalString(int n) {
    StringBuilder sb = new StringBuilder(" 122");
    int ans = 0;

    for (int i = 3; i <= n; ++i)
      if (i % 2 == 1)
        sb.append(String.valueOf('1').repeat(sb.charAt(i) - '0'));
      else
        sb.append(String.valueOf('2').repeat(sb.charAt(i) - '0'));

    for (int i = 0; i <= n; ++i)
      if (sb.charAt(i) == '1')
        ++ans;

    return ans;
  }
}
