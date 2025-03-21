class Solution {
  public List<Long> maximumEvenSplit(long finalSum) {
    if (finalSum % 2 == 1)
      return new ArrayList<>();

    List<Long> ans = new ArrayList<>();
    long needSum = finalSum;
    long even = 2;

    while (needSum - even >= even + 2) {
      ans.add(even);
      needSum -= even;
      even += 2;
    }

    ans.add(needSum);
    return ans;
  }
}
