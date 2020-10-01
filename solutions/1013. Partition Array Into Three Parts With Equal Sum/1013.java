class Solution {
  public boolean canThreePartsEqualSum(int[] A) {
    int sum = Arrays.stream(A).sum();
    int prefixSum = 0;
    int parts = 1;

    for (int a : A) {
      prefixSum += a;
      if (prefixSum == sum * parts / 3)
        ++parts;
    }

    return sum % 3 == 0 && parts >= 3;
  }
}