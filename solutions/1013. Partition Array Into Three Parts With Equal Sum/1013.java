class Solution {
  public boolean canThreePartsEqualSum(int[] arr) {
    final int sum = Arrays.stream(arr).sum();
    if (sum % 3 != 0)
      return false;

    final int average = sum / 3;
    int partCount = 0;
    int partSum = 0;

    for (final int a : arr) {
      partSum += a;
      if (partSum == average) {
        ++partCount;
        partSum = 0;
      }
    }

    // edge case: arr = [0, 0, 0, 0] -> partCount = 4.
    return partCount >= 3;
  }
}
