#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOOD_GROUPS 100

struct BloodGroup{
    char bloodType[10];
    int quantity;
};

void addBloodGroup(struct BloodGroup *bloodGroups, int *count){
   if(*count >= MAX_BLOOD_GROUPS){
    printf(" Cannot add more blood groups limit reached\n");
    return;
    }
    printf("Enter blood type: ");
    scanf("%s", bloodGroups[*count].bloodType);
    printf("Enter quantity: ");
    scanf("%d", &bloodGroups[*count].quantity);
    (*count)++;
    printf("Blood group added successfully.\n");
}

void deleteBloodGroup(struct BloodGroup *bloodGroups, int *count,const char *bloodType){
    int index = searchBloodGroup(bloodGroups, *count, bloodType);
    if (index == -1){
        printf("Blood group not found.\n");
        return;
}

    for (int i = index; i < *count - 1; i++) {
        bloodGroups[i] = bloodGroups[i + 1];
    }

    (*count)--;
    printf("Blood group deleted successfully.\n");
}

int searchBloodGroup(struct BloodGroup *bloodGroups, int count,const char *bloodType){
    for (int i = 0; i < count; i++){
        if (strcmp(bloodGroups[i].bloodType, bloodType) == 0){
            return i;
        }
    }
    return -1;
 }

void createBloodGroupPackage(struct BloodGroup *bloodGroups, int count,const char *packageDetails){
    printf("Creating blood group package with details: %s\n", packageDetails);

    displayBloodGroups(bloodGroups, count);
}

void displayBloodGroups(struct BloodGroup *bloodGroups, int count) {
    if (count == 0) {
        printf("No blood groups available.\n");
        return;
    }

    printf("Blood Groups:\n");
    for (int i = 0; i < count; i++) {
        printf("Blood Type: %s, Quantity: %d\n", bloodGroups[i].bloodType, bloodGroups[i].quantity);
    }
}

void updateBloodQuantity(struct BloodGroup *bloodGroups, int count,const char *bloodType, int quantity) {
    int index = searchBloodGroup(bloodGroups, count, bloodType);
    if (index == -1) {
        printf("Blood group not found.\n");
        return;
    }

    bloodGroups[index].quantity = quantity;
    printf("Blood quantity updated successfully.\n");
}

int main() {
 struct BloodGroup bloodGroups[MAX_BLOOD_GROUPS];
 int count = 0;
 int choice;
 char bloodType[10];
 int quantity;
while (1) {
    printf("\nBlood Bank Management System\n");
    printf("1. Add Blood Group\n");
    printf("2. Delete Blood Group\n");
    printf("3. Search Blood Group\n");
    printf("4. Display Blood Groups\n");
    printf("5. Update Blood Quantity\n");
    printf("6. Create Blood Group Package\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

switch(choice){
 case 1:
     addBloodGroup(bloodGroups, &count);
     break;
 case 2:
     printf("Enter blood type to delete: ");
     scanf("%s", bloodType);
     deleteBloodGroup(bloodGroups, &count, bloodType);
     break;
 case 3:
     printf("Enter blood type to search: ");
     scanf("%s", bloodType);
    if (searchBloodGroup(bloodGroups, count, bloodType) != -1) {
    printf("Blood group found.\n");
     } else {
     printf("Blood group not found.\n");
    }
     break;
 case 4:
     displayBloodGroups(bloodGroups, count);
     break;
 case 5:
     printf("Enter blood type to update: ");
     scanf("%s", bloodType);
     printf("Enter new quantity: ");
     scanf("%d", &quantity);
     updateBloodQuantity(bloodGroups, count, bloodType, quantity);
     break;
 case 6:
     createBloodGroupPackage(bloodGroups, count, "PackageDetails");
     break;
 case 7:
     exit(0);
 default:
    printf("Invalid choice!\n");
  }
 }
return 0;
}
