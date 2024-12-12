class SparseVector {
  SparseVector(int[] nums) {
    for (int i = 0; i < nums.length; ++i)
      if (nums[i] != 0)
        v.add(new T(i, nums[i]));
  }

  // Returns the dot product of the two sparse vectors.
  public int dotProduct(SparseVector vec) {
    int ans = 0;

    for (int i = 0, j = 0; i < v.size() && j < vec.v.size();)
      if (v.get(i).index == vec.v.get(j).index)
        ans += v.get(i++).num * vec.v.get(j++).num;
      else if (v.get(i).index < vec.v.get(j).index)
        ++i;
      else
        ++j;

    return ans;
  }

  private record T(int index, int num) {}
  private List<T> v = new ArrayList<>(); // [(index, num)]
}
