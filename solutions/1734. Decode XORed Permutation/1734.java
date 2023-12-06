class Solution {
  public int[] decode(int[] encoded) {
    // Our goal is to find the value of a1, which will allow us to decode a2,
    // a3, ..., an. This can be achieved by performing XOR operation between
    // each element in the `encoded` and a1.
    //
    // e.g. n = 3, perm = [a1, a2, a3] is a permutation of [1, 2, 3]
    //               encoded = [a1^a2, a2^a3]
    //    accumulatedEncoded = [a1^a2, a1^a3]
    //    a1 = (a1^a2)^(a1^a3)^(a1^a2^a3)
    //    a2 = a1^(a1^a2)
    //    a3 = a2^(a2^a3)
    final int n = encoded.length + 1;
    int nXors = 0;
    for (int i = 1; i <= n; i++)
      nXors ^= i;

    // Instead of constructing the array, we can track of the running XOR value
    // of `accumulatedEncoded`.
    int runningXors = 0;
    int xors = 0; // xors(accumulatedEncoded)

    for (final int encode : encoded) {
      runningXors ^= encode;
      xors ^= runningXors;
    }

    int[] ans = new int[encoded.length + 1];
    ans[0] = xors ^ nXors;

    for (int i = 0; i < encoded.length; i++)
      ans[i + 1] = ans[i] ^ encoded[i];

    return ans;
  }
}
