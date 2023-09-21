#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct menuItem {
    char name[50];
    float price;
};

void displayMenu(struct menuItem menu[], int size) {
    printf("\n------------------MENU------------------\n\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - Tk. %.2f\n", i+1, menu[i].name, menu[i].price);
    }
    printf("-----------------------------------------\n");
}


void placeOrder(struct menuItem menu[], int size) {

    FILE *pt;
    pt = fopen("customer_info.txt", "a");
    int a,b,c=0;
    fprintf(pt,"Item Ordered --------------------- Quantity of Items\n",a,b);

    int choice, quantity,counter = 0;
    float total = 0;
    printf("\nEnter the item number you want to order (0 to end): ");
    scanf("%d", &choice);
    while (choice != 0) {
        if (choice < 1 || choice > size) {
            printf("Invalid item number. Please try again.\n");
            break;
        }
        else {
            printf("Enter the quantity: ");
            scanf("%d", &quantity);
            fprintf(pt, "\n%s ---------------------- %d\n",menu[choice-1].name, quantity);
            total += menu[choice-1].price * quantity;
        }
        printf("\nEnter the item number you want to order (0 to end): ");
        counter++;
        scanf("%d", &choice);
    }
    printf("\nTotal bill: Tk. %.2f\n\n Thank you! Enjoy your Meal\n\n\n\n", total);

     fprintf(pt,"\n Category of items ordered = %d ---- Total Bill = %.2f BDT\n\n\n\n", counter, total);

    fclose(pt);
}

int main() {
    struct menuItem menu[] = {
        {"Cheeseburger", 150.00},
        {"French Fries", 75.00},
        {"Chicken Sandwich", 60.00},
        {"Pizza", 475.00},
        {"Sub Sandwich", 120.00},
        {"Chicken Momos(6 pieces)", 120.00},
        {"Russian Bread", 110.00},
        {"BBQ Rice Bowl", 130.00},
        {"Chicken Roll", 75.00},
        {"Salad", 40.00},
        {"Ice Cream", 50.00},
        {"Pudding", 40.00},
        {"Cake", 75.00},
        {"Cold Drinks", 20.00}
    };
    int menuSize = sizeof(menu) / sizeof(menu[0]);


    int choice;
        printf("\t \t \t\t--------------------- Khabe Naki ---------------------");
        printf("\n\t\t\t\t\tWelcome to Our Restaurant Khabe Naki \n");
        printf("\n1. Admin Login\n");
        printf("2. Exit\n");
        scanf("%d",&choice);

        switch(choice) {
        case 1:
            char password[10];
            printf("Enter Admin Password:\n");
            scanf("%s",password);

            if(strcmp(password,"admin")==0){
                while(1){
                printf("1. Display Menu\n");
                printf("2. Place Order\n");
                printf("3. Exit\n");
                printf("Enter your choice: \n");
                int admin_choice;
                scanf("%d", &admin_choice);

                switch(admin_choice){

                    case 1:
                        displayMenu(menu, menuSize);
                        break;
                    case 2:
                        placeOrder(menu, menuSize);
                        break;
                    case 3:
                        printf("\nThank you for staying with Khabe Naki. Enjoy Your Meal!");
                        exit(0);
                    default:
                        printf("\nInvalid choice. Please try again.\n");

                }

                }
            }
            else{
                printf("Incorrect Password\n");
            }
            break;

        case 2:
            printf("\nThank you for staying with Khabe Naki\n");
            exit(0);
            break;

        default:
            printf("Incorrect option\n");

        }

    return 0;
}
// some line added
