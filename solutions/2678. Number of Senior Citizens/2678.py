class Solution:
  def countSeniors(self, details: List[str]) -> int:
    return sum(int(detail[11:13]) > 60 for detail in details)
