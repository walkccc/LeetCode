class Solution:
  def countAnagrams(self, s: str) -> int:
    ans = 1

    for word in s.split():
      ans = ans * math.factorial(len(word))
      count = collections.Counter(word)
      for freq in count.values():
        ans //= math.factorial(freq)

    return ans % 1_000_000_007
