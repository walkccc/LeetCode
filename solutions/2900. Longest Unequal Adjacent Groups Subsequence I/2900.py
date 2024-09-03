class Solution:
  def getWordsInLongestSubsequence(
      self,
      n: int,
      words: list[str],
      groups: list[int],
  ) -> list[str]:
    ans = []
    groupId = -1

    for word, group in zip(words, groups):
      if group != groupId:
        groupId = group
        ans.append(word)

    return ans
