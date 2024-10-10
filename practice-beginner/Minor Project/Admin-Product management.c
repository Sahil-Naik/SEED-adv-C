#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


// TO-DO: Program only accepts string as "HelloWorld" and not "Hello World"

struct Admin {
    char admin_Username[30];
    char admin_Password[30];
    char admin_Code[30];
};

struct Product {
    int product_ID;
    char product_Owner[50];
    char product_Name[50];
    int product_Quantity;
    int product_Price;
};

// Function to generate random code
int randomDigitGenerator() {
    return rand() % 90000 + 10000;  // Generates a random 5-digit code
}

// Add a new product
void addProduct(struct Product *products, int *productCount, const char *owner) {
    struct Product newProduct;

    printf("\n\n\n----------ADD PRODUCT----------\n\n");

    newProduct.product_ID = *productCount + 1;  // Auto-increment ID
    printf("Enter product name: ");
    scanf("%49s", newProduct.product_Name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.product_Quantity);
    printf("Enter product price: ");
    scanf("%d", &newProduct.product_Price);

    strcpy(newProduct.product_Owner, owner);  // Set the owner

    products[*productCount] = newProduct;
    (*productCount)++;
    printf("\nProduct added successfully!\n");

    printf("\n----------ADD PRODUCT----------");
}

// Delete a product
void deleteProduct(struct Product *products, int *productCount, const char *owner) {
    int id, found = 0;
    printf("\n\n\n---------DELETE PRODUCT--------\n\n");
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *productCount; i++) {
        if (products[i].product_ID == id && strcmp(products[i].product_Owner, owner) == 0) {
            found = 1;
            for (int j = i; j < *productCount - 1; j++) {
                products[j] = products[j + 1];
            }
            (*productCount)--;
            printf("\nProduct deleted successfully.\n");
            printf("\n---------DELETE PRODUCT--------\n");
            return;
        }
    }

    if (!found) {
        printf("Product not found or you don't have permission to delete it.\n");
        printf("\n---------DELETE PRODUCT---------\n");
    }

}

// Update a product
void updateProduct(struct Product *products, int productCount, const char *owner) {
    int id, found = 0;
    printf("\n\n\n---------UPDATE PRODUCT---------\n\n");
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < productCount; i++) {
        if (products[i].product_ID == id && strcmp(products[i].product_Owner, owner) == 0) {
            found = 1;
            printf("Enter new product name: ");
            scanf("%49s", products[i].product_Name);
            printf("Enter new product quantity: ");
            scanf("%d", &products[i].product_Quantity);
            printf("Enter new product price: ");
            scanf("%d", &products[i].product_Price);
            printf("\nProduct updated successfully.\n");
            printf("\n---------UPDATE PRODUCT---------");
            return;
        }

    }

    if (!found) {
        printf("\nProduct not found or you don't have permission to update it.\n");
        printf("\n----------UPDATE PRODUCT-----------");
    }
}

// View all products for the logged-in admin
void viewProducts(struct Product *products, int productCount, const char *owner) {
    printf("\n\n\n---------PRODUCT DETAILS---------\n\n");
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].product_Owner, owner) == 0) {
            printf("ID: %d, Name: %s, Quantity: %d, Price: %d\n",
                   products[i].product_ID,
                   products[i].product_Name,
                   products[i].product_Quantity,
                   products[i].product_Price);
        }
    }
    printf("\n---------PRODUCT DETAILS---------\n");
}

