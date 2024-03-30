#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ORDERS 100

int bill = 0, numoforders = 0, grand = 0;
int grandtotal = 0;

struct CartItem {
    char itemName[50];
    int quantity;
    int price;
};

struct CartItem cart[MAX_ORDERS];

void welcome();
void mainmenu();
void menu();
void submenu(int n);
void coffeeSubMenu();
void beverageSubMenu();
void donutSubMenu();
void cookieSubMenu();
void pastrySubMenu();
void iceCreamSubMenu();
int adminpanel(int bills, int numberoforders, int grand, int grandtotal);
int processOrder(int category, int item, int prices[], const char *categoryName);
void viewCart();

int main() {
    welcome();
    mainmenu();
    return 0;
}

void welcome() {
    printf("\n");
    printf("\t\t\t\t\t ///////////////////////////////////////\t\t\t\t\t");
    printf("\n\t\t\t\t\t//                                   //");
    printf("\n\t\t\t\t       //  WELCOME TO THE JANU CHAI WALA    // \t\t\t\t\t\n");
    printf("\t\t\t\t      //                                   //\n");
    printf("\t\t\t\t     /////////////////////////////////////// \t\t\t\t");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t\t\t\t****************");
    printf("\n\t\t\t\t\t\t*\t\t*****");
    printf("\n\t\t\t\t\t\t*\t\t*    *");
    printf("\n\t\t\t\t\t\t*\t\t*    *");
    printf("\n\t\t\t\t\t\t*\t\t*    *");
    printf("\n\t\t\t\t\t\t*\t\t*****");
    printf("\n\t\t\t\t\t\t *             *\t");
    printf("\n\t\t\t\t\t\t  ************\t");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
}
void mainmenu() {
    
    int n;
     printf("\t\t\t\t\tPress 1 to go to the Customer Panel");
    printf("\n");
    printf("\n\t\t\t\t\tPress 2 to track orders for Admin Panel ");
    printf("\n");
    printf("\n\t\t\t\t\tPress 0 to exit ");

    printf("\n");
    printf("\n");
    scanf("%d", &n);
    if (n == 1) {
        system("cls");
        menu();
    }
    if(n==2)
    {
        system("cls");
        adminpanel(bill, numoforders, grand, grandtotal);
    }
    if(n==0)
    {
        system("cls");
        exit(0);
    } 
    else {
        printf("Invalid input. Please enter a number between 0 to 2.\n\n");
        mainmenu();
    }
}

void menu() {
    int n;
    printf("\nCHOOSE THE MENU CATEGORY:");
    printf("\n");
    printf("\n \t\t\t\t      ===========================  \t\t\t\t\t");
    printf("\n\t\t\t\t      ||          MENU         ||   \t\t\t\t\t\n");
    printf(" \t\t\t\t      ===========================  \t\t\t\t\t\n");
    printf("\n\n");

    printf("\n\t\t\t\t\t\t1. Coffees\n");
    printf("\n\t\t\t\t\t\t2. Beverages\n");
    printf("\n\t\t\t\t\t\t3. Donuts\n");
    printf("\n\t\t\t\t\t\t4. Cookies\n");
    printf("\n\t\t\t\t\t\t5. Pastries\n");
    printf("\n\t\t\t\t\t\t6. Ice Creams\n");
    printf("\n\t\t\t\t\n");

    printf("ENTER NUMBER ACCORDING TO YOUR CHOICE:\n");
    scanf("%d", &n);
    submenu(n);
}

