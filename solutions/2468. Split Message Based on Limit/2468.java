class Solution {
  public String[] splitMessage(String message, int limit) {
    final int kMessageLength = message.length();
    int b = 1;
    // the total length of a: initialized with the length of "1"
    int aLength = sz(1);

    // the total length of b := b * sz(b)
    // The total length of "</>" := b * 3
    while (b * limit < b * (sz(b) + 3) + aLength + kMessageLength) {
      // If the length of the last suffix "<b/b>" := sz(b) * 2 + 3 >= limit,
      // then it's impossible that the length of "*<b/b>" <= limit.
      if (sz(b) * 2 + 3 >= limit)
        return new String[] {};
      aLength += sz(++b);
    }

    String[] ans = new String[b];

    for (int i = 0, a = 1; a <= b; ++a) {
      // the length of "<a/b>" := sz(a) + sz(b) + 3
      final int j = limit - (sz(a) + sz(b) + 3);
      ans[a - 1] = message.substring(i, Math.min(message.length(), i + j)) + "<" +
                   String.valueOf(a) + "/" + String.valueOf(b) + ">";
      i += j;
    }

    return ans;
  }

  private int sz(int num) {
    return String.valueOf(num).length();
  }
}
