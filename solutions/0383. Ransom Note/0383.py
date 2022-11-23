class Solution:
  def canConstruct(self, ransomNote: str, magazine: str) -> bool:
    count1 = Counter(ransomNote)
    count2 = Counter(magazine)
    return all(count1[c] <= count2[c] for c in string.ascii_lowercase)
