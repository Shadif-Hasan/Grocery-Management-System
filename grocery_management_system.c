
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full!\n");
        return;
    }

    struct Item newItem;

    printf("Enter Item ID: ");
    scanf("%d", &newItem.id);

    printf("Enter Item Name: ");
    scanf(" %[^]", newItem.name);

    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);

    printf("Enter Price: ");
    scanf("%f", &newItem.price);

    inventory[itemCount++] = newItem;

    printf("Item added successfully!\n");
}

void displayItems() {
    if (itemCount == 0) {
        printf("No items in inventory.\n");
        return;
    }

    printf("\n%-10s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    for (int i = 0; i < itemCount; i++) {
        printf("%-10d %-20s %-10d $%-9.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void searchItem() {
    int searchId;
    printf("Enter Item ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == searchId) {
            printf("Item found:\n");
            printf("ID: %d\n", inventory[i].id);
            printf("Name: %s\n", inventory[i].name);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: $%.2f\n", inventory[i].price);
            return;
        }
    }

    printf("Item with ID %d not found.\n", searchId);
}

void updateItem() {
    int updateId;
    printf("Enter Item ID to update: ");
    scanf("%d", &updateId);

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == updateId) {
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Item updated successfully.\n");
            return;
        }
    }

    printf("Item with ID %d not found.\n", updateId);
}

void deleteItem() {
    int deleteId;
    printf("Enter Item ID to delete: ");
    scanf("%d", &deleteId);

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == deleteId) {
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Item deleted successfully.\n");
            return;
        }
    }

    printf("Item with ID %d not found.\n", deleteId);
}

int main() {
    int choice;

    do {
        printf("\n==== Grocery Management System ====\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Search Item\n");
        printf("4. Update Item\n");
        printf("5. Delete Item\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addItem(); break;
            case 2: displayItems(); break;
            case 3: searchItem(); break;
            case 4: updateItem(); break;
            case 5: deleteItem(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}
