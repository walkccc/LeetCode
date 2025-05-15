class Solution:
  def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
    dict = collections.defaultdict(list)

    for str in strs:
      key = ''.join(sorted(str))
      dict[key].append(str)

    return dict.values()
