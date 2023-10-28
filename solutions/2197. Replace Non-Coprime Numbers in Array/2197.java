class Solution {
  public List<Integer> replaceNonCoprimes(int[] nums) {
    LinkedList<Integer> ans = new LinkedList<>();

    for (int num : nums) {
      while (!ans.isEmpty() && gcd(ans.getLast(), num) > 1)
        num = lcm(ans.removeLast(), num);
      ans.addLast(num);
    }

    return ans;
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }

  private int lcm(int a, int b) {
    return a * (b / gcd(a, b));
  }
}
