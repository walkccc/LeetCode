class Solution:
  def findReplaceString(self, S: str, indexes: List[int], sources: List[str], targets: List[str]) -> str:
    for index, source, target in sorted(zip(indexes, sources, targets), reverse=True):
      if S[index:index + len(source)] == source:
        S = S[:index] + target + S[index + len(source):]

    return S
