class Solution {
  public String maskPII(String S) {
    int atIndex = S.indexOf('@');
    if (atIndex > 0) {
      S = S.toLowerCase();
      return S.charAt(0) + "*****" + S.substring(atIndex - 1);
    }

    String ans = "";
    for (char c : S.toCharArray())
      if (Character.isDigit(c))
        ans += c;

    if (ans.length() == 10)
      return "***-***-" + ans.substring(ans.length() - 4);
    return '+' + new String(new char[ans.length() - 10]).replace('\0', '*') + "-***-***-"
        + ans.substring(ans.length() - 4);
  }
}