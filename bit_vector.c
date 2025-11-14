#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define U_Size 26

void createBitVector(char set[], int bit_vector[]) {
    memset(bit_vector, 0, U_Size * sizeof(int));
    for (int i = 0; set[i] != '\0'; i++) {
        if (isalpha(set[i])) {
            bit_vector[tolower(set[i]) - 'a'] = 1;
        }
    }
}

void printBitVector(int bit_vector[], const char *label) {
    printf("%s (Bits): ", label);
    for (int i = 0; i < U_Size; i++) {
        printf("%d", bit_vector[i]);
    }
    printf("\n");

    printf("%s (Letters): ", label);
    for (int i = 0; i < U_Size; i++) {
        if (bit_vector[i]) {
            printf("%c ", 'a' + i);
        }
    }
    printf("\n");
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
        result[i] = set1[i] & !set2[i];
    }
}

int main() {
    char set1_str[U_Size + 1], set2_str[U_Size + 1];
    int set1_bit[U_Size], set2_bit[U_Size], result[U_Size];
    int choice = 0; // Initialize choice

    printf("Enter elements for Set 1 (lowercase letters only): ");
    scanf("%s", set1_str);
    printf("Enter elements for Set 2 (lowercase letters only): ");
    scanf("%s", set2_str);

    createBitVector(set1_str, set1_bit);
    createBitVector(set2_str, set2_bit);

    printf("\n");
    printBitVector(set1_bit, "Set 1");
    printBitVector(set2_bit, "Set 2");

    while (choice != 5) {
        printf("\nOperations:\n");
        printf("1. Union\n");
        printf("2. Intersection\n");
        printf("3. Complement\n");
        printf("4. Difference (Set1 - Set2)\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                unionSets(set1_bit, set2_bit, result);
                printf("\nUnion:\n");
                printBitVector(result, "Result");
                break;
            case 2:
                intersectionSets(set1_bit, set2_bit, result);
                printf("\nIntersection:\n");
                printBitVector(result, "Result");
                break;
            case 3:
                complementSet(set1_bit, result);
                printf("\nComplement of Set 1:\n");
                printBitVector(result, "Set 1 Complement");
                complementSet(set2_bit, result);
                printf("\nComplement of Set 2:\n");
                printBitVector(result, "Set 2 Complement");
                break;
            case 4:
                differenceSets(set1_bit, set2_bit, result);
                printf("\nDifference (Set1 - Set2):\n");
                printBitVector(result, "Set1 - Set2");
                differenceSets(set2_bit, set1_bit, result);
                printf("\nDifference (Set2 - Set1):\n");
                printBitVector(result, "Set2 - Set1");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
