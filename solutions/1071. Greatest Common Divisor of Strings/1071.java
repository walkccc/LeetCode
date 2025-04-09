class Solution {
  public String gcdOfStrings(String str1, String str2) {
    for (int sz = Math.min(str1.length(), str2.length()); sz > 0; --sz)
      if (isDivisible(str1, str2, sz))
        return str1.substring(0, sz);
    return "";
  }

  // Returns true if str1 and str2 are divisible by str1[0..sz).
  private boolean isDivisible(final String str1, final String str2, int sz) {
    if (str1.length() % sz > 0 || str2.length() % sz > 0)
      return false;
    final String gcd = str1.substring(0, sz);
    return str1.replace(gcd, "").isEmpty() && str2.replace(gcd, "").isEmpty();
  }
}
