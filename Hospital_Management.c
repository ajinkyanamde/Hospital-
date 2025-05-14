#include <stdio.h>
#include <string.h>

#define MAX 100

int ids[MAX];
char names[MAX][50];
int ages[MAX];
char genders[MAX][10];
char diseases[MAX][50];
int count = 0;

// Function to clear input buffer
void clearInputBuffer() {
    while (getchar() != '\n');
}

void addPatient() {
    if (count >= MAX) {
        printf("Patient list is full!\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &ids[count]);
    clearInputBuffer();  // clear buffer after number input

    printf("Enter Name: ");
    scanf(" %[^\n]", names[count]);

    printf("Enter Age: ");
    scanf("%d", &ages[count]);
    clearInputBuffer();

    printf("Enter Gender: ");
    scanf(" %s", genders[count]);
    clearInputBuffer();

    printf("Enter Disease: ");
    scanf(" %[^\n]", diseases[count]);

    count++;
    printf("Patient added successfully!\n");
}

void viewPatients() {
    if (count == 0) {
        printf("No patients available.\n");
        return;
    }
int i=0;
    for (i = 0; i < count; i++) {
        printf("\nID: %d\nName: %s\nAge: %d\nGender: %s\nDisease: %s\n",
               ids[i], names[i], ages[i], genders[i], diseases[i]);
    }
}

void searchPatient() {
    int id, found = 0;
    printf("Enter Patient ID to search: ");
    scanf("%d", &id);
    clearInputBuffer();
int i=0;
    for (i = 0; i < count; i++) {
        if (ids[i] == id) {
            printf("\nFound!\nID: %d\nName: %s\nAge: %d\nGender: %s\nDisease: %s\n",
                   ids[i], names[i], ages[i], genders[i], diseases[i]);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Patient not found.\n");
}

void deletePatient() {
    int id, index = -1;
    printf("Enter Patient ID to delete: ");
    scanf("%d", &id);
    clearInputBuffer();
int i=0;
    for (i = 0; i < count; i++) {
        if (ids[i] == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Patient not found.\n");
        return;
    }
int j=index;

    for (j = index; j < count - 1; j++) {
        ids[j] = ids[j + 1];
        strcpy(names[j], names[j + 1]);
        ages[j] = ages[j + 1];
        strcpy(genders[j], genders[j + 1]);
        strcpy(diseases[j], diseases[j + 1]);
    }

    count--;
    printf("Patient deleted.\n");
}

void editPatient() {
    int id, index = -1;
    printf("Enter Patient ID to edit: ");
    scanf("%d", &id);
    clearInputBuffer();
int i=0;

    for (i = 0; i < count; i++) {
        if (ids[i] == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Patient not found.\n");
        return;
    }

    printf("Enter new Name: ");
    scanf(" %[^\n]", names[index]);

    printf("Enter new Age: ");
    scanf("%d", &ages[index]);
    clearInputBuffer();

    printf("Enter new Gender: ");
    scanf(" %s", genders[index]);
    clearInputBuffer();

    printf("Enter new Disease: ");
    scanf(" %[^\n]", diseases[index]);

    printf("Patient updated.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Hospital Management ---\n");
        printf("1. Add Patient\n");
        printf("2. View All Patients\n");
        printf("3. Search Patient\n");
        printf("4. Delete Patient\n");
        printf("5. Edit Patient\n");
        printf("6. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1: addPatient(); break;
            case 2: viewPatients(); break;
            case 3: searchPatient(); break;
            case 4: deletePatient(); break;
            case 5: editPatient(); break;
            case 6: 
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

