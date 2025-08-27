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

void viewcustomers() {
    printf("\n=== Customer List ===\n");
    printf("No customers booked yet.\n");
}

void checkroomavailability() {
    printf("\n=== Room Availability ===\n");
    printf("This function will show room status.\n");
}

void generatebill() {
    char name[50];
    int Personalid;
    char Type;
    int Roomnumber;
    float Price;
    int nights;
    //fur mitarbeiter 
    printf("\n=== Generate Bill ===\n");
    printf("Enter The Name \n");
    scanf("%s", name);
    printf("Enter the Personal id \n");
    scanf("%d", &Personalid);
    printf("Enter the Type of the room \n ");
    scanf("%s", &Type);
    printf("Enter the number of the room \n");
    scanf("%d", &Roomnumber);
    printf("Enter the Price \n");
    scanf("%2.f",&Price);
    printf("how many nights \n");
    scanf("%d",%nights);
    float Total;
    Total = nights * Price ;

    printf("Bill for Customer John (ID: %d)\n Room: %d (%S) \n Price per night: %2.f $ \n Nights: %d \n Total: 2.f $", Personalid, Roomnumber, Price , nights , Total);
}

void showmainfunction(struct Room hotel[], int size) {
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
            bookroom(hotel, size);
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
    // Initialize hotel with some sample rooms
    struct Room hotel[5] = {
        {101, 'S', 100.0, 0},  // Standard room, available
        {102, 'S', 100.0, 0},  // Standard room, available
        {201, 'D', 150.0, 0},  // Deluxe room, available
        {202, 'D', 150.0, 0},  // Deluxe room, available
        {301, 'P', 250.0, 0}   // Premium room, available
    };
    
    int size = 5;
    
    // Pass hotel data to the main function
    showmainfunction(hotel, size);
    return 0;
}