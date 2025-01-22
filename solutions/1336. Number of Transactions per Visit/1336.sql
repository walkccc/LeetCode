WITH
  Users AS (
    SELECT
      Visits.user_id,
      Visits.visit_date,
      COUNT(Transactions.transaction_date) AS transaction_count
    FROM Visits
    LEFT JOIN Transactions
      ON (
        Visits.user_id = Transactions.user_id
        AND Visits.visit_date = Transactions.transaction_date)
    GROUP BY 1, 2
  ),
  RowNumbers AS (
    SELECT ROW_NUMBER() OVER() AS `row_number`
    FROM Transactions
    UNION ALL
    SELECT 0
  )
SELECT
  RowNumbers.`row_number` AS transactions_count,
  COUNT(Users.user_id) AS visits_count
FROM RowNumbers
LEFT JOIN Users
  ON (RowNumbers.`row_number` = Users.transaction_count)
WHERE RowNumbers.`row_number` <= (
    SELECT MAX(transaction_count) FROM Users
  )
GROUP BY 1
ORDER BY 1;
