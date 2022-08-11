class Solution:
  def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
    dict = defaultdict(list)

    for str in strs:
      key = ''.join(sorted(str))
      dict[key].append(str)

    return dict.values()
