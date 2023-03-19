class Solution {
  public int distributeCandies(int[] candies) {
    BitSet bitset = new BitSet(200001);

    for (final int candy : candies)
      bitset.set(candy + 100000);

    return Math.min(candies.length / 2, bitset.cardinality());
  }
}
