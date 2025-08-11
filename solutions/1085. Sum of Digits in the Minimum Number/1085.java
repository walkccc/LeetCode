class Solution {
  public int sumOfDigits(int[] nums) {
    int mn = Arrays.stream(nums).min().getAsInt();
    int sum = 0;

    while (mn > 0) {
      sum += mn % 10;
      mn /= 10;
    }

    return sum & 1 ^ 1;
  }
}
