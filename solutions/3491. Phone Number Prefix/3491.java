class Solution {
  public boolean phonePrefix(String[] numbers) {
    Arrays.sort(numbers);
    for (int i = 1; i < numbers.length; ++i)
      if (numbers[i].startsWith(numbers[i - 1]))
        return false;
    return true;
  }
}
