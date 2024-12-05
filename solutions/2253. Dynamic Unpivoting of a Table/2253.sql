CREATE PROCEDURE UnpivotProducts()
BEGIN
  # Override GROUP_CONCAT length which has a default limit of 1024.
  SET SESSION group_concat_max_len = 1000000;

  SELECT GROUP_CONCAT(
      CONCAT(
        'SELECT product_id, "',
        `column_name`, '" AS store, ',
        `column_name`, ' AS price ',
        'FROM products ',
        'WHERE ',
        `column_name`, ' IS NOT NULL'
      ) SEPARATOR ' UNION '
    ) INTO @stmt
  FROM `information_schema`.`columns`
  WHERE
    `table_schema` = 'test'
    AND `table_name` = 'Products'
    AND `column_name` != 'product_id';

  PREPARE final_query FROM @stmt;
  EXECUTE final_query;
  DEALLOCATE PREPARE final_query;
END