int main() {
    srand(time(0));

    int originalSize = 1;  // Start with size 1 to account for root admin
    int productCount = 0;
    int choice = 0, reset = 0;
    char adminUsername[50], adminPassword[50], adminCode[50];

    int usernameExists = 0;

    // Allocate memory for admin and product arrays
    struct Admin *admin = (struct Admin *)malloc(originalSize * sizeof(struct Admin));
    struct Product *products = (struct Product *)malloc(100 * sizeof(struct Product));

    if (admin == NULL || products == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Root admin setup
    printf("Creating new login for Admin...\n\n");
    printf("Enter Admin username: ");
    scanf("%29s", admin[0].admin_Username);
    printf("Enter new Password: ");
    scanf("%29s", admin[0].admin_Password);

    int code = randomDigitGenerator();
    snprintf(admin[0].admin_Code, 30, "%d", code);

    printf("\n\n-----------ROOT ADDED----------");
    printf("\nUsername: %s", admin[0].admin_Username);
    printf("\nCode: %s\nUse this code to reset password\nDON'T SHARE IT!", admin[0].admin_Code);
    printf("\n-------------------------------\n");

    // Main loop
    do {
        printf("\n\n\n--------CHOOSE AN OPTION-------\n");
        printf("\n1 = Register new User\n2 = Login\n3 = EXIT\nChoose: ");
        scanf("%d", &choice);
        printf("\n--------CHOOSE AN OPTION-------\n");

        switch (choice) {
            case 1: {
                usernameExists=0;
                printf("\n\n\n-----------NEW USER------------\n\n");
                printf("Enter Admin username: ");
                scanf("%29s", adminUsername);

                // Check if the username already exists
                for (int i = 0; i < originalSize; i++) {
                    if (strcmp(admin[i].admin_Username, adminUsername) == 0) {
                        usernameExists = 1;
                        break; // Username found, exit the loop
                    }
                }

                // If username exists, prompt the user to enter a new username
                if (usernameExists) {
                    printf("\nUsername already exists!\nPlease choose a different username!!\n");
                } else {
                    originalSize++;
                    admin = realloc(admin, originalSize * sizeof(struct Admin));

                    if (admin == NULL) {
                        printf("Memory allocation failed!\n");
                        exit(1);
                    }

                    // Assign the new username to the admin array
                    strcpy(admin[originalSize - 1].admin_Username, adminUsername);
                    printf("Enter new Password: ");
                    scanf("%29s", admin[originalSize - 1].admin_Password);

                    code = randomDigitGenerator();
                    snprintf(admin[originalSize - 1].admin_Code, 30, "%d", code);

                    printf("\nCode: %s\nUse this code to reset password\nDON'T SHARE IT!", admin[originalSize - 1].admin_Code);

                    printf("New user registered successfully!\n");
                }
                printf("\n-----------NEW USER------------");
                break;
            }

            case 2: {
                // Login and manage products
                printf("\n\n\n-------------LOGIN-------------\n");
                printf("\nEnter Admin username: ");
                scanf("%29s", adminUsername);
                printf("Enter Password (or type 'RES' to reset): ");
                scanf("%29s", adminPassword);

                int loggedIn = 0;
                if (strcmp(adminPassword, "RES") == 0) {
                    printf("\n\n--------PASSWORD RESET---------\n");
                    printf("\nEnter secret code: ");
                    scanf("%s", adminCode);
                    for (int i = 0; i < originalSize; i++) {
                        if (strcmp(admin[i].admin_Username, adminUsername) == 0 && strcmp(admin[i].admin_Code, adminCode) == 0) {
                            reset = 1;
                            printf("\nEnter new password: ");
                            scanf("%s", admin[i].admin_Password);

                            code = randomDigitGenerator();
                            snprintf(admin[i].admin_Code, 30, "%d", code);

                            printf("\nPassword Updated!");
                            printf("\nNew Code: %s\nUse this code to reset password\nDON'T SHARE IT!", admin[i].admin_Code);
                            break;
                        }
                    }

                    if (reset == 1) {
                        printf("\n--------PASSWORD RESET---------\n");
                    } else {
                        printf("\nUsername or Code incorrect!");
                        printf("\n--------PASSWORD RESET---------\n");
                    }
                    printf("\n------------LOGIN--------------");
                } else {
                    for (int i = 0; i < originalSize; i++) {
                        if (strcmp(admin[i].admin_Username, adminUsername) == 0 &&
                            strcmp(admin[i].admin_Password, adminPassword) == 0) {
                            loggedIn = 1;
                            printf("\nLogin Successful!\n");
                            printf("\n------------LOGIN--------------");

                            int innerChoice;
                            do {
                                printf("\n\n\n----------DASHBOARD------------\n");
                                printf("\n1. Add Product\n2. Delete Product\n3. Update Product\n4. View Products\n5. Log Out\n");
                                printf("Enter your choice: ");
                                scanf("%d", &innerChoice);
                                printf("\n----------DASHBOARD------------");

                                switch (innerChoice) {
                                    case 1:
                                        addProduct(products, &productCount, admin[i].admin_Username);
                                        break;
                                    case 2:
                                        deleteProduct(products, &productCount, admin[i].admin_Username);
                                        break;
                                    case 3:
                                        updateProduct(products, productCount, admin[i].admin_Username);
                                        break;
                                    case 4:
                                        viewProducts(products, productCount, admin[i].admin_Username);
                                        break;
                                    case 5:
                                        printf("\n\nLogging out...\n");
                                        break;
                                    default:
                                        printf("Invalid choice!\n");
                                }
                            } while (innerChoice != 5);

                            break;
                        }
                        if (!loggedIn) {
                            printf("\nLogin failed! Invalid username or password.\n");
                        }
                    }
                }


                break;
            }

            case 3:
                printf("\n\nExiting...\n");
                break;

            default:
                printf("\nInvalid option! Please try again.\n");
        }

    } while (choice != 3);

    // Free allocated memory
    free(admin);
    free(products);

    return 0;
}
