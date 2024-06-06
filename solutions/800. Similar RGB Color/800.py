class Solution:
  def similarRGB(self, color: str) -> str:
    kShorthands = ['00', '11', '22', '33', '44', '55', '66', '77', '88', '99',
                   'aa', 'bb', 'cc', 'dd', 'ee', 'ff']
    ans = ['#']

    for i in range(1, len(color), 2):
      currValue = int(color[i:i + 2], 16)
      closestShorthand = min(kShorthands,
                             key=lambda shorthand: (currValue - int(shorthand, 16))**2)
      ans.append(closestShorthand)

    return ''.join(ans)
