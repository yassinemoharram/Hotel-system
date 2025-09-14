#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct Room {
    int number;
    char Type;
    float Price;
    int isbooked; // 0 = available, 1 = booked
    char customerName[50];
    char personal_id[20];
    char checkIn[25];   // Example: "2025-09-14 14:00"
    char checkOut[25];  // Example: "2025-09-16 12:00"

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

                

                printf("Enter your name please:\n");
                scanf("%s", hotel[i].customerName);
                printf("Enter Your personal id please:\n");
                scanf("%s", hotel[i].personal_id);
                printf("Enter check-in time (YYYY-MM-DD_HH:MM): ");
                scanf("%s", hotel[i].checkIn);
                printf("Enter check-out time (YYYY-MM-DD_HH:MM): ");
                scanf("%s", hotel[i].checkOut);

                printf("✅ Booking confirmed for %s (ID: %s) in Room %d\n",
                    hotel[i].customerName, hotel[i].personal_id, hotel[i].number);
            }
            break;
        }
    }
    if (!found) {
        printf("⚠️ Room number %d not found.\n", choice);
    }
}

void viewcustomers(struct Room hotel[], int size) {
    int found = 0;
    printf("\n=== Customer List ===\n");

    for (int i = 0; i < size; i++) {
        if (hotel[i].isbooked) {
            printf("Room %d (%c) | %.2f $/night | Customer: %s (ID: %s)\n",
                   hotel[i].number,
                   hotel[i].Type,
                   hotel[i].Price,
                   hotel[i].customerName,
                   hotel[i].personal_id,
                   hotel[i].checkIn,
                   hotel[i].checkOut);
            found = 1;
        }
    }

    if (!found) {
        printf("⚠️ No customers booked yet.\n");
    }
}


void checkroomavailability(struct Room hotel[], int size) {
    printf("\n=== Room Availability ===\n");
    for (int i = 0; i < size; i++) {
        printf("Room %d | Type: %c | Price: %.2f $ | Status: %s\n",
               hotel[i].number,
               hotel[i].Type,
               hotel[i].Price,
               hotel[i].isbooked ? "Booked" : "Available");
    }
}


void generatebill(struct Room hotel[], int size) {
    int roomno;
    printf("Enter the room number for bill generation: ");
    scanf("%d", &roomno);

    for (int i = 0; i < size; i++) {
        if (hotel[i].number == roomno) {
            if (hotel[i].isbooked == 0) {
                printf("⚠️ Room %d is not booked. No bill available.\n", roomno);
                return;
            }

            int nights;
            printf("How many nights did the customer stay? ");
            scanf("%d", &nights);

            float total = nights * hotel[i].Price;

            printf("\n================= HOTEL BILL =================\n");
            printf("Customer: %-20s | ID: %s\n", hotel[i].customerName, hotel[i].personal_id);
            printf("Room No: %-3d | Type: %c | Price: %.2f $/night\n", hotel[i].number, hotel[i].Type, hotel[i].Price);
            printf("Check-in: %s | Check-out: %s\n", hotel[i].checkIn, hotel[i].checkOut);
            printf("Nights Stayed: %d\n", nights);
            printf("----------------------------------------------\n");
            printf("TOTAL : %.2f $\n", total);

            printf("==============================================\n");
            return;
        }
    }
    printf("❌ Room %d not found.\n", roomno);
}

void cancelbooking(struct Room hotel[], int size){

    int roomno;
    printf("Enter the room number to cancel booking: \n");
    scanf("%d",&roomno);

    for(int i = 0; i < size; i++){
        if (hotel[i].number == roomno){
            if(hotel[i].isbooked){
                hotel[i].isbooked = 0;
                strcpy(hotel[i].customerName,"");
                strcpy(hotel[i].personal_id,"");
                strcpy(hotel[i].checkIn, "");
                strcpy(hotel[i].checkOut, "");
                printf("✅ Booking for Room %d has been cancelled.\n", roomno);
            } else {
                printf("⚠️ Room %d is already available.\n", roomno);
            }
            return;
        }
    }
    printf("❌ Room not found.\n");
}

void modifybooking(struct Room hotel[],int size){

    int roomno;

    printf("Enter the room number to modify booking: ");
    scanf("%d", &roomno);

    for (int i = 0; i < size; i++) {
        if (hotel[i].number == roomno && hotel[i].isbooked) {
            printf("Current Customer: %s (ID: %s)\n",
                   hotel[i].customerName, hotel[i].personal_id);

            printf("Enter new name: ");
            scanf("%s", hotel[i].customerName);
            printf("Enter new ID: ");
            scanf("%s", hotel[i].personal_id);

            printf("✅ Booking for Room %d has been updated.\n", roomno);
            return;
        }
    }
    printf("❌ Room not found or not booked.\n");
}
void searchCustomer(struct Room hotel[], int size) {
    char input[50];
    printf("Enter customer name or ID to search: ");
    scanf("%s", input);

    int found = 0;
    for (int i = 0; i < size; i++) {
        if (hotel[i].isbooked &&
           (strcmp(hotel[i].customerName, input) == 0 || strcmp(hotel[i].personal_id, input) == 0)) {
            printf("Room %d | Type: %c | Price: %.2f | Customer: %s | ID: %s\n",
                   hotel[i].number, hotel[i].Type, hotel[i].Price,
                   hotel[i].customerName, hotel[i].personal_id);
            found = 1;
        }
    }

    if (!found) {
        printf("⚠️ Customer not found.\n");
    }
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
    printf("5. Cancel Booking\n");
    printf("6. Modify Booking\n");
    printf("7. Search Customer\n");
    printf("8. Exit\n");
    printf("===================================================\n");
    printf("Enter Your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            bookroom(hotel, size);
            break;

        case 2:
            viewcustomers(hotel, size);
            break;

        case 3:
            checkroomavailability(hotel, size); 
            break;

        
        case 4:
            generatebill(hotel, size);
            break;

        case 5:
            cancelbooking(hotel, size);
            break;

        case 6:
            modifybooking(hotel, size);
            break;

        case 7:
            searchCustomer(hotel, size)
            break;

        case 8:
            printf("👋 Exiting program...\n");
            exit(0);

        

        default:
            printf("Invalid  choice (please choose the numbers that are given above)\n");
            break;





    }
}

int main() {
    // Initialize hotel with some sample rooms
   struct Room hotel[5] = {
    {101, 'S', 100.0, 0, "", "", "", ""},
    {102, 'S', 100.0, 0, "", "", "", ""},
    {201, 'D', 150.0, 0, "", "", "", ""},
    {202, 'D', 150.0, 0, "", "", "", ""},
    {301, 'P', 250.0, 0, "", "", "", ""}
};

    int size = 5;

    // Pass hotel data to the main function
    while (1) {
        showmainfunction(hotel, size);
    }
    return 0;
}
