class Solution:
  def discountPrices(self, sentence: str, discount: int) -> str:
    kPrecision = 2
    ans = []

    for word in sentence.split():
      if word[0] == '$' and len(word) > 1:
        digits = word[1:]
        if all(digit.isdigit() for digit in digits):
          val = float(digits) * (100 - discount) / 100
          s = f'{val:.2f}'
          trimmed = s[:s.index('.') + kPrecision + 1]
          ans.append('$' + trimmed)
        else:
          ans.append(word)
      else:
        ans.append(word)

    return ' '.join(ans)
