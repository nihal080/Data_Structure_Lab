#include <stdio.h>
#include <stdlib.h>

#define U_Size 26

char univ_set[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
                     'n','o','p','q','r','s','t','u','v','w','x','y','z'};

char set1[26], set2[26];
int bit_vec1[26], bit_vec2[26], result[26];

void initializeSet()
{
    for (int i = 0; i < U_Size; i++) {
        bit_vec1[i] = 0;
        bit_vec2[i] = 0;
        result[i] = 0;
    }
}

void bitVector(char arr[], int bit[26], int num)
{
    for (int i = 0; i < num; i++) {
        char c = arr[i];
        if (c >= 'a' && c <= 'z') {
            int index = c - 'a';
            bit[index] = 1;
        }
    }
}

void printBitVector(int bit[26]) {
    for (int i = 0; i < U_Size; i++) {
        printf("%d", bit[i]);
    }
    printf("\n");
}

void printSet(int bit[26]) {
    printf("{ ");
    for (int i = 0; i < U_Size; i++) {
        if (bit[i]) {
            printf("%c ", univ_set[i]);
        }
    }
    printf("}\n");
}

void displayResult(const char *operation, int bit[26]) {
    printf("%s:\n", operation);
    printf("set : ");
    printSet(bit);
    printf("bit vector: ");
    printBitVector(bit);
}

void unionSets(int set1[], int set2[], int result[]) {
    for (int i = 0; i < U_Size; i++) {
        result[i] = set1[i] | set2[i];
    }
}

void intersectionSets(int set1[], int set2[], int result[]) {
    for (int i = 0; i < U_Size; i++) {
        result[i] = set1[i] & set2[i];
    }
}

void complementSet(int set[], int result[]) {
    for (int i = 0; i < U_Size; i++) {
        result[i] = !set[i];
    }
}

void differenceSets(int set1[], int set2[], int result[]) {
    for (int i = 0; i < U_Size; i++) {
        result[i] = set1[i] & (!set2[i]);
    }
}

int main()
{
    int choice, num1, num2;
    initializeSet();

    printf("Enter number of elements in set1: ");
    scanf("%d", &num1);
    printf("Enter set1 elements: ");
    for (int i = 0; i < num1; i++) {
        scanf(" %c", &set1[i]);
    }

    printf("Enter number of elements in set2: ");
    scanf("%d", &num2);
    printf("Enter set2 elements: ");
    for (int i = 0; i < num2; i++) {
        scanf(" %c", &set2[i]);
    }

    bitVector(set1, bit_vec1, num1);
    bitVector(set2, bit_vec2, num2);

    choice = 0; // Initialize choice
    while (choice != 5) {
        printf("\nMenu:\n");
        printf("1. Union\n");
        printf("2. Intersection\n");
        printf("3. Difference (set1 - set2)\n");
        printf("4. Complement of a set\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
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
                displayResult("Difference (set1 - set2)", result);
                break;
            case 4:
                int setChoice;
                printf("Enter 1 for set1, 2 for set2: ");
                scanf("%d", &setChoice);
                if (setChoice == 1) 
                {
                    complementSet(bit_vec1, result);
                    printf("Complement of set1:\n");
                }
                else if (setChoice == 2) 
                {
                    complementSet(bit_vec2, result);
                    printf("Complement of set2:\n");
                }
                else {
                    printf("Invalid choice.\n");
                    break;
                }
                displayResult("Complement", result);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
