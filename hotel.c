#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bookroom() {}
void viewcustomers() {}
void checkroomavailability() {}
void generatebill() {}

void showmainfunction() {
    int choice;
    printf("===================================================\n");
    printf("         Welcome to the Hotel Management System       \n");
    printf("===================================================\n");
    printf("1. Book a Room \n");
    printf("2. View Customers\n");
    printf("3. Check Room Availability\n");
    printf("4. Generate Bill \n");
    printf("===================================================\n");
    printf("Enter Your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            bookroom();
            break;
        case 2:
            viewcustomers();
            break;
        case 3:
            checkroomavailability();
            break;
        case 4:
            generatebill();
            break;
        default:
            printf("Invalid choice (please choose the numbers that are given above)\n");
            break;
    }
}

int main() {
    showmainfunction();
    return 0;
}