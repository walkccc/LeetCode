class Solution:
  def maxRepOpt1(self, text: str) -> int:
    count = collections.Counter(text)
    groups = [[c, len(list(group))]
              for c, group in itertools.groupby(text)]
    ans = max(min(length + 1, count[c]) for c, length in groups)

    for i in range(1, len(groups) - 1):
      if groups[i - 1][0] == groups[i + 1][0] and groups[i][1] == 1:
        ans = max(
            ans,
            min(groups[i - 1][1] + groups[i + 1][1] + 1, count
                [groups[i - 1][0]]))

    return ans
