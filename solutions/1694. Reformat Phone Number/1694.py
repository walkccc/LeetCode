class Solution:
  def reformatNumber(self, number: str) -> str:
    ans = []

    number = number.replace("-", "").replace(" ", "")

    i = 0  # number's index
    while i + 4 < len(number):
      ans.append(number[i:i + 3] + '-')
      i += 3

    countFinalDigits = len(number) - i
    if countFinalDigits < 4:
      ans.append(number[i:])
    else:  # countFinalDigits == 4
      ans.append(number[i:i + 2] + '-' + number[i + 2:])

    return ''.join(ans)
