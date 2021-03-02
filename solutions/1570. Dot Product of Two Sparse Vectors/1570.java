class SparseVector {
  SparseVector(int[] nums) {
    for (int i = 0; i < nums.length; ++i)
      if (nums[i] != 0)
        indexToNum.put(i, nums[i]);
  }

  // Return the dotProduct of two sparse vectors
  public int dotProduct(SparseVector vec) {
    if (indexToNum.size() < vec.indexToNum.size())
      return vec.dotProduct(this);

    int ans = 0;

    for (final int index : vec.indexToNum.keySet())
      if (indexToNum.containsKey(index))
        ans += vec.indexToNum.get(index) * indexToNum.get(index);

    return ans;
  }

  private Map<Integer, Integer> indexToNum = new HashMap<>();
}
