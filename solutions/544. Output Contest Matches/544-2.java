class Solution {
  public String findContestMatch(int n) {
    String[] matches = new String[n];

    for (int i = 0; i < n; ++i)
      matches[i] = String.valueOf(i + 1);

    while (n > 1) {
      for (int i = 0; i < n / 2; ++i)
        matches[i] = "(" + matches[i] + "," + matches[n - 1 - i] + ")";
      n /= 2;
    }

    return matches[0];
  }
}