void submenu(int n) {
    int category,i;
    const char *categoryName;  // Added to store the category name
    int itemPrices[8];

    switch (n) {
        case 1:
            category = 0;  // Coffee
            categoryName = "Coffees";
            int coffeePrices[] = {350, 400, 380, 450, 420, 480, 400, 450};
            for ( i = 0; i < 8; i++) {
                itemPrices[i] = coffeePrices[i];
            }
            coffeeSubMenu();
            break;
        case 2:
            category = 1;  // Beverages
            categoryName = "Beverages";
            int beveragePrices[] = {200, 250, 180, 300, 280, 320, 150, 220};
            for ( i = 0; i < 8; i++) {
                itemPrices[i] = beveragePrices[i];
            }
            beverageSubMenu();
            break;
        case 3:
            category = 2;  // Donuts
            categoryName = "Donuts";
            int donutPrices[] = {60, 70, 80, 75, 90, 65, 85, 80};
            for ( i = 0; i < 8; i++) {
                itemPrices[i] = donutPrices[i];
            }
            donutSubMenu();
            break;
        case 4:
            category = 3;  // Cookies
            categoryName = "Cookies";
            int cookiePrices[] = {40, 45, 50, 55, 45, 50, 55, 50};
            for ( i = 0; i < 8; i++) {
                itemPrices[i] = cookiePrices[i];
            }
            cookieSubMenu();
            break;
        case 5:
            category = 4;  // Pastries
            categoryName = "Pastries";
            int pastryPrices[] = {80, 85, 90, 100, 95};
            for ( i = 0; i < 5; i++) {
                itemPrices[i] = pastryPrices[i];
            }
            pastrySubMenu();
            break;
        case 6:
            category = 5;  // Ice Creams
            categoryName = "Ice Creams";
            int iceCreamPrices[] = {50, 60, 55, 65, 70, 75, 80};
            for ( i = 0; i < 7; i++) {
                itemPrices[i] = iceCreamPrices[i];
            }
            iceCreamSubMenu();
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }

    int item;
    printf("Enter the item number to order (1-8): ");
    scanf("%d", &item);

    bill = processOrder(category, item, itemPrices, categoryName);
    viewCart();

    int orderAgain;
    printf("\nWant to order again?\nPress 1 for yes\nPress 0 for no\n");
    scanf("%d", &orderAgain);

    if (orderAgain == 1) {
        menu();
    } else if (orderAgain == 0) {
        system("cls");
        printf("\n\n\t\t\t\t******  Thank you for choosing us!  *****\n");
        printf("\n");
        printf("\n");
        printf("\n");

        mainmenu();
    } else {
        printf("Invalid choice\n");
    }
}
void coffeeSubMenu() {
    printf("\n\t\t\t\t COFFEE NAMES              PRICE LIST\t\t\t\t\t\n");
    printf("\t\t\t\t ************              **********\t\t\t\t\t\n");
    printf("\n\t\t\t\t(1) Americano                 350/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(2) Latte                     400/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(3) Espresso                  380/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(4) Irish                     450/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(5) Affogato                  420/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(6) Mochachino                480/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(7) Macchiato                 400/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(8) Flat White                450/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(9) GO BACK TO MAIN MENU           \t\t\t\t\t\n\n\n");
}
void beverageSubMenu() {
    printf("\n\t\t\t\t BEVERAGE NAMES            PRICE LIST\t\t\t\t\t\n");
    printf("\t\t\t\t **************            **********\t\t\t\t\t\n");
    printf("\n\t\t\t\t(1) Fruit Punch              200/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(2) Iced Tea                 250/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(3) Lemonade                 180/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(4) Mojito                   300/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(5) Smoothie                 280/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(6) Hot Chocolate            320/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(7) Green Tea                150/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(8) Mango Lassi              220/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(9) GO BACK TO MAIN MENU          \t\t\t\t\t\n\n\n");
}

void donutSubMenu() {
    printf("\n\t\t\t\t  DONUT NAMES               PRICE LIST\t\t\t\t\t\n");
    printf("\t\t\t\t ************               **********\t\t\t\t\t\n");
    printf("\n\t\t\t\t(1) Glazed Donut             60/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(2) Chocolate Donut          70/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(3) Strawberry Donut         80/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(4) Vanilla Donut            75/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(5) Maple Bacon Donut        90/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(6) Jelly Donut              65/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(7) Cinnamon Sugar Donut     85/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(8) Coconut Donut            80/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(9) GO BACK TO MAIN MENU         \t\t\t\t\t\n\n\n");
}

