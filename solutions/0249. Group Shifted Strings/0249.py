class Solution:
  def groupStrings(self, strings: List[str]) -> List[List[str]]:
    keyToStrings = defaultdict(list)

    # 'abc' . '11' because diff(a, b) = 1 and diff(b, c) = 1
    def getKey(s: str) -> str:
      key = ''

      for i in range(1, len(s)):
        diff = (ord(s[i]) - ord(s[i - 1]) + 26) % 26
        key += str(diff) + ','

      return key

    for s in strings:
      keyToStrings[getKey(s)].append(s)

    return keyToStrings.values()
