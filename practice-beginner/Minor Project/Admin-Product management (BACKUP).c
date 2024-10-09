#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>


struct Admin{
    char admin_Username[30];
    char admin_Password[30];
    char admin_Code[30];
};

struct Product{
    int product_ID;
    char product_Owner[50];
    char product_Name[50];
    int product_Quantity;
    int product_Price;
};

int randomDigitGenerator(){
    return rand() % 90000 + 10000;
}

int login(struct Admin* admin) {
    char enteredUsername[30], enteredPassword[30];
    printf("Enter username: ");
    scanf("%29s", enteredUsername);
    printf("Enter password: ");
    scanf("%29s", enteredPassword);

    if (strcmp(admin->admin_Username, enteredUsername) == 0 &&
        strcmp(admin->admin_Password, enteredPassword) == 0) {
        printf("Login successful!\n");
        return 1; // Success
    } else {
        printf("Login failed!\n");
        return 0; // Failure
    }
}

void addProduct(struct Product* products, int* productCount, const char* owner) {
    struct Product newProduct;

    newProduct.product_ID = *productCount + 1; // Auto-increment ID
    printf("Enter product name: ");
    scanf("%49s", newProduct.product_Name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.product_Quantity);
    printf("Enter product price: ");
    scanf("%d", &newProduct.product_Price);
    strcpy(newProduct.product_Owner, owner); // Set the owner

    products[*productCount] = newProduct;
    (*productCount)++;
}

void deleteProduct(struct Product* products, int* productCount, const char* owner) {
    int id, found = 0;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *productCount; i++) {
        if (products[i].product_ID == id && strcmp(products[i].product_Owner, owner) == 0) {
            found = 1;
            for (int j = i; j < *productCount - 1; j++) {
                products[j] = products[j + 1];
            }
            (*productCount)--;
            printf("Product deleted successfully.\n");
            return;
        }
    }
    if (!found) {
        printf("Product not found or you don't have permission to delete it.\n");
    }
}

void updateProduct(struct Product* products, int productCount, const char* owner) {
    int id, found = 0;
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
            printf("Product updated successfully.\n");
            return;
        }
    }
    if (!found) {
        printf("Product not found or you don't have permission to update it.\n");
    }
}

void viewProducts(struct Product* products, int productCount, const char* owner) {
    printf("\nYour Products:\n");
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].product_Owner, owner) == 0) {
            printf("ID: %d, Name: %s, Quantity: %d, Price: %d\n",
                   products[i].product_ID,
                   products[i].product_Name,
                   products[i].product_Quantity,
                   products[i].product_Price);
        }
    }
}


int main() {
    srand(time(0));

    int originalSize = 1;  // Start with size 1 to account for root admin
    int expandedSize = 0;
    int choice = 0;
    int reset = 0;  // Variable to check whether user wants to reset password

    char adminUsername[50], adminPassword[50];
    char adminCode[50];

    // Allocate memory for at least one Admin (root admin)
    struct Admin *admin = (struct Admin *)malloc(originalSize * sizeof(struct Admin));
    if (admin == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    struct Admin *temp;
    struct Product *product = (struct Product *)malloc(originalSize * sizeof(struct Product));
    int productCount = 0;

    printf("Fresh session: Active");
    printf("\nCreating new login for Admin...\n");

    printf("\nEnter Admin username: ");
    scanf("%29s", admin[0].admin_Username);  // Root admin (first user)

    // Generating random code and storing it as a string
    int code = randomDigitGenerator();
    snprintf(admin[0].admin_Code, 30, "%d", code);

    printf("Enter new Password: ");
    scanf("%29s", admin[0].admin_Password);

    printf("\n\n-----------ROOT ADDED----------");
    printf("\nUsername: %s", admin[0].admin_Username);
    printf("\nCode: %s\nUse this code to reset password\nDON'T SHARE IT!", admin[0].admin_Code);
    printf("\n--------------------------------");

    // Reset choice buffer [just in case]
    choice = 0;
    int loggedIn = 0;  // flag to track if user is logged in

    do {
        printf("\n\n-------Choose an option-------");
        printf("\n\t1 = Register new User");
        printf("\n\t2 = Login");
        printf("\n\t3 = EXIT");
        printf("\n\t Choose: ");
        scanf("%d", &choice);
        printf("\n------------------------------");

        switch (choice) {
            case 1:
                // Increment the original size to allocate space for the new user
                originalSize++;

                // Re-allocate memory to hold one more user
                temp = realloc(admin, originalSize * sizeof(struct Admin));

                // Check if reallocation was successful
                if (temp == NULL) {
                    printf("Memory allocation failed!\n");
                    exit(1);  // Exit if allocation fails
                } else {
                    admin = temp;  // Assign the newly allocated memory back to admin
                }

                printf("\nEnter Admin username: ");
                scanf("%29s", admin[originalSize - 1].admin_Username);

                // Generating random code and storing it as a string
                code = randomDigitGenerator();
                snprintf(admin[originalSize - 1].admin_Code, 30, "%d", code);

                printf("Enter new Password: ");
                scanf("%29s", admin[originalSize - 1].admin_Password);

                printf("\n\n------------ADDED------------");
                printf("\nUsername: %s", admin[originalSize - 1].admin_Username);
                printf("\nCode: %s\nUse this code to reset password\nDON'T SHARE IT!", admin[originalSize - 1].admin_Code);
                printf("\n-------------------------------");

                break;

            case 2:
                reset = 0;
                printf("\n\n------------LOGIN------------");
                printf("\n\tUsername: ");
                scanf("%s", adminUsername);
                printf("\n(ENTER 'RES' TO RESET PASSWORD)");
                printf("\n\tPassword: ");
                scanf("%s", adminPassword);

                if (strcmp(adminPassword, "RES") == 0) {
                    printf("\n-------PASSWORD RESET---------");
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
                        printf("\n-------PASSWORD RESET---------");
                    } else {
                        printf("\nUsername or Code incorrect!");
                        printf("\n-------PASSWORD RESET---------");
                    }
                } else {
                    for (int i = 0; i < originalSize; i++) {
                        if (strcmp(admin[i].admin_Username, adminUsername) == 0 && strcmp(admin[i].admin_Password, adminPassword) == 0) {
                            loggedIn = 1;  // Set logged in flag
                            int innerChoice = 0;

                            while (loggedIn) {
                                printf("\nLogin Successful");
                                printf("\n---------PRODUCT----------");
                                printf("\n1. Add Product\n2. Delete Product\n3. Update Product\n4. View Products\n5. Log-Out\n");
                                printf("Enter your choice: ");
                                scanf("%d", &innerChoice);

                                switch (innerChoice) {
                                    case 1:
                                        addProduct(product, &productCount, admin->admin_Username);
                                        break;
                                    case 2:
                                        deleteProduct(product, &productCount, admin->admin_Username);
                                        break;
                                    case 3:
                                        updateProduct(product, productCount, admin->admin_Username);
                                        break;
                                    case 4:
                                        viewProducts(product, productCount, admin->admin_Username);
                                        break;
                                    case 5:
                                        printf("\n-----------LOGGING OUT------------");
                                        loggedIn = 0;  // Exit inner loop
                                        break;
                                    default:
                                        printf("Invalid choice! Try again.\n");
                                }
                            }
                        }
                    }
                }
                break;

            case 3:
                choice = 3;
                printf("\n\n--------------Exiting...");
                break;

            default:
                printf("\nInvalid option, please try again.");
                break;

        } // SWITCH END

    } while (choice != 3);


    free(admin);

    return 0;
}
