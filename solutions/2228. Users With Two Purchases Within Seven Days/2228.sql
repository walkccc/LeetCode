SELECT DISTINCT First.user_id
FROM Purchases AS First
INNER JOIN purchases AS Second
  USING (user_id)
WHERE
  First.purchase_id != Second.purchase_id
  AND First.purchase_date <= Second.purchase_date
  AND DATEDIFF(Second.purchase_date, First.purchase_date) <= 7
ORDER BY 1;
