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
        printf("\n===== MAIN MENU =====\n1. Create New Account\n2. Login\n0. Exit\n\nEnter your choice: ");
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

    printf("\n===== CREATE NEW ACCOUNT =====\nEnter new username: ");
    if (scanf("%29s", username) != 1)
    {
        printf("Invalid input!\n");
        return;
    }

    fp = fopen(USER_FILE, "r");

    if (fp != NULL)
    {
        while (fscanf(fp, "%29s %29s", savedUsername, savedPassword) == 2)
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

    printf("\n===== ACCOUNT CREATED SUCCESSFULLY =====\nNew User: %s\nUser added successfully!\n", username);
}

int login(void)
{
    char username[30];
    char password[30];
    char savedUsername[30];
    char savedPassword[30];
    int found = 0;

    FILE *fp;

    printf("\n===== LOGIN =====\nUsername: ");
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
    while (fscanf(fp, "%29s %29s", savedUsername, savedPassword) == 2)
    {
        if (strcmp(username, savedUsername) == 0 && strcmp(password, savedPassword) == 0)
        {
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (found == 1)
    {
        printf("\nLogin successful!\nWelcome, %s!\n", username);
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
    printf("\n--- Burger Menu ---\n1. Classic Heritage - $12.50\n2. Smoky Orchard - $15.75\n3. Truffle Forager - $18.00\n4. Green Goddess - $14.20\n");
}

void pizza_menu(void)
{
    printf("\n--- Pizza Menu ---\n1. Rustic Margherita - $14.50\n2. Crimson Honey Pepperoni - $16.75\n3. Truffled Bianco - $18.00\n");
}

void sandwich_menu(void)
{
    printf("\n--- Sandwich Menu ---\n1. Napa Orchard Turkey - $13.50\n2. Chimichurri Tri-Tip - $16.20\n3. Italian Grinder - $14.80\n4. Chipotle Avocado Melt - $12.90\n5. Garden Caprese Panini - $12.50\n");
}

void fries_menu(void)
{
    printf("\n--- French Fries Menu ---\n1. Sea Salt & Rosemary - $5.25\n2. Garlic Parmesan Truffle - $7.50\n");
}

void drinks_menu(void)
{
    printf("\n--- Cold Drinks Menu ---\n1. Meyer Lemonade - $3.75\n2. Cold Brew Coffee - $4.50\n3. Hibiscus Berry Tea - $3.95\n4. Craft Cola - $3.50\n5. Spiced Ginger Beer - $4.20\n6. Cucumber Mint Water - $3.25\n");
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

    printf("\n===== ORDER FOOD =====\n1. Burger\n2. Pizza\n3. Sandwich\n4. French Fries\n5. Cold Drinks\n\nChoose category: ");

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

    printf("\n===== ORDER SUCCESSFUL =====\nOrder ID: %d\nItem: %s\nQuantity: %d\nUnit Price: $%.2f\nTotal: $%.2f\nStatus: Processing\n", orders[orderCount].order_id, name, quantity, price, price * quantity);
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
            printf("\nOrder ID: %d\nItem: %s\nQuantity: %d\nPrice: $%.2f\nStatus: Processing\n", orders[i].order_id, orders[i].item_name, orders[i].quantity, orders[i].price * orders[i].quantity);
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
    printf("\n===== CANCEL ORDER =====\n\n--- CURRENT PROCESSING ORDERS ---\nOrder ID] [Item Name] [Quantity]\n");

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
        if (orders[i].order_id == id && orders[i].active == 1)
        {
            orders[i].active = 0;
            printf("\nOrder ID %d cancelled successfully!\n", id);
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
        printf("\n===== CUSTOMER DASHBOARD =====\n1. Order Food\n2. View Processing Orders\n3. Cancel Order\n4. Total Bill to Pay\n5. Logout\n\nEnter your choice: ");

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