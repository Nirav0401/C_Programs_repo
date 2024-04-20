#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

FILE *fp;  // declared as global variable
int userfound = 0;
char email[20];

struct customer {
    char name[20];
    char cname[20];
    char Email[20];
    char password[20];
    int id;
    char companyName[20];
    char issueDetail[150];
    char status[30];
} f;

void sign_up() {
    fp = fopen("new.txt", "a+");
    printf("\nEnter Your Name: ");
    scanf("%s", f.name);
    printf("Enter Your Email Id: ");
    scanf("%s", f.Email);
    printf("Enter Your Password: ");
    scanf("%s", f.password);

    fwrite(&f, sizeof(f), 1, fp);
    fclose(fp);
    printf("\nYou have successfully completed your sign up.\n");
}

void login() {
    char pass[20];
    printf("\nEnter Your Email Id: ");
    scanf("%s", email);
    printf("Enter Your Password: ");
    scanf("%s", pass);

    fp = fopen("new.txt", "r");
    while(fread(&f, sizeof(f), 1, fp)) {
        if((strcmp(f.Email, email) == 0) && (strcmp(f.password, pass) == 0)) {
            printf("\nYou have successfully logged in.\n");
            printf("Name: %s\n", f.name);
            break;
        } else {
            printf("\nInvalid Password!\n");
            Beep(800, 300);
        }
    }
    fclose(fp);
}


void Fill_Details() {
    printf("\nEnter Your Email Id: ");
    scanf("%s", email);
    fp = fopen("new.txt", "r+");
    int found = 0; // Flag to check if the email is found
    
    while(fread(&f, sizeof(f), 1, fp)) {
        if(strcmp(f.Email, email) == 0) {
            found = 1; // Set the flag to 1 if email is found
            
            printf("\nEnter Customer Id Number: ");
            scanf("%d", &f.id);
            printf("Enter the Customer Name: ");
            scanf("%s", f.cname);
            printf("Enter the Customer Company Name: ");
            scanf("%s", f.companyName);
            printf("Enter the issue being faced: ");
            scanf("%s", f.issueDetail);
            printf("Update the status of the issue: ");
            scanf("%s", f.status);
            
            fseek(fp, -sizeof(f), SEEK_CUR);
            fwrite(&f, sizeof(f), 1, fp);
            break;
        }
    }
    
    fclose(fp);
    
    if(!found) { // Check the flag
        printf("Wrong Email Input! Please Do First Sign Up!\n");
    }
}

void View_Details() {
    printf("\nEnter Your Email Id: ");
    scanf("%s", email);
    fp = fopen("new.txt", "r");
    int found = 0; // Flag to check if the email is found
    
    while(fread(&f, sizeof(f), 1, fp)) {
        if(strcmp(f.Email, email) == 0) {
            found = 1; // Set the flag to 1 if email is found
            
            printf("\nThe Customer Id Number: %d\n", f.id);
            printf("The Customer Name: %s\n", f.cname);
            printf("The Customer Company Name: %s\n", f.companyName);
            printf("The issue being faced: %s\n", f.issueDetail);
            printf("The status of the issue: %s\n", f.status);
            break;
        }
    }
    
    fclose(fp);
    
    if(!found) { // Check the flag
        printf("\nWrong Email Input! Please Do First Sign Up!\n");
    }
}

void Edit_Details() {
    int opt;
    printf("\nEnter Your Email Id: ");
    scanf("%s", email);
    fp = fopen("new.txt", "r+");
    while(fread(&f, sizeof(f), 1, fp)) {
        if(strcmp(f.Email, email) == 0) {
            printf("\nThe Customer Id Number: %d\n", f.id);
            printf("The Customer Name: %s\n", f.cname);
            printf("The Customer Company Name: %s\n", f.companyName);
            printf("The issue being faced: %s\n", f.issueDetail);
            printf("The status of the issue: %s\n", f.status);
            
            printf("\n###############################################################\n");
            printf("\nUpdate the Customer Complaint Form\n");
            printf("\nEnter Your Choice:\n");
            printf("1. Update the Customer Id\n");
            printf("2. Update the Customer Name\n");
            printf("3. Update the Customer Company Name\n");
            printf("4. Update the issue being faced\n");
            printf("5. Update the Status of the Issue\n");
            printf("------------------------------------------------\n");
            scanf("%d", &opt);
            
            switch(opt) {
                case 1:
                    printf("Edit the Customer Id Number: ");
                    scanf("%d", &f.id);
                    break;
                case 2:
                    printf("Edit the Customer Name: ");
                    scanf("%s", f.cname);
                    break;
                case 3:
                    printf("Edit Customer Company Name: ");
                    scanf("%s", f.companyName);
                    break;
                case 4:
                    printf("Edit the Issue being Faced: ");
                    scanf("%s", f.issueDetail);
                    break;
                case 5:
                    printf("Edit the Status of the Issue: ");
                    scanf("%s", f.status);
                    break;
                default:
                    printf("Invalid Input!");
                    break;
            }
            fseek(fp, -sizeof(f), SEEK_CUR);
            fwrite(&f, sizeof(f), 1, fp);
            break;
        } else {
            userfound = 0;
        }
    }
    fclose(fp);
    if(userfound == 0) {
        printf("\nWrong Email Input! Please Do First Sign Up!\n");
    }
    printf("You have successfully Updated the data.\n");
}

int main() {
    int choice;
    do {
        printf("\n\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("\n\t\t!!!!                                              !!!!\n");
        printf("\n\t\t!!!!    Welcome To the Customer Complaint Form    !!!!\n");
        printf("\n\t\t!!!!                                              !!!!\n");
        printf("\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("\n\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        printf("\n1. Sign Up\n2. Login\n3. Fill Details\n4. View Details\n5. Edit Details\n6. Exit\n\n");
        printf("Enter Your Selection to Use Customer Complaint Form: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                sign_up();
                break;
            case 2:
                login();
                break;
            case 3:
                Fill_Details();
                break;
            case 4:
                View_Details();
                break;
            case 5:
                Edit_Details();
                break;    
            case 6:
                printf("\nThanks for Registration and using our portal.\n");
                exit(0);
                break;
            default:
                printf("\nWrong Input!\n");
                exit(0);
                break;
        }
    } while(1);
    
    return 0;
}
