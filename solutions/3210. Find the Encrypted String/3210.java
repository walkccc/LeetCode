class Solution {
  public String getEncryptedString(String s, int k) {
    k %= s.length();
    return s.substring(k) + s.substring(0, k);
  }
}
