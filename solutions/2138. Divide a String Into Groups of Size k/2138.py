class Solution:
  def divideString(self, s: str, k: int, fill: chr) -> List[str]:
    return [
        s[i:] + fill * (i + k - len(s)) if i + k > len(s)
        else s[i:i + k]
        for i in range(0, len(s), k)
    ]
