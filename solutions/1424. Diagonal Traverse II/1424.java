class Solution {
  public int[] findDiagonalOrder(List<List<Integer>> nums) {
    List<Integer> ans = new ArrayList<>();
    Map<Integer, List<Integer>> keyToNums = new HashMap<>(); // key = row + col
    int maxKey = 0;

    for (int i = 0; i < nums.size(); ++i)
      for (int j = 0; j < nums.get(i).size(); ++j) {
        final int key = i + j;
        keyToNums.putIfAbsent(key, new ArrayList<>());
        keyToNums.get(key).add(nums.get(i).get(j));
        maxKey = Math.max(key, maxKey);
      }

    for (int i = 0; i <= maxKey; ++i)
      for (int j = keyToNums.get(i).size() - 1; j >= 0; --j)
        ans.add(keyToNums.get(i).get(j));

    return ans.stream().mapToInt(Integer::intValue).toArray();
  }
}
