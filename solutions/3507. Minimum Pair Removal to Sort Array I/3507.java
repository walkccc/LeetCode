class Solution {
  public int minimumPairRemoval(int[] nums) {
    int ans = 0;
    List<Integer> numsList = Arrays.stream(nums).boxed().collect(Collectors.toList());

    while (hasInversion(numsList)) {
      List<Integer> pairSums = new ArrayList<>();
      for (int i = 0; i < numsList.size() - 1; ++i)
        pairSums.add(numsList.get(i) + numsList.get(i + 1));
      int minPairSum = Integer.MAX_VALUE;
      int minPairIndex = -1;
      for (int i = 0; i < pairSums.size(); ++i)
        if (pairSums.get(i) < minPairSum) {
          minPairSum = pairSums.get(i);
          minPairIndex = i;
        }
      numsList.set(minPairIndex, minPairSum);
      numsList.remove(minPairIndex + 1);
      ++ans;
    }

    return ans;
  }

  private boolean hasInversion(List<Integer> nums) {
    for (int i = 0; i < nums.size() - 1; ++i)
      if (nums.get(i) > nums.get(i + 1))
        return true;
    return false;
  }
}
