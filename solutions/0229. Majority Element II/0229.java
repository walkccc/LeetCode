class Solution {
  public List<Integer> majorityElement(int[] nums) {
    List<Integer> ans = new ArrayList<>();
    int candidate1 = 0;
    int candidate2 = 1;  // any number different from candidate1
    int countSoFar1 = 0; // # of candidate1 so far
    int countSoFar2 = 0; // # of candidate2 so far

    for (final int num : nums)
      if (num == candidate1) {
        ++countSoFar1;
      } else if (num == candidate2) {
        ++countSoFar2;
      } else if (countSoFar1 == 0) { // assign new candidate
        candidate1 = num;
        ++countSoFar1;
      } else if (countSoFar2 == 0) { // assign new candidate
        candidate2 = num;
        ++countSoFar2;
      } else { // meet a new number, so pair out previous counts
        --countSoFar1;
        --countSoFar2;
      }

    int count1 = 0;
    int count2 = 0;

    for (final int num : nums)
      if (num == candidate1)
        ++count1;
      else if (num == candidate2)
        ++count2;

    if (count1 > nums.length / 3)
      ans.add(candidate1);
    if (count2 > nums.length / 3)
      ans.add(candidate2);
    return ans;
  }
}
