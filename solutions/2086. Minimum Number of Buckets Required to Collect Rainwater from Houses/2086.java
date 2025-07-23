class Solution {
  public int minimumBuckets(String street) {
    final char[] A = street.toCharArray();

    for (int i = 0; i < A.length; ++i)
      if (A[i] == 'H') {
        if (i > 0 && A[i - 1] == 'B')
          continue;
        if (i + 1 < A.length && A[i + 1] == '.')
          // Always prefer place a bucket in (i + 1) because it enhances the
          // possibility to collect the upcoming houses.
          A[i + 1] = 'B';
        else if (i > 0 && A[i - 1] == '.')
          A[i - 1] = 'B';
        else
          return -1;
      }

    return (int) new String(A).chars().filter(a -> a == 'B').count();
  }
}
