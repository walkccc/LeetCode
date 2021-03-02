class Solution {
  public List<Boolean> prefixesDivBy5(int[] A) {
    List<Boolean> ans = new ArrayList<>();
    int num = 0;

    for (int a : A) {
      num = (num * 2 + a) % 5;
      ans.add(num % 5 == 0);
    }

    return ans;
  }
}
