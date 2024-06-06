SELECT Emails.user_id
FROM Emails
INNER JOIN Texts
  USING (email_id)
WHERE
  Texts.signup_action = 'Verified'
  AND DATEDIFF(Texts.action_date, Emails.signup_date) = 1
ORDER BY 1;
