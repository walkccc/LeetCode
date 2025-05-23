class Solution:
  def distinctNames(self, ideas: list[str]) -> int:
    ans = 0
    # suffixes[i] := the set of strings omitting the first letter, where the
    # first letter is ('a' + i)
    suffixes = [set() for _ in range(26)]

    for idea in ideas:
      suffixes[ord(idea[0]) - ord('a')].add(idea[1:])

    for i, j in itertools.combinations(range(26), 2):
      count = len(suffixes[i] & suffixes[j])
      ans += 2 * (len(suffixes[i]) - count) * (len(suffixes[j]) - count)

    return ans
