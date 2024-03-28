class Solution {
  public int sumOfDigits(int[] nums) {
    int min = Arrays.stream(nums).min().getAsInt();
    int sum = 0;

    while (min > 0) {
      sum += min % 10;
      min /= 10;
    }

    return sum & 1 ^ 1;
  }
}
