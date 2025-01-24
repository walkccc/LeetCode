class Solution:
  def capitalizeTitle(self, title: str) -> str:
    return ' '.join(s.lower() if len(s) < 3
                    else s.capitalize() for s in title.split())
