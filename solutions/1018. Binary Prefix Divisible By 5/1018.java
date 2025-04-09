class Solution {
  public List<Boolean> prefixesDivBy5(int[] nums) {
    List<Boolean> ans = new ArrayList<>();
    int curr = 0;

    for (final int num : nums) {
      curr = (curr * 2 + num) % 5;
      ans.add(curr % 5 == 0);
    }

    return ans;
  }
}
