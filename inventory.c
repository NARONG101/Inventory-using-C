#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

// Structure to store item information
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Item;

Item inventory[MAX_ITEMS];
int itemCount = 0;

// Function to pause until user presses Enter
void waitForEnter() {
    printf("\nPress Enter to return to the main menu...");
    while (getchar() != '\n'); // flush leftover newline
    getchar(); // wait for Enter
}

// Function to create a new item
void createItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory full! Cannot add more items.\n");
        waitForEnter();
        return;
    }

    Item newItem;
    printf("Enter Item ID: ");
    scanf("%d", &newItem.id);

    printf("Enter Item Name: ");
    while (getchar() != '\n'); // clear newline before fgets
    fgets(newItem.name, sizeof(newItem.name), stdin);
    newItem.name[strcspn(newItem.name, "\n")] = '\0'; // remove newline

    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);

    printf("Enter Price: ");
    scanf("%f", &newItem.price);

    inventory[itemCount++] = newItem;
    printf("Item added successfully!\n");

    waitForEnter();
}

// Function to update an existing item
void updateItem() {
    int id, found = 0;
    printf("Enter Item ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            found = 1;
            printf("Enter new name: ");
            while (getchar() != '\n');
            fgets(inventory[i].name, sizeof(inventory[i].name), stdin);
            inventory[i].name[strcspn(inventory[i].name, "\n")] = '\0';

            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);

            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);

            printf("Item updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Item not found!\n");
    }

    waitForEnter();
}

// Function to search for an item
void searchItem() {
    int id, found = 0;
    printf("Enter Item ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            found = 1;
            printf("\nItem Found:\n");
            printf("ID: %d\n", inventory[i].id);
            printf("Name: %s\n", inventory[i].name);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: $%.2f\n", inventory[i].price);
            break;
        }
    }

    if (!found) {
        printf("Item not found!\n");
    }

    waitForEnter();
}

// Function to delete an item
void deleteItem() {
    int id, found = 0;
    printf("Enter Item ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            found = 1;
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Item deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Item not found!\n");
    }

    waitForEnter();
}

// Function to view all items
void viewAllItems() {
    if (itemCount == 0) {
        printf("No items in inventory.\n");
    } else {
        printf("\nAll Inventory Items:\n");
        for (int i = 0; i < itemCount; i++) {
            printf("ID: %d | Name: %s | Quantity: %d | Price: $%.2f\n",
                   inventory[i].id, inventory[i].name,
                   inventory[i].quantity, inventory[i].price);
        }
    }
    waitForEnter();
}

// Main function
int main() {
    int choice;

    do {
        printf("\n==============================\n");
        printf("Inventory Management System\n");
        printf("Assignment2\n");
        printf("==============================\n");
        printf("1. Create Item\n");
        printf("2. Update Item\n");
        printf("3. Search Item\n");
        printf("4. Delete Item\n");
        printf("5. View All Items\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createItem(); break;
            case 2: updateItem(); break;
            case 3: searchItem(); break;
            case 4: deleteItem(); break;
            case 5: viewAllItems(); break;
            case 6: printf("Exiting program...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}
