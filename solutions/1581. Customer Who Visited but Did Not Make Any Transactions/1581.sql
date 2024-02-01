SELECT
  Visits.customer_id,
  COUNT(Visits.visit_id) AS count_no_trans
FROM Visits
LEFT JOIN Transactions
  USING (visit_id)
WHERE Transactions.transaction_id IS NULL
GROUP BY 1;
