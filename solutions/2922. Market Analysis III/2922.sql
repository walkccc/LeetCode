WITH
  Sellers AS(
    SELECT
      Users.seller_id,
      COUNT(DISTINCT Orders.item_id) AS num_items
    FROM Users
    INNER JOIN Orders
      USING (seller_id)
    INNER JOIN Items
      USING (item_id)
    WHERE Items.item_brand != Users.favorite_brand
    GROUP BY 1
  ),
  RankedSellers AS (
    SELECT
      seller_id,
      num_items,
      RANK() OVER(ORDER BY num_items DESC) AS `rank`
    FROM Sellers
  )
SELECT seller_id, num_items
FROM RankedSellers
WHERE `rank` = 1;
