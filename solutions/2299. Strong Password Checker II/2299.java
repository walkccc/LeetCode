class Solution {
  public boolean strongPasswordCheckerII(String password) {
    if (password.length() < 8)
      return false;

    final boolean hasLowerCase = password.chars().anyMatch(c -> Character.isLowerCase(c));
    if (!hasLowerCase)
      return false;

    final boolean hasUpperCase = password.chars().anyMatch(c -> Character.isUpperCase(c));
    if (!hasUpperCase)
      return false;

    final boolean hasDigit = password.chars().anyMatch(c -> Character.isDigit(c));
    if (!hasDigit)
      return false;

    final boolean hasSpecial = password.chars().anyMatch(c -> "!@#$%^&*()-+".indexOf(c) != -1);
    if (!hasSpecial)
      return false;

    for (int i = 1; i < password.length(); ++i)
      if (password.charAt(i) == password.charAt(i - 1))
        return false;
    return true;
  }
}
