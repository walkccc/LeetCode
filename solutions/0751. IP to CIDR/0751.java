class Solution {
  public List<String> ipToCIDR(String ip, int n) {
    List<String> ans = new ArrayList<>();
    long num = getNum(ip.split("\\."));

    while (n > 0) {
      final long lowbit = num & -num;
      final long count = lowbit == 0 ? maxLow(n) : firstFit(lowbit, n);
      ans.add(getCIDR(num, getPrefix(count)));
      n -= (int) count;
      num += count;
    }

    return ans;
  }

  private long getNum(String[] x) {
    long num = 0;
    for (int i = 0; i < 4; ++i)
      num = num * 256 + Long.parseLong(x[i]);
    return num;
  }

  // return max i s.t. 2^i < n
  private int maxLow(int n) {
    for (int i = 0; i < 32; ++i)
      if (1 << i + 1 > n)
        return 1 << i;
    throw new IllegalArgumentException();
  }

  private long firstFit(long lowbit, long n) {
    while (lowbit > n)
      lowbit >>= 1;
    return lowbit;
  }

  private String getCIDR(long num, long prefix) {
    final long d = num & 255;
    num >>= 8;
    final long c = num & 255;
    num >>= 8;
    final long b = num & 255;
    num >>= 8;
    final long a = num & 255;
    return new StringBuilder()
        .append(a)
        .append(".")
        .append(b)
        .append(".")
        .append(c)
        .append(".")
        .append(d)
        .append("/")
        .append(prefix)
        .toString();
  }

  // e.g. count = 8 = 2^3 -> prefix = 32 - 3 = 29
  //      count = 1 = 2^0 -> prefix = 32 - 0 = 32
  private int getPrefix(long count) {
    for (int i = 0; i < 32; ++i)
      if (count == 1 << i)
        return 32 - i;
    throw new IllegalArgumentException();
  }
}
