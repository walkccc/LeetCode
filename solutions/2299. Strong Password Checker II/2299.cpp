class Solution {
 public:
  bool strongPasswordCheckerII(string password) {
    if (password.length() < 8)
      return false;

    const bool hasLowerCase =
        ranges::any_of(password, [](const char c) { return islower(c); });
    if (!hasLowerCase)
      return false;

    const bool hasUpperCase =
        ranges::any_of(password, [](const char c) { return isupper(c); });
    if (!hasUpperCase)
      return false;

    const bool hasDigit =
        ranges::any_of(password, [](const char c) { return isdigit(c); });
    if (!hasDigit)
      return false;

    const bool hasSpecial = ranges::any_of(password, [](const char c) {
      return string("!@#$%^&*()-+").find(c) != string::npos;
    });
    if (!hasSpecial)
      return false;

    for (int i = 1; i < password.length(); ++i)
      if (password[i] == password[i - 1])
        return false;
    return true;
  }
};
