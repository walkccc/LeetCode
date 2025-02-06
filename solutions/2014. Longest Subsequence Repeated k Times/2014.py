class Solution:
  def longestSubsequenceRepeatedK(self, s: str, k: int) -> str:
    ans = ''
    count = [0] * 26
    possibleChars = []
    # Stores subsequences, where the length grows by 1 each time.
    q = collections.deque([''])

    for c in s:
      count[string.ascii_lowercase.index(c)] += 1

    for c in string.ascii_lowercase:
      if count[string.ascii_lowercase.index(c)] >= k:
        possibleChars.append(c)

    def isSubsequence(subseq: str, s: str, k: int) -> bool:
      i = 0  # subseq's index
      for c in s:
        if c == subseq[i]:
          i += 1
          if i == len(subseq):
            k -= 1
            if k == 0:
              return True
            i = 0
      return False

    while q:
      currSubseq = q.popleft()
      if len(currSubseq) * k > len(s):
        return ans
      for c in possibleChars:
        newSubseq = currSubseq + c
        if isSubsequence(newSubseq, s, k):
          q.append(newSubseq)
          ans = newSubseq

    return ans
