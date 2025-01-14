class Solution {
  public int minChanges(int n, int k) {
    // n needs to be a superset of k.
    return (n & k) == k ? Integer.bitCount(n ^ k) : -1;
  }
}
