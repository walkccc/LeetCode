class Solution:
  def numUniqueEmails(self, emails: List[str]) -> int:
    seen = set()

    for email in emails:
      local, domain = email.split('@')
      local = local.split('+')[0].replace('.', '')
      seen.add(local + '@' + domain)

    return len(seen)
