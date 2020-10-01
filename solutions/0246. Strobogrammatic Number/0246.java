class Solution {
  public boolean isStrobogrammatic(String num) {
    int[] rotated = new int[] { '0', '1', 'n', 'n', 'n', 'n', '9', 'n', '8', '6' };

    for (int i = 0; i < num.length(); ++i)
      if (rotated[num.charAt(i) - '0'] != num.charAt(num.length() - 1 - i))
        return false;

    return true;
  }
}