//ID:0182420012101168
#include <stdio.h>
#define MAX_SIZE 100

void insert(int arr[], int *n);
void update(int arr[], int n);
void delete(int arr[], int *n);
void sort(int arr[], int n);
void search(int arr[], int n);
void display(int arr[], int n);

int main() {
    int arr[MAX_SIZE], size = 0, choice;

    while (1) {
        printf("\n--- Array Manager ---\n");
        printf("1. Insert Element\n");
        printf("2. Update Element\n");
        printf("3. Delete Element\n");
        printf("4. Sort Array\n");
        printf("5. Search Element\n");
        printf("6. Display Array\n");
        printf("0. Exit\n");
        printf("Select Option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(arr, &size); break;
            case 2: update(arr, size); break;
            case 3: delete(arr, &size); break;
            case 4: sort(arr, size); break;
            case 5: search(arr, size); break;
            case 6: display(arr, size); break;
            case 0: printf("Program Terminated.\n"); return 0;
            default: printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}

// Insert Function
void insert(int arr[], int *n) {
    if (*n >= MAX_SIZE) {
        printf("Array limit reached.\n");
        return;
    }
    int val;
    printf("Enter value to insert: ");
    scanf("%d", &val);
    arr[*n] = val;
    (*n)++;
    printf("Inserted successfully.\n");
}

// Update Function
void update(int arr[], int n) {
    int pos, val;
    printf("Enter position to update (0 to %d): ", n - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= n) {
        printf("Invalid index.\n");
        return;
    }
    printf("Enter new value: ");
    scanf("%d", &val);
    arr[pos] = val;
    printf("Updated successfully.\n");
}

// Delete Function
void delete(int arr[], int *n) {
    int pos;
    printf("Enter position to delete (0 to %d): ", *n - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= *n) {
        printf("Invalid index.\n");
        return;
    }
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Deleted successfully.\n");
}

// Sort Function
void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    printf("Array sorted in ascending order.\n");
}


void search(int arr[], int n) {
    int key, found = 0;
    printf("Enter value to search: ");
    scanf("%d", &key);
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Found at position %d.\n", i);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Value not found.\n");
}


void display(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Current Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
