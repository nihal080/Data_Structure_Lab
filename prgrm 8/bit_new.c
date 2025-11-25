#include <stdio.h>
#include <stdlib.h>

#define U_SIZE 26

char univ_set[U_SIZE] = {
    'a','b','c','d','e','f','g','h','i','j','k','l','m',
    'n','o','p','q','r','s','t','u','v','w','x','y','z'
};

int bit_vec1[U_SIZE], bit_vec2[U_SIZE], result[U_SIZE];

void initializeSets() {
    for (int i = 0; i < U_SIZE; i++) {
        bit_vec1[i] = bit_vec2[i] = result[i] = 0;
    }
}

void buildBitVector(char arr[], int bit[], int num) {
    for (int i = 0; i < num; i++) {
        char c = arr[i];
        bit[c - 'a'] = 1;
    }
}

void printBitVector(int bit[]) {
    for (int i = 0; i < U_SIZE; i++)
        printf("%d", bit[i]);
    printf("\n");
}

void printSet(int bit[]) {
    printf("{ ");
    for (int i = 0; i < U_SIZE; i++) {
        if (bit[i])
            printf("%c ", univ_set[i]);
    }
    printf("}\n");
}

void displayResult(const char *operation, int bit[]) {
    printf("\n%s:\n", operation);
    printf("Set: ");
    printSet(bit);
    printf("Bit vector: ");
    printBitVector(bit);
}

void unionSets(int a[], int b[], int r[]) {
    for (int i = 0; i < U_SIZE; i++)
        r[i] = a[i] | b[i];
}

void intersectionSets(int a[], int b[], int r[]) {
    for (int i = 0; i < U_SIZE; i++)
        r[i] = a[i] & b[i];
}

void differenceSets(int a[], int b[], int r[]) {
    for (int i = 0; i < U_SIZE; i++)
        r[i] = a[i] & (!b[i]);
}

void complementSet(int a[], int r[]) {
    for (int i = 0; i < U_SIZE; i++)
        r[i] = !a[i];
}

void readSet(char set[], int count, const char *setName) {
    printf("Enter %d elements for %s (a–z): ", count, setName);

    int validCount = 0;
    while (validCount < count) {
        char c;
        scanf(" %c", &c);

        if (c < 'a' || c > 'z') {
            printf("Invalid input '%c' — only a–z allowed.\n", c);
            continue;
        }

        set[validCount] = c;
        validCount++;
    }
}

int main() {
    int choice, num1, num2;
    char set1[U_SIZE], set2[U_SIZE];

    initializeSets();

    printf("Enter number of elements in Set 1: ");
    scanf("%d", &num1);
    readSet(set1, num1, "Set 1");

    printf("Enter number of elements in Set 2: ");
    scanf("%d", &num2);
    readSet(set2, num2, "Set 2");

    buildBitVector(set1, bit_vec1, num1);
    buildBitVector(set2, bit_vec2, num2);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Union\n");
        printf("2. Intersection\n");
        printf("3. Difference (Set1 - Set2)\n");
        printf("4. Complement\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting...\n");
            break;
        }

        switch (choice) {
            case 1:
                unionSets(bit_vec1, bit_vec2, result);
                displayResult("Union", result);
                break;

            case 2:
                intersectionSets(bit_vec1, bit_vec2, result);
                displayResult("Intersection", result);
                break;

            case 3:
                differenceSets(bit_vec1, bit_vec2, result);
                displayResult("Difference (Set1 - Set2)", result);
                break;

            case 4: {
                int setChoice;
                printf("Complement of which set? (1 or 2): ");
                scanf("%d", &setChoice);

                if (setChoice == 1) 
                {
                    complementSet(bit_vec1, result);
                    displayResult("Complement of Set 1", result);
                } else if (setChoice == 2) {
                    complementSet(bit_vec2, result);
                    displayResult("Complement of Set 2", result);
                } else {
                    printf("Invalid choice!\n");
                }
                break;
            }

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

