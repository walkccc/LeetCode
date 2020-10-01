class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = []
        dict = collections.defaultdict(list)

        for str in strs:
            s = ''.join(sorted(str))
            dict[s].append(str)

        return dict.values()
