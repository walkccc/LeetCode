WITH
  UserCategories AS (
    SELECT DISTINCT
      ProductPurchases.user_id,
      ProductInfo.category
    FROM ProductPurchases
    INNER JOIN ProductInfo
      USING (product_id)
  ),
  CategoryPairs AS (
    SELECT
      UserCategories.user_id,
      LEAST(
        UserCategories.category,
        UserCategories2.category
      ) AS category1,
      GREATEST(
        UserCategories.category,
        UserCategories2.category
      ) AS category2
    FROM UserCategories
    INNER JOIN UserCategories AS UserCategories2
      ON (
        UserCategories.user_id = UserCategories2.user_id
        AND UserCategories.category < UserCategories2.category)
  ),
  PairCustomerCounts AS (
    SELECT
      category1,
      category2,
      COUNT(DISTINCT user_id) AS customer_count
    FROM CategoryPairs
    GROUP BY 1, 2
  )
SELECT
  category1,
  category2,
  customer_count
FROM PairCustomerCounts
WHERE customer_count >= 3
ORDER BY customer_count DESC, category1, category2;
