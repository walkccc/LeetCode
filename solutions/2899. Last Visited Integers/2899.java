class Solution {
  public List<Integer> lastVisitedIntegers(List<String> words) {
    List<Integer> ans = new ArrayList<>();
    List<Integer> nums = new ArrayList<>();
    int k = 0;

    for (final String word : words)
      if (word.equals("prev")) {
        ++k;
        ans.add(k > nums.size() ? -1 : nums.get(nums.size() - k));
      } else {
        k = 0;
        nums.add(Integer.valueOf(word));
      }

    return ans;
  }
}
