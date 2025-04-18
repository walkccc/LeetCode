class Solution {
  public int uniqueXorTriplets(int[] nums) {
    final int n = nums.length;
    if (n == 1)
      return 1;

    Set<Integer> pairs = new HashSet<>();
    BitSet triplets = new BitSet();

    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        pairs.add(nums[i] ^ nums[j]);

    for (final int pair : pairs)
      for (final int num : nums)
        triplets.set(pair ^ num);

    return triplets.cardinality();
  }
}
