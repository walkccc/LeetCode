class Solution {
  public int[] lexicographicallySmallestArray(int[] nums, int limit) {
    int[] ans = new int[nums.length];
    List<List<Pair<Integer, Integer>>> numAndIndexesGroups = new ArrayList<>();

    for (Pair<Integer, Integer> numAndIndex : getNumAndIndexes(nums))
      if (numAndIndexesGroups.isEmpty() ||
          numAndIndex.getKey() -
                  numAndIndexesGroups.get(numAndIndexesGroups.size() - 1)
                      .get(numAndIndexesGroups.get(numAndIndexesGroups.size() - 1).size() - 1)
                      .getKey() >
              limit) {
        // Start a new group.
        numAndIndexesGroups.add(new ArrayList<>(List.of(numAndIndex)));
      } else {
        // Append to the existing group.
        numAndIndexesGroups.get(numAndIndexesGroups.size() - 1).add(numAndIndex);
      }

    for (List<Pair<Integer, Integer>> numAndIndexesGroup : numAndIndexesGroups) {
      List<Integer> sortedNums = new ArrayList<>();
      List<Integer> sortedIndices = new ArrayList<>();
      for (Pair<Integer, Integer> pair : numAndIndexesGroup) {
        sortedNums.add(pair.getKey());
        sortedIndices.add(pair.getValue());
      }
      sortedIndices.sort(null);
      for (int i = 0; i < sortedNums.size(); ++i) {
        ans[sortedIndices.get(i)] = sortedNums.get(i);
      }
    }

    return ans;
  }

  private Pair<Integer, Integer>[] getNumAndIndexes(int[] nums) {
    Pair<Integer, Integer>[] numAndIndexes = new Pair[nums.length];
    for (int i = 0; i < nums.length; ++i)
      numAndIndexes[i] = new Pair<>(nums[i], i);
    Arrays.sort(numAndIndexes, (a, b) -> Integer.compare(a.getKey(), b.getKey()));
    return numAndIndexes;
  }
}
