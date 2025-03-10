WITH
  RankedCategoriesPerCustomer AS (
    SELECT
      Transactions.customer_id,
      Products.category,
      RANK() OVER(
        PARTITION BY Transactions.customer_id
        ORDER BY COUNT(Products.category) DESC,
          MAX(Transactions.transaction_date) DESC
      ) AS `rank`
    FROM Transactions
    INNER JOIN Products
      USING (product_id)
    GROUP BY 1, 2
  ),
  TransactionsMetadata AS (
    SELECT
      Transactions.customer_id,
      ROUND(SUM(Transactions.amount), 2) AS total_amount,
      COUNT(Transactions.transaction_id) AS transaction_count,
      COUNT(DISTINCT Products.category) AS unique_categories,
      ROUND(AVG(Transactions.amount), 2) AS avg_transaction_amount,
      RankedCategoriesPerCustomer.category AS top_category
    FROM Transactions
    INNER JOIN Products
      USING (product_id)
    INNER JOIN RankedCategoriesPerCustomer
      USING (customer_id)
    WHERE RankedCategoriesPerCustomer.`rank` = 1
    GROUP BY 1
  )
SELECT
  *,
  ROUND(transaction_count * 10 + total_amount / 100, 2) AS loyalty_score
FROM TransactionsMetadata
ORDER BY loyalty_score DESC, customer_id;
