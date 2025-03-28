class Solution {
  public String smallestNumber(String num, long t) {
    Pair<Map<Integer, Integer>, Boolean> primeCountResult = getPrimeCount(t);
    Map<Integer, Integer> primeCount = primeCountResult.getKey();
    boolean isDivisible = primeCountResult.getValue();
    if (!isDivisible)
      return "-1";

    Map<Integer, Integer> factorCount = getFactorCount(primeCount);
    if (sumValues(factorCount) > num.length())
      return construct(factorCount);

    Map<Integer, Integer> primeCountPrefix = getPrimeCount(num);
    int firstZeroIndex = num.indexOf('0');
    if (firstZeroIndex == -1) {
      firstZeroIndex = num.length();
      if (isSubset(primeCount, primeCountPrefix))
        return num;
    }

    for (int i = num.length() - 1; i >= 0; --i) {
      final int d = num.charAt(i) - '0';
      // Remove the current digit's factors from primeCountPrefix.
      primeCountPrefix = subtract(primeCountPrefix, FACTOR_COUNTS.get(d));
      final int spaceAfterThisDigit = num.length() - 1 - i;
      if (i > firstZeroIndex)
        continue;
      for (int biggerDigit = d + 1; biggerDigit < 10; ++biggerDigit) {
        // Compute the required factors after replacing with a larger digit.
        Map<Integer, Integer> factorsAfterReplacement = getFactorCount(
            subtract(subtract(primeCount, primeCountPrefix), FACTOR_COUNTS.get(biggerDigit)));
        // Check if the replacement is possible within the available space.
        if (sumValues(factorsAfterReplacement) <= spaceAfterThisDigit) {
          // Fill extra space with '1', if any, and construct the result.
          final int fillOnes = spaceAfterThisDigit - sumValues(factorsAfterReplacement);
          return num.substring(0, i) + // Keep the prefix unchanged.
              biggerDigit +            // Replace the current digit.
              "1".repeat(fillOnes) + // Fill remaining space with '1'.
              construct(factorsAfterReplacement);
        }
      }
    }

    // No solution of the same length exists, so we need to extend the number
    // by prepending '1's and adding the required factors.
    Map<Integer, Integer> factorsAfterExtension = getFactorCount(primeCount);
    return "1".repeat(num.length() + 1 - sumValues(factorsAfterExtension)) +
        construct(factorsAfterExtension);
  }

  private static final Map<Integer, Map<Integer, Integer>> FACTOR_COUNTS = Map.of(
      0, Map.of(), 1, Map.of(), 2, Map.of(2, 1), 3, Map.of(3, 1), 4, Map.of(2, 2), 5, Map.of(5, 1),
      6, Map.of(2, 1, 3, 1), 7, Map.of(7, 1), 8, Map.of(2, 3), 9, Map.of(3, 2));

  // Returns the prime count of t and if t is divisible by 2, 3, 5, 7.
  private Pair<Map<Integer, Integer>, Boolean> getPrimeCount(long t) {
    Map<Integer, Integer> count = new HashMap<>(Map.of(2, 0, 3, 0, 5, 0, 7, 0));
    for (int prime : new int[] {2, 3, 5, 7}) {
      while (t % prime == 0) {
        t /= prime;
        count.put(prime, count.get(prime) + 1);
      }
    }
    return new Pair<>(count, t == 1);
  }

  // Returns the prime count of `num`.
  private Map<Integer, Integer> getPrimeCount(String num) {
    Map<Integer, Integer> count = new HashMap<>(Map.of(2, 0, 3, 0, 5, 0, 7, 0));
    for (final char c : num.toCharArray()) {
      Map<Integer, Integer> digitFactors = FACTOR_COUNTS.get(c - '0');
      for (Map.Entry<Integer, Integer> entry : digitFactors.entrySet()) {
        final int prime = entry.getKey();
        final int freq = entry.getValue();
        count.merge(prime, freq, Integer::sum);
      }
    }
    return count;
  }

  private Map<Integer, Integer> getFactorCount(Map<Integer, Integer> count) {
    // 2^3 = 8
    final int count8 = count.get(2) / 3;
    final int remaining2 = count.get(2) % 3;
    // 3^2 = 9
    final int count9 = count.get(3) / 2;
    int count3 = count.get(3) % 2;
    // 2^2 = 4
    int count4 = remaining2 / 2;
    int count2 = remaining2 % 2;
    // Combine 2 and 3 to 6 if both are present
    int count6 = 0;
    if (count2 == 1 && count3 == 1) {
      count2 = 0;
      count3 = 0;
      count6 = 1;
    }
    // Combine 3 and 4 to 2 and 6 if both are present
    if (count3 == 1 && count4 == 1) {
      count2 = 1;
      count6 = 1;
      count3 = 0;
      count4 = 0;
    }
    return Map.of(2, count2, 3, count3, 4, count4, 5, count.get(5), 6, count6, 7, count.get(7), 8,
                  count8, 9, count9);
  }

  private String construct(Map<Integer, Integer> factors) {
    StringBuilder sb = new StringBuilder();
    for (int digit = 2; digit < 10; ++digit)
      sb.append(String.valueOf(digit).repeat(factors.get(digit)));
    return sb.toString();
  }

  // Returns true if a is a subset of b.
  private boolean isSubset(Map<Integer, Integer> a, Map<Integer, Integer> b) {
    for (Map.Entry<Integer, Integer> entry : a.entrySet())
      if (b.get(entry.getKey()) < entry.getValue())
        return false;
    return true;
  }

  // Returns a - b.
  private Map<Integer, Integer> subtract(Map<Integer, Integer> a, Map<Integer, Integer> b) {
    Map<Integer, Integer> res = new HashMap<>(a);
    for (Map.Entry<Integer, Integer> entry : b.entrySet()) {
      final int key = entry.getKey();
      final int value = entry.getValue();
      res.put(key, Math.max(0, res.get(key) - value));
    }
    return res;
  }

  // Returns the sum of the values in `count`.
  private int sumValues(Map<Integer, Integer> count) {
    return count.values().stream().mapToInt(Integer::intValue).sum();
  }
}
