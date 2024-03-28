class Solution:
  def sortString(self, s: str) -> str:
    ans = []
    count = collections.Counter(s)

    while count:
      for chars in string.ascii_lowercase, reversed(string.ascii_lowercase):
        ans += [c for c in chars if c in count]
        count -= dict.fromkeys(count, 1)

    return ''.join(ans)
