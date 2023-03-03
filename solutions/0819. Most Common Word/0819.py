class Solution:
  def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
    banned = set(banned)
    words = re.findall(r'\w+', paragraph.lower())
    return collections.Counter(word for word in words if word not in banned).most_common(1)[0][0]
