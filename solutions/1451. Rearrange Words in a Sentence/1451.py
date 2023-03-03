class Solution:
  def arrangeWords(self, text: str) -> str:
    words = text.split()
    count = collections.defaultdict(list)

    for word in words:
      count[len(word)].append(word.lower())

    c2 = OrderedDict(sorted(count.items()))

    ans = []

    for l in c2:
      for word in c2[l]:
        ans.append(word)

    ans[0] = ans[0].capitalize()

    return ' '.join(ans)
