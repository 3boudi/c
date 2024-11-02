#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an item
struct Item
{
    char name[50];
    float price;
    int quantity;
};

// Dynamic array to store items
struct Item *items = NULL;
FILE *file;
char filename[] = "stock.txt";
int itemCount = 0;

// Function to display the details of an item
void displayItem(struct Item item)
{
    printf("Name: %s\n", item.name);
    printf("Price: %.2f\n", item.price);
    printf("Quantity in stock: %d\n", item.quantity);
    printf("\n");
}

// Function to save data to a file
void saveData()
{
    FILE *stockFile;
    stockFile = fopen("stock.txt", "w");

    for (int i = 0; i < itemCount; i++)
    {
        fprintf(stockFile, "Item: %d\n", i + 1);
        fprintf(stockFile, "Name: %s\n", items[i].name);
        fprintf(stockFile, "Price: %.2f\n", items[i].price);
        fprintf(stockFile, "Quantity in stock: %d\n", items[i].quantity);
        fprintf(stockFile, "\n");
    }
    fclose(stockFile);
}

void loadItems()
{
    struct Item temp;
    int k = 0;

    // Open the file for reading
    file = fopen(filename, "r");

    if (file != NULL)
    {
        while (fscanf(file, "Item: %d\nName: %s\nPrice: %f\nQuantity in stock: %d\n\n",
                      &k, temp.name, &temp.price, &temp.quantity) != EOF)
        {
            items = realloc(items, (itemCount + 1) * sizeof(struct Item));
            strcpy(items[itemCount].name, temp.name);
            items[itemCount].price = temp.price;
            items[itemCount].quantity = temp.quantity;
            itemCount++;
        }
        fclose(file);
    }
}

int main()
{
    int choice;

    printf("Welcome to the inventory management program.\n");
    loadItems();
    printf("Number of items: %d\n", itemCount);

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Add an item\n");
        printf("2. Edit an item\n");
        printf("3. Delete an item\n");
        printf("4. Display all items\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5)
        {
            free(items);
            break;
        }

        switch (choice)
        {
        case 1:
            // Add an item
            itemCount++;
            items = realloc(items, itemCount * sizeof(struct Item));
            printf("\nEnter the details of the item:\n");
            printf("Name: ");
            scanf("%s", items[itemCount - 1].name);
            printf("Price: ");
            scanf("%f", &items[itemCount - 1].price);
            printf("Quantity in stock: ");
            scanf("%d", &items[itemCount - 1].quantity);
            saveData();
            break;

        case 2:
            // Edit an item
            if (itemCount == 0)
            {
                printf("\nNo items to edit.\n");
            }
            else
            {
                int editChoice;
                printf("\nSelect the item to edit (from 1 to %d): ", itemCount);
                scanf("%d", &editChoice);

                if (editChoice >= 1 && editChoice <= itemCount)
                {
                    printf("\nEnter the new information for the item:\n");
                    printf("Name: ");
                    scanf("%s", items[editChoice - 1].name);
                    printf("Price: ");
                    scanf("%f", &items[editChoice - 1].price);
                    printf("Quantity in stock: ");
                    scanf("%d", &items[editChoice - 1].quantity);
                    saveData();
                }
                else
                {
                    printf("\nInvalid item number.\n");
                }
            }
            break;

        case 3:
            // Delete an item
            if (itemCount == 0)
            {
                printf("\nNo items to delete.\n");
            }
            else
            {
                int deleteChoice;
                printf("\nSelect the item to delete (from 1 to %d): ", itemCount);
                scanf("%d", &deleteChoice);

                if (deleteChoice >= 1 && deleteChoice <= itemCount)
                {
                   
                    for (int i = deleteChoice - 1; i < itemCount - 1; i++)
                    {
                        strcpy(items[i].name, items[i + 1].name);
                        items[i].price = items[i + 1].price;
                        items[i].quantity = items[i + 1].quantity;
                    }
                    itemCount--;
                    items = realloc(items, itemCount * sizeof(struct Item));
                    saveData();
                    printf("\nThe item was successfully deleted.\n");
                }
                else
                {
                    printf("\nInvalid item number.\n");
                }
            }
            break;

        case 4:
            // Display all items
            printf("\nList of items: %d\n", itemCount);
            for (int i = 0; i < itemCount; i++)
            {
                printf("Item: %d\n", i + 1);
                displayItem(items[i]);
            }
            break;

        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
        }
    }
}
