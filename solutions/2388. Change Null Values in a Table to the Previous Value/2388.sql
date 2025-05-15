WITH
  CoffeeShoptWithRowNumber AS (
    SELECT *, ROW_NUMBER() OVER() AS `row_number`
    FROM CoffeeShop
  ),
  CoffeeShoptWithRowNumberAndGroupId AS (
    SELECT
      *,
      SUM(drink IS NOT NULL) OVER(
        ORDER BY `row_number`
      ) AS group_id
    FROM CoffeeShoptWithRowNumber
  )
SELECT
  id,
  FIRST_VALUE(drink) OVER(
    PARTITION by group_id
    ORDER BY `row_number`
  ) AS drink
FROM CoffeeShoptWithRowNumberAndGroupId;
