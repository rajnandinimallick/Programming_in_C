#include <stdio.h>
#include <string.h>
#define MAX_ORDERS 100
#define USER_FILE "users.txt"

struct order
{
    int order_id;
    char item_name[50];
    float price;
    int quantity;
    int active;
};

struct order orders[MAX_ORDERS];
int orderCount = 0;

void registerUser(void);
int login(void);
void burger_menu(void);
void pizza_menu(void);
void sandwich_menu(void);
void fries_menu(void);
void drinks_menu(void);
void orderFood(void);
void view_orders(void);
void cancelOrder(void);
void customerMenu(void);
void total_bill_to_pay(void);

int main(void)
{
    int choice;

    printf("===== WELCOME TO RIZA'S RESTAURANT =====\n");

    while (1)
    {
        printf("\n===== MAIN MENU =====\n");
        printf("1. Create New Account\n");
        printf("2. Login\n");
        printf("0. Exit\n");

        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Enter a number.\n");

            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;

            continue;
        }

        switch (choice)
        {
        case 1:
            registerUser();
            break;

        case 2:
            if (login())
            {
                customerMenu();
            }
            break;

        case 0:
            printf("\nThank you for visiting!\n");
            return 0;

        default:
            printf("\nInvalid choice! Please select 0-2.\n");
        }
    }

    return 0;
}

void registerUser(void)
{
    char username[30];
    char password[30];

    char savedUsername[30];
    char savedPassword[30];

    FILE *fp;

    printf("\n===== CREATE NEW ACCOUNT =====\n");

    printf("Enter new username: ");
    if (scanf("%29s", username) != 1)
    {
        printf("Invalid input!\n");
        return;
    }

    fp = fopen(USER_FILE, "r");

    if (fp != NULL)
    {
        while (fscanf(fp, "%29s %29s",
                      savedUsername, savedPassword) == 2)
        {
            if (strcmp(username, savedUsername) == 0)
            {
                printf("\nUsername already exists!\n");
                fclose(fp);
                return;
            }
        }

        fclose(fp);
    }

    printf("Enter new password: ");
    if (scanf("%29s", password) != 1)
    {
        printf("Invalid input!\n");
        return;
    }

    fp = fopen(USER_FILE, "a");

    if (fp == NULL)
    {
        printf("\nError opening user file!\n");
        return;
    }

    fprintf(fp, "%s %s\n", username, password);

    fclose(fp);

    printf("\n===== ACCOUNT CREATED SUCCESSFULLY =====\n");
    printf("New User: %s\n", username);
    printf("User added successfully!\n");
}

