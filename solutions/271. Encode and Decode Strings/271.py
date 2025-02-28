class Codec:
  def encode(self, strs: list[str]) -> str:
    """Encodes a list of strings to a single string."""
    return ''.join(str(len(s)) + '/' + s for s in strs)

  def decode(self, s: str) -> list[str]:
    """Decodes a single string to a list of strings."""
    decoded = []

    i = 0
    while i < len(s):
      slash = s.find('/', i)
      length = int(s[i:slash])
      i = slash + length + 1
      decoded.append(s[slash + 1:i])

    return decoded
