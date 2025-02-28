/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface ArrayReader {
 *   // Compares 4 different elements in the array
 *   // Returns 4 if the values of the 4 elements are the same (0 or 1).
 *   // Returns 2 if three elements have a value equal to 0 and one element has
 *   //           value equal to 1 or vice versa.
 *   // Returns 0 if two element have a value equal to 0 and two elements have
 *   //           a value equal to 1.
 *   public int query(int a, int b, int c, int d);
 *
 *   // Returns the length of the array
 *   public int length();
 * };
 */

class Solution {
  public int guessMajority(ArrayReader reader) {
    final int n = reader.length();
    final int query0123 = reader.query(0, 1, 2, 3);
    final int query1234 = reader.query(1, 2, 3, 4);
    // the number of numbers that are same as `nums[0]`
    int zeros = 1;
    // the number of numbers that are different from `nums[0]`
    int nonZeros = 0;
    // any index i s.t. nums[i] != nums[0]
    int indexNot0 = -1;

    // Find which group nums[1..3] belong to.
    for (int i = 1; i <= 3; ++i) {
      List<Integer> abcd = getABCD(i);
      if (reader.query(abcd.get(0), abcd.get(1), abcd.get(2), abcd.get(3)) == query1234) {
        ++zeros;
      } else {
        ++nonZeros;
        indexNot0 = i;
      }
    }

    // Find which group nums[4..n) belong to.
    for (int i = 4; i < n; ++i)
      if (reader.query(1, 2, 3, i) == query0123) {
        ++zeros;
      } else {
        ++nonZeros;
        indexNot0 = i;
      }

    if (zeros == nonZeros)
      return -1;
    if (zeros > nonZeros)
      return 0;
    return indexNot0;
  }

  // Returns [0..4] except i.
  private List<Integer> getABCD(int i) {
    List<Integer> abcd = new ArrayList<>(List.of(0));
    for (int j = 1; j <= 3; ++j)
      if (j != i)
        abcd.add(j);
    abcd.add(4);
    return abcd;
  }
}
