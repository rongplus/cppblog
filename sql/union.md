Appending Data via UNION(union all)
UNION Use Case
The UNION operator is used to combine the result sets of 2 or more SELECT statements. It removes duplicate rows between the various SELECT statements.
Each SELECT statement within the UNION must have the same number of fields in the result sets with similar data types.
Typically, the use case for leveraging the UNION command in SQL is when a user wants to pull together distinct values of specified columns that are spread across multiple tables. For example, a chef wants to pull together the ingredients and respective aisle across three separate meals that are maintained in different tables.
Details of UNION
There must be the same number of expressions in both SELECT statements.
The corresponding expressions must have the same data type in the SELECT statements. For example: expression1 must be the same data type in both the first and second SELECT statement.
Expert Tip
UNION removes duplicate rows.
UNION ALL does not remove duplicate rows.
Resources
The resource here on SQL UNIONs is helpful in understanding syntax and examples.


Appending Data via UNION Demonstration

SQL's two strict rules for appending data:

Both tables must have the same number of columns.
Those columns must have the same data types in the same order as the first table.
A common misconception is that column names have to be the same. Column names, in fact, don't need to be the same to append two tables but you will find that they typically are.

Pretreating Tables before doing a UNION