# """
# This is HtmlParser's API interface.
# You should not implement it, or speculate about its implementation
# """
# Class HtmlParser(object):
#   def getUrls(self, url: str) -> list[str]:

class Solution:
  def crawl(self, startUrl: str, htmlParser: 'HtmlParser') -> list[str]:
    q = collections.deque([startUrl])
    seen = {startUrl}
    hostname = startUrl.split('/')[2]

    while q:
      currUrl = q.popleft()
      for url in htmlParser.getUrls(currUrl):
        if url in seen:
          continue
        if hostname in url:
          q.append(url)
          seen.add(url)

    return seen
