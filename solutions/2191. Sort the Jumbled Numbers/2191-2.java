
class Solution {
  public int[] sortJumbled(int[] mapping, int[] nums) {
    List<Integer> ans = new ArrayList<>();
    TreeMap<Integer, List<Integer>> mappedToOriginalNums = new TreeMap<>();

    for (final int num : nums) {
      final int mapped = getMapped(num, mapping);
      mappedToOriginalNums.putIfAbsent(mapped, new ArrayList<>());
      mappedToOriginalNums.get(mapped).add(num);
    }

    for (List<Integer> originalNums : mappedToOriginalNums.values())
      ans.addAll(originalNums);

    return ans.stream().mapToInt(Integer::intValue).toArray();
  }

  private int getMapped(int num, int[] mapping) {
    StringBuilder sb = new StringBuilder();
    for (final char c : String.valueOf(num).toCharArray())
      sb.append(mapping[c - '0']);
    return Integer.parseInt(sb.toString());
  }
}
