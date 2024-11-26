#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length constants
#define NAME_LEN 100
#define BLOOD_TYPE_LEN 4

// Donor structure
typedef struct Donor {
    char name[NAME_LEN];
    char bloodType[BLOOD_TYPE_LEN];
    int age;
    struct Donor* next;
} Donor;

// Blood Inventory structure
typedef struct {
    char bloodType[BLOOD_TYPE_LEN];
    int quantity;
} BloodInventory;

// Global variables
Donor* donorHead = NULL;
BloodInventory bloodInventory[8] = {
    {"A+", 0}, {"A-", 0}, {"B+", 0}, {"B-", 0},
    {"AB+", 0}, {"AB-", 0}, {"O+", 0}, {"O-", 0}
};

// Function prototypes
void addDonor();
void viewDonors();
void addBlood();
void viewBloodInventory();
void requestBlood();
int findBloodIndex(char* bloodType);
void displayMenu();

int main() {
    int choice;
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character

        switch(choice) {
            case 1: addDonor(); break;
            case 2: viewDonors(); break;
	            case 3: addBlood(); break;
}

void addDonor() {
    Donor* newDonor = (Donor*)malloc(sizeof(Donor));
    
    printf("Enter donor name: ");
    fgets(newDonor->name, NAME_LEN, stdin);
    newDonor->name[strcspn(newDonor->name, "\n")] = '\0'; // Remove trailing newline

    printf("Enter blood type: ");
    fgets(newDonor->bloodType, BLOOD_TYPE_LEN, stdin);
    newDonor->bloodType[strcspn(newDonor->bloodType, "\n")] = '\0'; // Remove trailing newline

    printf("Enter age: ");
    scanf("%d", &newDonor->age);
    getchar(); // to consume the newline character

    newDonor->next = donorHead;
    donorHead = newDonor;

    printf("Donor added successfully!\n");
}

void viewDonors() {
    Donor* current = donorHead;

    if (current == NULL) {
        printf("No donors available.\n");
        return;
    }
       printf("\nList of Donors:\n");
    fgets(bloodType, BLOOD_TYPE_LEN, stdin);
    bloodType[strcspn(bloodType, "\n")] = '\0'; // Remove trailing newline

    printf("Enter quantity: ");
    scanf("%d", &quantity);
    getchar(); // to consume the newline character

    int index = findBloodIndex(bloodType);
    if (index != -1) {
        bloodInventory[index].quantity += quantity;
        printf("Blood added successfully!\n");
    } else {
        printf("Invalid blood type!\n");
    }
}

void viewBloodInventory() {
    printf("\nBlood Inventory:\n");
    for (int i = 0; i < 8; i++) {
        printf("Blood Type: %s, Quantity: %d\n", bloodInventory[i].bloodType, bloodInventory[i].quantity);
    }
}

void requestBlood() {
    char bloodType[BLOOD_TYPE_LEN];
    int quantity;

    printf("Enter blood type: ");
    fgets(bloodType, BLOOD_TYPE_LEN, stdin);
    bloodType[strcspn(bloodType, "\n")] = '\0'; // Remove trailing newline

    printf("Enter quantity: ");
    scanf("%d", &quantity);
    getchar(); // to consume the newline character

    int index = findBloodIndex(bloodType);
    if (index != -1) {
        if (bloodInventory[index].quantity >= quantity) {
            bloodInventory[index].quantity -= quantity;
            printf("Blood request fulfilled successfully!\n");
        } else {
            printf("Insufficient blood quantity!\n");
        }
    } else {
        printf("Invalid blood type!\n");
    }
}

int findBloodIndex(char* bloodType) {
    for (int i = 0; i < 8; i++) {
        if (strcmp(bloodType, bloodInventory[i].bloodType) == 0) {
            return i;
        }
    }
    return -1;
}

