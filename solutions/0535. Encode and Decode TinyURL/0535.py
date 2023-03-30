class Codec:
  alphabets = string.ascii_letters + '0123456789'
  urlToCode = {}
  codeToUrl = {}

  def encode(self, longUrl: str) -> str:
    while longUrl not in self.urlToCode:
      code = ''.join(random.choice(self.alphabets) for _ in range(6))
      if code not in self.codeToUrl:
        self.codeToUrl[code] = longUrl
        self.urlToCode[longUrl] = code
    return 'http://tinyurl.com/' + self.urlToCode[longUrl]

  def decode(self, shortUrl: str) -> str:
    return self.codeToUrl[shortUrl[-6:]]
