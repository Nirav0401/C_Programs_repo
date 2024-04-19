/*
Problem Statement: Write a program to build a simple Software for Student Information Management System which can perform the following operations:

Store the First name of the student.
Store the Last name of the student.
Store the unique Roll number for every student.
Store the CGPA of every student.
Store the courses registered by the student.
Approach: The idea is to form an individual functions for every operation. All the functions are unified together to form software.

Add Student Details: Get data from user and add a student to the list of students. While adding the students into the list, check for the uniqueness of the roll number.
Find the student by the given roll number: This function is to find the student record for the given roll number and print the details.
Find the student by the given first name: This function is to find all the students with the given first name and print their details.
Find the students registered in a course: This function is to find all the students who have registered for a given course.
Count of Students: This function is to print the total number of students in the system
Delete a student: This function is to delete the student record for the given roll number.
Update Student: This function is to update the student records. This function does not ask for new details for all fields but the user should be able to pick and choose what
he wants to update.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int i = 0;

struct student {
    char fname[30];
    char lname[30];
    int rollno;
    float cgpa;
    int cid;
} st[50];

int add_s() {
    FILE *fp = fopen("student.dat", "a+");
    printf("Enter the student Details\n");
    
    printf("Enter the student First name\n");
    scanf("%s", st[i].fname);
    printf("Enter the student Last name\n");
    scanf("%s", st[i].lname);
    printf("Enter the Roll No of the student\n");
    scanf("%d", &st[i].rollno);
    printf("Enter the CGPA of the student\n");
    scanf("%f", &st[i].cgpa);
    printf("Enter the Course Id of the student\n");
    scanf("%d", &st[i].cid);
    fwrite(&st[i], sizeof(struct student), 1, fp);
    
    fclose(fp);
    i++;
}

int roll_s() {
    int a;
    printf("Enter the Roll No\n");
    scanf("%d", &a);
    FILE *fp = fopen("student.dat", "r");
    while(fread(&st[i], sizeof(struct student), 1, fp)) {
        if(a == st[i].rollno) {
            printf("Student First Name %s\n", st[i].fname);
            printf("Student Last Name %s\n", st[i].lname);
            printf("Student CGPA %.2f\n", st[i].cgpa);
            printf("Student C'ID %d\n", st[i].cid);
        }
        else
        printf("Roll Number Not Found!!\n");
    }
    fclose(fp);
}

int fname_s() {
    char name[30];
    printf("Enter the first name of the student\n");
    scanf("%s", name);
    FILE *fp = fopen("student.dat", "r");
    while(fread(&st[i], sizeof(struct student), 1, fp)) {
        if(!strcmp(st[i].fname, name)) {
            printf("Student roll no %d\n", st[i].rollno);
            printf("Student Last Name %s\n", st[i].lname);
            printf("Student CGPA %.2f\n", st[i].cgpa);
            printf("Student C'ID %d\n", st[i].cid);
        }
        else
        printf("%s Not Found!!\n", name);
    }
    fclose(fp);
}

int C_id_s() {
    int C_ID;
    printf("Enter the Course Id of the student\n");
    scanf("%d", &C_ID);
    FILE *fp = fopen("student.dat", "r");
    while(fread(&st[i], sizeof(struct student), 1, fp)) {
        if(st[i].cid == C_ID) {
            printf("Student First Name %s\n", st[i].fname);
            printf("Student Last Name %s\n", st[i].lname);
            printf("Student Roll No %d\n", st[i].rollno);
            printf("Student CGPA %.2f\n", st[i].cgpa);
        }
        else
        printf("Course Id Not Found!!\n");
    }
    fclose(fp);
}

void tot_s() {
    int count = 0;
    
    FILE *fp = fopen("student.dat", "r");
    while(fread(&st[i], sizeof(struct student), 1, fp)) {
        count++;
    }
    fclose(fp);
    
    printf("The total number of Student is %d\n", count);
    printf("You can have a max of 50 students\n");
    printf("You can have %d more students\n", 50 - count);
}

void delete_s() {
    int rol;
    printf("Enter the RollNo which you want to delete\n");
    scanf("%d", &rol);
    
    FILE *fp = fopen("student.dat", "r");
    FILE *temp_fp = fopen("temp.dat", "w"); // Temporary file to hold records
    
    int found = 0;
    while(fread(&st[i], sizeof(struct student), 1, fp)) {
        if (rol == st[i].rollno) {
            found = 1;
            continue; // Skip writing this record to the temporary file
        }
        fwrite(&st[i], sizeof(struct student), 1, temp_fp);
    }
    
    fclose(fp);
    fclose(temp_fp);
    
    if (found) {
        remove("student.dat"); // Delete the original file
        rename("temp.dat", "student.dat"); // Rename the temporary file to the original name
        i--; // Decrease the student count
        printf("The Roll Number is removed Successfully\n");
    } else {
        printf("Roll Number not found\n");
    }
}

void update_s() {
    int x, y;
    printf("Enter the rollno to update the list\n");
    scanf("%d", &x);
    
    FILE *fp = fopen("student.dat", "r");
    for(int j = 0; j < i; j++) {
        if (x == st[j].rollno) {
            printf("Enter your choice\n");
            printf("1. Update the First name\n2. update the Last name\n3. update the roll no\n4. update the CGPA\n5. update the course Id\n");
            scanf("%d", &y);
            
            switch(y) {
                case 1:
                    printf("Enter the first new name\n");
                    scanf("%s", st[j].fname);
                    break;
                case 2:
                    printf("Enter the last new name\n");
                    scanf("%s", st[j].lname);
                    break;
                case 3:
                    printf("Enter the new roll no\n");
                    scanf("%d", &st[j].rollno);
                    break;
                case 4:
                    printf("Enter the new CGPA\n");
                    scanf("%f", &st[j].cgpa);
                    break;
                case 5:
                    printf("Enter the new course Id\n");
                    scanf("%d", &st[j].cid);
                    break;
            }
            fclose(fp);
            fp = fopen("student.dat", "w");
            fwrite(st, sizeof(struct student), i, fp);
            fclose(fp);
            printf("Updated Successfully\n");
            break;
        }
    }
}

int main() {
    int choice;

    while(1) {
        printf("\t\tThe Student Management Portal\t\t\n");
        printf("\t----------------------------------------------\t\n");
        printf("1. Add Student Details\n");
        printf("2. Find the student by Roll No\n");
        printf("3. Find the student by First Name\n");
        printf("4. Find the student by Course Id\n");
        printf("5. Count of total student\n");
        printf("6. Delete the student from the list\n");
        printf("7. Update the details of the student\n");
        printf("8. Exit from the operation\n");

        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_s();
                break;
            case 2:
                roll_s();
                break;
            case 3:
                fname_s();
                break;
            case 4:
                C_id_s();
                break;
            case 5:
                tot_s();
                break;
            case 6:
                delete_s();
                break;
            case 7:
                update_s();
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
