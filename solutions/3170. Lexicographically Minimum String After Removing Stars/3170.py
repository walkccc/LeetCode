class Solution:
  def clearStars(self, s: str) -> str:
    ans = list(s)
    buckets = [[] for _ in range(26)]

    for i, c in enumerate(s):
      if c == '*':
        ans[i] = ''
        j = next(j for j, bucket in enumerate(buckets) if bucket)
        ans[buckets[j].pop()] = ''
      else:
        buckets[string.ascii_lowercase.index(c)].append(i)

    return ''.join(ans)
