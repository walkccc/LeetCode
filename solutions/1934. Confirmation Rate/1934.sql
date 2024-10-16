SELECT
  Signups.user_id,
  IFNULL(ROUND(AVG(Confirmations.action = 'confirmed'), 2), 0) AS confirmation_rate
FROM Signups
LEFT JOIN Confirmations
  USING (user_id)
GROUP BY 1;
