# projecthub
A collection of personal projects, showcasing my skills and interests in programming and software development.
############################# MY 1ST PROJECT###############
*********************Supermarket Inventory Management System****************************
This C++ project simulates a basic supermarket inventory and billing system. It allows users to add items to inventory and manage sales. The program provides an interactive console interface for entering item details, rates, and quantities.

****Features********
Add Items to Inventory: Users can add new items, specifying the item name, rate, and quantity. The details are then saved to a file named ItemInventory.txt.

**Order Items:** Users can order items by specifying the item name and quantity. The system checks for item availability and updates the inventory accordingly. It also generates a receipt for the purchase, saving the details to Reciept.txt.

**View Receipts:** Users can view the receipt for their purchase, which includes the name, rate, chosen quantity of items, and the total bill.

**How to Use**
Run the Program: Execute the program to start the supermarket inventory management system.

**Add Items:** Choose the option to add items to inventory. Enter the item name, rate, and quantity.

**Buy Items:** Choose the option to buy items. Enter the item name and quantity. If the item is available, it will be added to your receipt, and the inventory will be updated.

**View Receipt**: After completing the purchases, you can view the receipt, which shows the total amount payable.

**Files**
*ItemInventory.txt:* Stores the details of the items in the inventory.

*Reciept.txt:* Stores the details of the purchases and the total bill.

********************Example Usage********************
cpp
*WELCOME TO THE SUPERMARKET
*****ENJOY YOUR SHOPPING
1. ADD ITEM IN INVENTORY.
2. BUY ITEM.
CHOOSE (1 OR 2):

-> ADD ITEM:
Enter Item name: Apple
Enter rate of Item: 50
Enter quantity of Item: 100
*ITEM ADDED SUCCESSFULLY*

-> BUY ITEM:
Enter item name: Apple
Enter quantity of item: 10
YOUR TOTAL BILL: 500
*******Requirements*******
A C++ compiler
