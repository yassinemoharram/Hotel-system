#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Room {
    int number;
    char Type;
    float Price;
    int isbooked; // 0 = available, 1 = booked
};

void bookroom(struct Room hotel[], int size) {
    printf("\n Available Rooms:\n");
    for(int i = 0; i < size; i++){
        printf("Room %d | %c | %.2f$ | %s\n",
            hotel[i].number,
            hotel[i].Type,
            hotel[i].Price,
            hotel[i].isbooked ? "Booked" : "Available");
    }
    
    int choice;
    printf("\n Enter the room number you want to book: ");
    scanf("%d", &choice);

    int found = 0;
    for (int i = 0; i < size; i++) {
        if (hotel[i].number == choice) {
            found = 1;
            if (hotel[i].isbooked) {
                printf("❌ Room %d is already booked.\n", hotel[i].number);
            } else {
                hotel[i].isbooked = 1;

                char name[50];
                char personal_id[20];
                
                printf("Enter your name please:\n");
                scanf("%s", name);
                printf("Enter Your personal id please:\n");
                scanf("%s", personal_id);

                printf("✅ Booking confirmed for %s (ID: %s) in Room %d\n",
                       name, personal_id, hotel[i].number);
            }
            break;
        }
    }
    if (!found) {
        printf("⚠️ Room number %d not found.\n", choice);
    }
}

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
    printf("5. Exit\n");
    printf("===================================================\n");
    printf("Enter Your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            // You need to pass hotel array and size here
            // bookroom(hotel, size);
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

        case 5:
            printf("👋 Exiting program...\n");
            exit(0);
            
        default:
            printf("Invalid choice (please choose the numbers that are given above)\n");
            break;
    }
}

int main() {
    showmainfunction();
    return 0;
}