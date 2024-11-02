#include <stdio.h>
#include <string.h>
#include<stdlib.h>

struct stock
{
  char item_name[100];
  float price;
  int quantity;
};

int additem(struct stock *items ,int size)
{
  int n = 0;
  printf("Where do you want to put your item? (Choose between 1 and 1000): ");
  while (n > size || n <= 0)
  {
    printf("Enter the place number:\n");
    scanf("%d", &n);
  }
  while (items[n].quantity != 0)
  {
    printf("Place is already taken. Enter another number:\n");
    scanf("%d", &n);
  }


  printf("Enter name of item:\n");
  scanf("%s", items[n].item_name);
  printf("Enter price of item:\n");
  scanf("%f", &items[n].price);
  printf("Enter quantity number:\n");
  scanf("%d", &items[n].quantity);

  return 0;
}

int modify(struct stock *items , int  size)
{
  int n, modify_num, replay;
  printf("What item do you want to modify:\n");
  scanf("%d", &n);
  while (n > size || n <= 0)
  {
    printf("Enter a valid place:\n");
    scanf("%d", &n);
  }
  while (items[n].quantity == 0)
  {
    printf("Place is empty:\n");
    scanf("%d", &n);
  }
  if (items[n].quantity != 0)
  {
    printf("Item[%d] name: %s\n", n, items[n].item_name);
    printf("Item[%d] price: %.2f\n", n, items[n].price);
    printf("Item[%d] quantity: %d\n\n", n, items[n].quantity);
    printf("What do you want to modify? 1 - name, 2 - price, 3 - quantity, other - exit\n");
    scanf("%d", &modify_num);
  }

  do
  {
    if (modify_num == 1)
    {
      printf("Enter new name:\n");
      scanf("%s", items[n].item_name);
    }
    else if (modify_num == 2)
    {
      printf("Enter new price:\n");
      scanf("%f", &items[n].price);
    }
    else if (modify_num == 3)
    {
      printf("Enter new quantity:\n");
      scanf("%d", &items[n].quantity);
    }
    else
    {
      printf("Exiting modification\n");
      return 0;
    }
    printf("Do you want to continue modifying? 0 (no) or any other number (yes):\n");
    scanf("%d", &replay);
  } while (replay != 0);

  return 0;
}

int delet(struct stock *items ,int size)
{
  int n;
  printf("Enter item index to delete:\n");
  scanf("%d", &n);
  if (n >= 0 && n <= size && items[n].quantity != 0)
  {
    // Mark the item as deleted by setting quantity to 0

    items[n].quantity = 0;
    printf("Item deleted successfully.\n");
  }
  else
  {
    printf("Invalid index or empty item.\n");
  }
  return 0;
}

void savetofile(struct stock *items , int size)
{
  FILE *stock = fopen("C:\\Users\\SURFUCE\\Pictures\\FDS\\stock.txt", "w");
  if (stock == NULL)
  {
    printf("Error opening file!\n");
    return;
  }

  printf("Saving to file and displaying all items:\n");

  for (int i = 1; i <= size; i++)
  {
    if (items[i].quantity != 0)
    {
      fprintf(stock, "Item[%d] Name: %s\n", i, items[i].item_name);
      fprintf(stock, "Item[%d] Price: %.2f\n", i, items[i].price);
      fprintf(stock, "Item[%d] Quantity: %d\n\n", i, items[i].quantity);

      printf("Item[%d] Name: %s\n", i, items[i].item_name);
      printf("Item[%d] Price: %.2f\n", i, items[i].price);
      printf("Item[%d] Quantity: %d\n\n", i, items[i].quantity);
    }
  }

  fclose(stock);
  printf("Data saved to file successfully.\n");
}

int main()
{
  int size=1000;
  int replay = 1;
  struct stock *items= (struct stock *) calloc(size,sizeof(struct stock));

  int choice;
  do
  {
    printf("\t....Welcome to Stock Management...\n");
    printf("\t....Select an option:...........\n");
    printf("\t1.......Add item to stock........\n");
    printf("\t2.......Modify item in stock......\n");
    printf("\t3..........Delete item...........\n");
    printf("\t4............Exit................\n");
    printf("Enter your choice:\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      additem(items, size);
      break;
    case 2:
      modify(items, size);
      break;
    case 3:
      delet(items, size);
      break;
    case 4:
      return 0;
    default:
      printf("Invalid choice. Please try again.\n");
    }
    printf("Do you want to continue? (1 = yes, 0 = no)\n");
    scanf("%d", &replay);
  } while (replay != 0);

  savetofile(items,size);
  return 0;
}
