/*
SQL Script produced by Daronhil Mauricette
For Exercise 4
COMP23111
z20375dm
*/
SET ECHO ON;
SPOOL EX04-z20375dm.log;

START /opt/info/courses/COMP23111/drop-Eclectic-Ecommerce-tables.sql
START /opt/info/courses/COMP23111/create-Eclectic-Ecommerce-tables.sql
START /opt/info/courses/COMP23111/populate-Eclectic-Ecommerce-tables.sql


--(1)(a)
CREATE VIEW CustomersWithCarts AS
SELECT DISTINCT firstName, lastName
FROM customerInfo, orderCartInfo, lineItems
WHERE customerInfo.loginName = orderCartInfo.customerID AND orderPrice > 0;

SELECT * FROM CustomersWithCarts;

--(1)(b)

CREATE VIEW ItemView AS
SELECT DISTINCT itemType.itemNum, category.categoryID, inventoryItem.qtyInstock
FROM inventoryItem, category, itemType
WHERE itemType.belongsTo = category.categoryID
AND inventoryItem.itemNum = itemType.itemNum;

SELECT * FROM ItemView;

--(1)(c)

CREATE VIEW CustomerOrderPrices AS
SELECT DISTINCT customerInfo.loginName, customerInfo.firstName, 
customerInfo.lastName, orderCartInfo.orderCartID, lineItems.orderPrice
FROM customerInfo, orderCartInfo, lineItems
WHERE customerInfo.loginName = orderCartInfo.customerID
AND lineItems.orderCartID = orderCartInfo.orderCartID;

SELECT * FROM CustomerOrderPrices;

--(1)(d)
CREATE VIEW CustomerTotalOrders AS
SELECT customerInfo.loginName, customerInfo.firstName, 
customerInfo.lastName, SUM (lineItems.qtyOrdered) AS "Total Orders" 
FROM customerInfo, lineItems, orderCartInfo
WHERE customerInfo.loginName = orderCartInfo.customerID
AND orderCartInfo.orderCartID = lineItems.orderCartID
GROUP BY customerInfo.firstName, customerInfo.lastName, customerInfo.loginName;

SELECT * FROM CustomerTotalOrders;

--(1)(e)
CREATE VIEW CustomerTotalCarts AS
SELECT customerInfo.loginName, COUNT(orderCartInfo.orderCartId) AS "Total", 
CASE
	WHEN COUNT(orderCartInfo.orderCartId) > 2 THEN 'BR-1 violated'
	ELSE 'BR-1 satisfied' 
END AS "BusinessRule1"
FROM customerInfo
JOIN orderCartInfo ON customerInfo.loginName = orderCartInfo.customerID
GROUP BY customerInfo.loginName;

SELECT * FROM CustomerTotalCarts;


--(1)(f)
SELECT itemNum, itemSize, itemColor
FROM 
(SELECT itemNum, itemSize, itemColor,
CASE
WHEN "Price_Check" <= 1 THEN 'BR-2 violated'
ELSE 'BR-2 satisfied'
END AS "BusinessRule2" 
FROM 
(SELECT itemNum, itemSize, itemColor,
COUNT(itemNum) AS "Price_Check"
FROM inventoryItem
GROUP BY itemNum, itemSize, itemColor))
WHERE BusinessRule2 = 'BR-2 violated';

--(1)(g)
COLUMN PICTURE FORMAT a11
SELECT * 
FROM itemType;
CREATE VIEW MinimumPrice AS 
SELECT MIN(price) AS min FROM itemType;

CREATE TRIGGER PriceCheck
BEFORE INSERT OR UPDATE OF price 
ON itemType FOR EACH ROW 
DECLARE Minimum_Price FLOAT;

BEGIN
SELECT MIN(min) INTO Minimum_Price FROM MinimumPrice;
IF :new.price > (Minimum_Price * 4) THEN RAISE_APPLICATION_ERROR(-20107, 
'Price of Item Exceeds the Set Limit!');
END IF;
END; 
/

--Tests for (1)(g)
SELECT * FROM itemType;

INSERT INTO itemType VALUES('A5', 'The September', 
'xxxx', 790.67, 'P');

SELECT * FROM itemType;

UPDATE itemType SET price = 200
WHERE itemNum = 'C2';

SELECT * FROM itemType;




SPOOL OFF;