void cookieSubMenu() {
    printf("\n\t\t\t\t COOKIE NAMES              PRICE LIST\t\t\t\t\t\n");
    printf("\t\t\t\t *************             **********\t\t\t\t\t\n");
    printf("\n\t\t\t\t(1) Chocolate Chip Cookie   \t 40/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(2) Peanut Butter Cookie    \t 45/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(3) Oatmeal Raisin Cookie   \t 50/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(4) White Chocolate Cookie  \t 55/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(5) Snickerdoodle Cookie    \t 45/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(6) Double Chocolate Cookie \t 50/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(7) Almond Butter Cookie    \t 55/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(8) Cranberry Orange Cookie \t 50/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(9) GO BACK TO MAIN MENU         \t\t\t\t\t\n\n\n");
}

void pastrySubMenu() {
    printf("\n\t\t\t\t CHOCOLATE PASTRY NAMES            PRICE LIST\t\t\t\t\t\n");
    printf("\t\t\t\t **********************            **********\t\t\t\t\t\n");
    printf("\n\t\t\t\t(1) Chocolate Croissant               80/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(2) Triple Chocolate Danish           85/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(3) Chocolate Eclair                  90/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(5) KitKat Chocolate Cinnamon Roll    95/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(4) KitKat Chocolate Tart             100/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(9) GO BACK TO MAIN MENU                \t\t\t\t\t\n\n\n");
}

void iceCreamSubMenu() {
    printf("\n\t\t\t\t ICE CREAM FLAVORS        PRICE LIST\t\t\t\t\t\n");
    printf("\t\t\t\t *****************        **********\t\t\t\t\t\n");
    printf("\n\t\t\t\t(1) Vanilla                 50/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(2) Chocolate               60/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(3) Strawberry              55/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(4) Mint Chocolate Chip     65/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(5) Cookies and Cream       70/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(6) Butter Pecan            75/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(7) Rocky Road              80/-\t\t\t\t\t\n");
    printf("\n\t\t\t\t(8) Mango Sorbet            90/-\t\t\t\t\t\n\n\n");
}
int processOrder(int category, int item, int prices[], const char *categoryName) {
    if (item >= 1 && item <= 8) {
        int quantity;
        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Update bill and store item details in the cart
        cart[numoforders].quantity = quantity;
        cart[numoforders].price = prices[item - 1] * quantity;
        strcpy(cart[numoforders].itemName, categoryName);
        return bill + cart[numoforders++].price;
    } else if (item == 9) {
        menu();
        return bill;
    } else {
        printf("Invalid input\n");
        return bill;
    }
}
void viewCart() {
	int i;
    printf("\n-------- Your Cart --------\n");

    for ( i = 0; i < numoforders; i++) {
        printf("%d. %s (Quantity: %d) - Price: %d\n", i + 1, cart[i].itemName, cart[i].quantity, cart[i].price);
    }

    printf("\nTotal Cart Value: %d PKR\n", bill);
    printf("--------------------------\n");
}



int adminpanel(int bills, int numberoforders, int grand, int grandtotal) {
    grand = bills;
    printf("\n\n\n");
    printf("\n\n\n\n\n\t\t\t\t\t        *******************************\n");
    printf("\t\t\t\t\t        *    Welcome to Admin Panel   *\n");
    printf("\t\t\t\t\t        *******************************\n");
    printf("\n\n\t\t\t\t\t          ==> Total Sales: %d PKR\n", bills);
    printf("\n\t\t\t\t\t          ==> Total Orders: %d\n", numberoforders);
    printf("\n\t\t\t\t\t          ==> Grand Total: %d PKR\n", grand);
    printf("\n\t\t\t\t\t         ******************************\n\n");

    printf("\t\t\t\tPress 1 to Reset Orders\n\t\t\t\tPress 2 to Exit\n");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            bill = 0;
            numoforders = 0;
            printf("\n\n\t\t\t\t\tOrders Reset Successfully!\n");
            printf("\n\n");
            mainmenu();
            break;
        case 2:
            system("cls");
            printf("\n\n\t\t\t\tExiting Admin Panel!\n");
            exit(0);
            break;
        default:
            printf("\n\n\t\t\t\tInvalid Choice!\n");
            break;
    }

    return 0;
}