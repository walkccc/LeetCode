class Solution {
  public String largestMultipleOfThree(int[] digits) {
    StringBuilder ans = new StringBuilder();
    int[] mod1 = new int[] {1, 4, 7, 2, 5, 8};
    int[] mod2 = new int[] {2, 5, 8, 1, 4, 7};
    int[] count = new int[10];
    int sum = 0;

    for (int digit : digits) {
      ++count[digit];
      sum += digit;
    }

    while (sum % 3 != 0)
      for (int i : sum % 3 == 1 ? mod1 : mod2)
        if (count[i] > 0) {
          --count[i];
          sum -= i;
          break;
        }

    for (int digit = 9; digit >= 0; --digit)
      ans.append(Character.toString('0' + digit).repeat(count[digit]));

    return ans.length() > 0 && ans.charAt(0) == '0' ? "0" : ans.toString();
  }
}
