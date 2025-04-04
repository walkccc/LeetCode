class Solution:
  def letterCombinations(self, digits: str) -> list[str]:
    if not digits:
      return []

    ans = ['']
    digitToLetters = ['', '', 'abc', 'def', 'ghi',
                      'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']

    for d in digits:
      temp = []
      for s in ans:
        for c in digitToLetters[int(d)]:
          temp.append(s + c)
      ans = temp

    return ans
