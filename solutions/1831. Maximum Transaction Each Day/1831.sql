WITH
  RankedTransactions AS (
    SELECT
      *,
      RANK() OVER(
        PARTITION BY DATE(day)
        ORDER BY amount DESC
      ) AS `rank`
    FROM Transactions
  )
SELECT transaction_id
FROM RankedTransactions
WHERE `rank` = 1
ORDER BY 1;
