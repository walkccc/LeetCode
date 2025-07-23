class Solution {
  public int countSymmetricIntegers(int low, int high) {
    int ans = 0;

    for (int num = low; num <= high; ++num)
      if (isSymmetricInteger(num))
        ++ans;

    return ans;
  }

  private boolean isSymmetricInteger(int num) {
    if (num >= 10 && num <= 99)
      return num / 10 == num % 10;
    if (num >= 1000 && num <= 9999) {
      final int left = num / 100;
      final int right = num % 100;
      return left / 10 + left % 10 == right / 10 + right % 10;
    }
    return false;
  }
}
