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

void clearInputBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory is full!\n");
        return;
    }

    struct Item newItem;

    printf("Enter Item ID: ");
    if (scanf("%d", &newItem.id) != 1) {
        printf("Invalid input for ID!\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    // Prevent duplicate IDs
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == newItem.id) {
            printf("Item ID already exists!\n");
            return;
        }
    }

    printf("Enter Item Name: ");
    fgets(newItem.name, sizeof(newItem.name), stdin);
    newItem.name[strcspn(newItem.name, "\n")] = '\0'; // Remove newline

    printf("Enter Quantity: ");
    if (scanf("%d", &newItem.quantity) != 1) {
        printf("Invalid input for quantity!\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    printf("Enter Price: ");
    if (scanf("%f", &newItem.price) != 1) {
        printf("Invalid input for price!\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

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
        printf("%-10d %-20s %-10d $%-9.2f\n",
               inventory[i].id,
               inventory[i].name,
               inventory[i].quantity,
               inventory[i].price);
    }
}

void searchItem() {
    int searchId;
    printf("Enter Item ID to search: ");
    if (scanf("%d", &searchId) != 1) {
        printf("Invalid input!\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

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
    if (scanf("%d", &updateId) != 1) {
        printf("Invalid input!\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == updateId) {
            printf("Enter new quantity: ");
            if (scanf("%d", &inventory[i].quantity) != 1) {
                printf("Invalid input!\n");
                clearInputBuffer();
                return;
            }
            clearInputBuffer();

            printf("Enter new price: ");
            if (scanf("%f", &inventory[i].price) != 1) {
                printf("Invalid input!\n");
                clearInputBuffer();
                return;
            }
            clearInputBuffer();

            printf("Item updated successfully.\n");
            return;
        }
    }

    printf("Item with ID %d not found.\n", updateId);
}

void deleteItem() {
    int deleteId;
    printf("Enter Item ID to delete: ");
    if (scanf("%d", &deleteId) != 1) {
        printf("Invalid input!\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

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

        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

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
