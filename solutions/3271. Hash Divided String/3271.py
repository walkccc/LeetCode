class Solution:
  def stringHash(self, s: str, k: int) -> str:
    ans = []

    for i in range(0, len(s), k):
      sumHash = sum(string.ascii_lowercase.index(s[j])
                    for j in range(i, i + k))
      ans.append(string.ascii_lowercase[sumHash % 26])

    return ''.join(ans)
