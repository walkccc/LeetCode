class Solution {
  public boolean isStrobogrammatic(String num) {
    char[] rotated = {'0', '1', 'n', 'n', 'n', 'n', '9', 'n', '8', '6'};

    for (int l = 0, r = num.length() - 1; l <= r; ++l, --r)
      if (rotated[num.charAt(l) - '0'] != num.charAt(r))
        return false;

    return true;
  }
}
