class Solution {
  public String toHexspeak(String num) {
    final long n = Long.parseLong(num);
    final String ans = Long.toHexString(n).toUpperCase().replace('1', 'I').replace('0', 'O');
    return ans.chars().anyMatch(c -> Character.isDigit(c)) ? "ERROR" : ans;
  }
}
