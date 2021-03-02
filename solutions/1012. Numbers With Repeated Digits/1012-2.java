public class Solution {
  public int numDupDigitsAtMostN(int N) {
    int uniqueNumbers = 0;
    List<Integer> digits = new ArrayList<>(); // N + 1
    Set<Integer> seen = new HashSet<>();

    // transfer N + 1 to an array of digits
    for (int i = N + 1; i > 0; i /= 10)
      digits.add(i % 10);
    Collections.reverse(digits);

    final int n = digits.size();

    // unique numbers w/ digits < n
    for (int i = 1; i < n; ++i)
      uniqueNumbers += 9 * P(9, i - 1);

    // unique numbers w/ digits = n and same prefix
    for (int i = 0; i < n; ++i) {
      for (int j = i > 0 ? 0 : 1; j < digits.get(i); ++j)
        if (!seen.contains(j))
          uniqueNumbers += P(9 - i, n - i - 1);
      if (seen.contains(digits.get(i)))
        break;
      seen.add(digits.get(i));
    }

    return N - uniqueNumbers;
  }

  private int P(int m, int n) {
    int ans = 1;
    for (int i = m - n + 1; i <= m; ++i)
      ans *= i;
    return ans;
  }
}
