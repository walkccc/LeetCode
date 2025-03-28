class Solution:
  def largestMultipleOfThree(self, digits: list[int]) -> str:
    ans = ''
    mod1 = [1, 4, 7, 2, 5, 8]
    mod2 = [2, 5, 8, 1, 4, 7]
    count = collections.Counter(digits)
    summ = sum(digits)

    while summ % 3 != 0:
      for digit in (mod1 if summ % 3 == 1 else mod2):
        if count[digit]:
          count[digit] -= 1
          summ -= digit
          break

    for digit in reversed(range(10)):
      ans += str(digit) * count[digit]

    return '0' if len(ans) and ans[0] == '0' else ans
