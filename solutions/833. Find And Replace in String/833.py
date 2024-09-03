class Solution:
  def findReplaceString(self, s: str, indexes: list[int],
                        sources: list[str], targets: list[str]) -> str:
    for index, source, target in sorted(
            zip(indexes, sources, targets),
            reverse=True):
      if s[index:index + len(source)] == source:
        s = s[:index] + target + s[index + len(source):]
    return s