int login(void)
{
    char username[30];
    char password[30];

    char savedUsername[30];
    char savedPassword[30];

    int found = 0;

    FILE *fp;

    printf("\n===== LOGIN =====\n");

    printf("Username: ");
    if (scanf("%29s", username) != 1)
    {
        printf("Invalid input!\n");
        return 0;
    }

    printf("Password: ");
    if (scanf("%29s", password) != 1)
    {
        printf("Invalid input!\n");
        return 0;
    }

    fp = fopen(USER_FILE, "r");

    if (fp == NULL)
    {
        printf("\nNo registered accounts found!\n");
        return 0;
    }

    while (fscanf(fp, "%29s %29s",
                  savedUsername, savedPassword) == 2)
    {
        if (strcmp(username, savedUsername) == 0 &&
            strcmp(password, savedPassword) == 0)
        {
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (found == 1)
    {
        printf("\nLogin successful!\n");
        printf("Welcome, %s!\n", username);
        return 1;
    }
    else
    {
        printf("\nIncorrect username or password!\n");
        return 0;
    }
}

void burger_menu(void)
{
    printf("\n--- Burger Menu ---\n");
    printf("1. Classic Heritage - $12.50\n");
    printf("2. Smoky Orchard - $15.75\n");
    printf("3. Truffle Forager - $18.00\n");
    printf("4. Green Goddess - $14.20\n");
}

void pizza_menu(void)
{
    printf("\n--- Pizza Menu ---\n");
    printf("1. Rustic Margherita - $14.50\n");
    printf("2. Crimson Honey Pepperoni - $16.75\n");
    printf("3. Truffled Bianco - $18.00\n");
}

void sandwich_menu(void)
{
    printf("\n--- Sandwich Menu ---\n");
    printf("1. Napa Orchard Turkey - $13.50\n");
    printf("2. Chimichurri Tri-Tip - $16.20\n");
    printf("3. Italian Grinder - $14.80\n");
    printf("4. Chipotle Avocado Melt - $12.90\n");
    printf("5. Garden Caprese Panini - $12.50\n");
}

void fries_menu(void)
{
    printf("\n--- French Fries Menu ---\n");
    printf("1. Sea Salt & Rosemary - $5.25\n");
    printf("2. Garlic Parmesan Truffle - $7.50\n");
}

void drinks_menu(void)
{
    printf("\n--- Cold Drinks Menu ---\n");
    printf("1. Meyer Lemonade - $3.75\n");
    printf("2. Cold Brew Coffee - $4.50\n");
    printf("3. Hibiscus Berry Tea - $3.95\n");
    printf("4. Craft Cola - $3.50\n");
    printf("5. Spiced Ginger Beer - $4.20\n");
    printf("6. Cucumber Mint Water - $3.25\n");
}

void total_bill_to_pay(void)
{
    int i;
    float total = 0;

    printf("\n===== TOTAL BILL TO PAY =====\n");

    for (i = 0; i < orderCount; i++)
    {
        if (orders[i].active == 1)
        {
            total += orders[i].price * orders[i].quantity;
        }
    }

    printf("Total Bill: $%.2f\n", total);
}

void orderFood(void)
{
    int category, item, quantity;
    char name[50];
    float price;

    if (orderCount >= MAX_ORDERS)
    {
        printf("\nOrder limit reached!\n");
        return;
    }

    printf("\n===== ORDER FOOD =====\n");
    printf("1. Burger\n");
    printf("2. Pizza\n");
    printf("3. Sandwich\n");
    printf("4. French Fries\n");
    printf("5. Cold Drinks\n");

    printf("\nChoose category: ");

    if (scanf("%d", &category) != 1)
    {
        printf("Invalid input!\n");

        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;

        return;
    }

    switch (category)
    {
    case 1:
        burger_menu();
        break;

    case 2:
        pizza_menu();
        break;

    case 3:
        sandwich_menu();
        break;

    case 4:
        fries_menu();
        break;

    case 5:
        drinks_menu();
        break;

    default:
        printf("Invalid category!\n");
        return;
    }

    printf("\nSelect item number: ");

    if (scanf("%d", &item) != 1)
    {
        printf("Invalid input!\n");

        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;

        return;
    }

    switch (category)
    {
    case 1:
        switch (item)
        {
        case 1:
            strcpy(name, "Classic Heritage");
            price = 12.50;
            break;

        case 2:
            strcpy(name, "Smoky Orchard");
            price = 15.75;
            break;

        case 3:
            strcpy(name, "Truffle Forager");
            price = 18.00;
            break;

        case 4:
            strcpy(name, "Green Goddess");
            price = 14.20;
            break;

        default:
            printf("Invalid burger choice!\n");
            return;
        }
        break;

    case 2:
        switch (item)
        {
        case 1:
            strcpy(name, "Rustic Margherita");
            price = 14.50;
            break;

        case 2:
            strcpy(name, "Crimson Honey Pepperoni");
            price = 16.75;
            break;

        case 3:
            strcpy(name, "Truffled Bianco");
            price = 18.00;
            break;

        default:
            printf("Invalid pizza choice!\n");
            return;
        }
        break;

    case 3:
        switch (item)
        {
        case 1:
            strcpy(name, "Napa Orchard Turkey");
            price = 13.50;
            break;

        case 2:
            strcpy(name, "Chimichurri Tri-Tip");
            price = 16.20;
            break;

        case 3:
            strcpy(name, "Italian Grinder");
            price = 14.80;
            break;

        case 4:
            strcpy(name, "Chipotle Avocado Melt");
            price = 12.90;
            break;

        case 5:
            strcpy(name, "Garden Caprese Panini");
            price = 12.50;
            break;

        default:
            printf("Invalid sandwich choice!\n");
            return;
        }
        break;

    case 4:
        switch (item)
        {
        case 1:
            strcpy(name, "Sea Salt & Rosemary");
            price = 5.25;
            break;

        case 2:
            strcpy(name, "Garlic Parmesan Truffle");
            price = 7.50;
            break;

        default:
            printf("Invalid fries choice!\n");
            return;
        }
        break;

    case 5:
        switch (item)
        {
        case 1:
            strcpy(name, "Meyer Lemonade");
            price = 3.75;
            break;

        case 2:
            strcpy(name, "Cold Brew Coffee");
            price = 4.50;
            break;

        case 3:
            strcpy(name, "Hibiscus Berry Tea");
            price = 3.95;
            break;

        case 4:
            strcpy(name, "Craft Cola");
            price = 3.50;
            break;

        case 5:
            strcpy(name, "Spiced Ginger Beer");
            price = 4.20;
            break;

        case 6:
            strcpy(name, "Cucumber Mint Water");
            price = 3.25;
            break;

        default:
            printf("Invalid drink choice!\n");
            return;
        }
        break;
    }

    printf("Enter quantity: ");

    if (scanf("%d", &quantity) != 1)
    {
        printf("Invalid input!\n");

        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;

        return;
    }

    if (quantity <= 0)
    {
        printf("Invalid quantity!\n");
        return;
    }

    orders[orderCount].order_id = orderCount + 1;
    strcpy(orders[orderCount].item_name, name);
    orders[orderCount].price = price;
    orders[orderCount].quantity = quantity;
    orders[orderCount].active = 1;

    printf("\n===== ORDER SUCCESSFUL =====\n");
    printf("Order ID: %d\n", orders[orderCount].order_id);
    printf("Item: %s\n", name);
    printf("Quantity: %d\n", quantity);
    printf("Unit Price: $%.2f\n", price);
    printf("Total: $%.2f\n", price * quantity);
    printf("Status: Processing\n");

    orderCount++;

    total_bill_to_pay();
}

void view_orders(void)
{
    int i;
    int found = 0;

    printf("\n===== PROCESSING ORDERS =====\n");

    for (i = 0; i < orderCount; i++)
    {
        if (orders[i].active == 1)
        {
            printf("\nOrder ID: %d\n", orders[i].order_id);
            printf("Item: %s\n", orders[i].item_name);
            printf("Quantity: %d\n", orders[i].quantity);
            printf("Price: $%.2f\n",
                   orders[i].price * orders[i].quantity);
            printf("Status: Processing\n");

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("\nNo processing orders found.\n");
    }
}

void cancelOrder(void)
{
    int id;
    int i;
    int found = 0;

    printf("\n===== CANCEL ORDER =====\n");

    printf("\n--- CURRENT PROCESSING ORDERS ---\n");
    printf("[Order ID] [Item Name] [Quantity]\n");

    for (i = 0; i < orderCount; i++)
    {
        if (orders[i].active == 1)
        {
            printf("[%d] [%s] [%d]\n",
                   orders[i].order_id,
                   orders[i].item_name,
                   orders[i].quantity);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("\nNo processing orders available to cancel.\n");
        total_bill_to_pay();
        return;
    }

    printf("\nEnter Order ID to cancel: ");

    if (scanf("%d", &id) != 1)
    {
        printf("Invalid input!\n");

        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;

        return;
    }

    for (i = 0; i < orderCount; i++)
    {
        if (orders[i].order_id == id &&
            orders[i].active == 1)
        {
            orders[i].active = 0;

            printf("\nOrder ID %d cancelled successfully!\n", id);

            /* UPDATE TOTAL BILL */
            total_bill_to_pay();

            return;
        }
    }

    printf("\nOrder not found or already cancelled!\n");
}

void customerMenu(void)
{
    int choice;

    while (1)
    {
        printf("\n===== CUSTOMER DASHBOARD =====\n");
        printf("1. Order Food\n");
        printf("2. View Processing Orders\n");
        printf("3. Cancel Order\n");
        printf("4. Total Bill to Pay\n");
        printf("5. Logout\n");

        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Enter a number.\n");

            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;

            continue;
        }

        switch (choice)
        {
        case 1:
            orderFood();
            break;

        case 2:
            view_orders();
            break;

        case 3:
            cancelOrder();
            break;

        case 4:
            total_bill_to_pay();
            break;

        case 5:
            printf("\nLogging out...\n");
            return;

        default:
            printf("\nInvalid choice!\n");
        }
    }
}
