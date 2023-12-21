WITH
  TransactionsWithGroupId AS (
    SELECT
      customer_id,
      TO_DAYS(transaction_date) - ROW_NUMBER() OVER(
        PARTITION BY customer_id
        ORDER BY transaction_date
      ) AS group_id
    FROM Transactions
  ),
  RankedCustomers AS (
    SELECT
      customer_id,
      RANK() OVER(ORDER BY COUNT(*) DESC) AS `rank`
    FROM TransactionsWithGroupId
    GROUP BY customer_id, group_id
  )
SELECT customer_id
FROM RankedCustomers
WHERE `rank` = 1
ORDER BY 1;
