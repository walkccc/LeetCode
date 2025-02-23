class Solution {
  public int minimumSum(int num) {
    char[] chars = String.valueOf(num).toCharArray();
    Arrays.sort(chars);
    return (chars[0] - '0') * 10 + (chars[2] - '0') + (chars[1] - '0') * 10 + (chars[3] - '0');
  }
}
