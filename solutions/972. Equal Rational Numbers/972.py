class Solution:
  def isRationalEqual(self, s: str, t: str) -> bool:
    ratios = [1, 1 / 9, 1 / 99, 1 / 999, 1 / 9999]

    def valueOf(s: str) -> float:
      if s.find('(') == -1:
        return float(s)

      # Get the indices.
      leftParenIndex = s.find('(')
      rightParenIndex = s.find(')')
      dotIndex = s.find('.')

      # integerAndNonRepeating := <IntegerPart><.><NonRepeatingPart>
      integerAndNonRepeating = float(s[:leftParenIndex])
      nonRepeatingLength = leftParenIndex - dotIndex - 1

      # repeating := <RepeatingPart>
      repeating = int(s[leftParenIndex + 1:rightParenIndex])
      repeatingLength = rightParenIndex - leftParenIndex - 1
      return integerAndNonRepeating + repeating * 0.1**nonRepeatingLength * ratios[repeatingLength]

    return abs(valueOf(s) - valueOf(t)) < 1e-9
