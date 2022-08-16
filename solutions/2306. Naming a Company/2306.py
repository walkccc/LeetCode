class Solution:
  def distinctNames(self, ideas: List[str]) -> int:
    ans = 0
    # group strings by initials
    suffixes = [set() for _ in range(26)]

    for idea in ideas:
      suffixes[ord(idea[0]) - ord('a')].add(idea[1:])

    for i in range(25):
      for j in range(i + 1, 26):
        count = len(suffixes[i] & suffixes[j])
        ans += 2 * (len(suffixes[i]) - count) * (len(suffixes[j]) - count)

    return ans
