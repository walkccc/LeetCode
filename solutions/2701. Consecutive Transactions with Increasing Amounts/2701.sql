WITH
  IncreasingTransactions AS (
    SELECT
      Curr.customer_id,
      Curr.transaction_date
    FROM Transactions AS Curr
    LEFT JOIN Transactions AS Next
      USING (customer_id)
    WHERE
      Curr.amount < Next.amount
      AND DATEDIFF(Next.transaction_date, Curr.transaction_date) = 1
  ),
  IncreasingTransactionsWithGroupId AS (
    SELECT
      *,
      TO_DAYS(transaction_date) - ROW_NUMBER() OVER(
        PARTITION BY customer_id
        ORDER BY transaction_date
      ) AS group_id
    FROM IncreasingTransactions
  ),
  IncreasingTransactionsWithCountDays AS (
    SELECT
      customer_id,
      MIN(transaction_date) AS consecutive_start,
      COUNT(*) AS count_days
    FROM IncreasingTransactionsWithGroupId
    GROUP BY customer_id, group_id
  )
SELECT
  customer_id,
  consecutive_start,
  DATE_ADD(consecutive_start, INTERVAL count_days DAY) AS consecutive_end
FROM IncreasingTransactionsWithCountDays
WHERE count_days >= 2
ORDER BY 1;
