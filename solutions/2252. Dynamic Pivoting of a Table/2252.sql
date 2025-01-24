CREATE PROCEDURE PivotProducts()
BEGIN
  # Override GROUP_CONCAT length which has a default limit of 1024.
  SET SESSION group_concat_max_len = 1000000;

  SELECT GROUP_CONCAT(
      DISTINCT CONCAT(
        'SUM(IF(store = "',
        store,
        '", price, NULL)) AS ',
        store
      )
    ) INTO @stmt
  FROM products;

  SET @query = CONCAT(
    'SELECT product_id, ', @stmt, ' '
    'FROM Products '
    'GROUP BY 1');

  PREPARE final_query FROM @query;
  EXECUTE final_query;
  DEALLOCATE PREPARE final_query;
END
