class Solution:
  def letterCombinations(self, digits: str) -> List[str]:
    if not digits:
      return []

    ans = ['']
    digitToLetters = ['', '', 'abc', 'def', 'ghi',
                      'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']

    for d in digits:
      temp = []
      for s in ans:
        for c in digitToLetters[ord(d) - ord('0')]:
          temp.append(s + c)
      ans = temp

    return ans
