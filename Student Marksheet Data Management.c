#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct st {
	char name[50], rollno[10];
	int sub1;
	int sub2;
	int sub3;
	int sub4;
	int sub5;
	float tot, avg;
} student[55];

int total_marks(struct st st) {
	st.tot = (st.sub1 + st.sub2 + st.sub3 + st.sub4 + st.sub5);
	return st.tot;
}

int marks_persentage(struct st st) {
	return (st.tot/5);
}

int main() {
	FILE *fp;
	struct st st[55];   
	int num;
	int choice;

	do {
		printf("\n\t\t\t\tWelcome to the student data portal\t\t\n");
		printf("\n\t\t\t##################################################\t\t\n");
		printf("\n\n1. Enter the student marks data\n");
		printf("2. View Student marksheet\n");
		printf("3. Topper student list\n");
		printf("\nEnter your choice\n");
		scanf("%d", &choice);
		fgetc(stdin);

		switch(choice) {
			case 1: {
				system("cls");

				printf("How many students data do you want to add\n");
				scanf("%d", &num);
				fp = fopen("marksheet.dat", "w"); // Open in write mode
				for(int i = 0; i < num; i++) {
					printf("\nEnter the Student Name\n");
					scanf("%s", st[i].name);
					printf("Enter the Student Roll No.\n");
					scanf("%s", st[i].rollno);
					printf("Enter the Maths marks\n");
					scanf("%d", &st[i].sub1);
					printf("Enter the Science marks\n");
					scanf("%d", &st[i].sub2);
					printf("Enter the Social Science marks\n");
					scanf("%d", &st[i].sub3);
					printf("Enter the English marks\n");
					scanf("%d", &st[i].sub4);
					printf("Enter the Hindi marks\n");
					scanf("%d", &st[i].sub5);
				}

				if(fp != NULL) {
					fwrite(st, sizeof(struct st), num, fp);
					fclose(fp);
					printf("Data saved successfully.\n");
				} else {
					printf("Failed to open the file.\n");
				}
			}
			break;
			case 2: {
		    system("cls");
		    printf("How many students data do you want to view\n");
		    scanf("%d", &num);
		    fp = fopen("marksheet.dat", "r");
		    if(fp != NULL) {
		        for(int i = 0; i < num; i++) {
		            fread(&st[i], sizeof(struct st), 1, fp);
		            printf("The Record of the Student marksheet\n\n");
		            printf("Student Name %s\t\tStudent RollNo %s\n\n", st[i].name, st[i].rollno);
		            printf("\t\tSubject\t\t\n\n");
		            printf("The Maths subject marks is : %d\n", st[i].sub1);
		            printf("The Science subject marks is : %d\n", st[i].sub2);
		            printf("The Social Science subject marks is : %d\n", st[i].sub3);
		            printf("The English subject marks is : %d\n", st[i].sub4);
		            printf("The Hindi subject marks is : %d\n\n", st[i].sub5);
		            
		            st[i].tot = total_marks(st[i]);
		            printf("The Total marks out of 500 is : %.2f\n\n", st[i].tot);
		            
		            st[i].avg = marks_persentage(st[i]);
		            printf("The percentage is : %.2f\n\n", st[i].avg);
		        }
		        // Reset the file pointer to the beginning
		        rewind(fp);
		        fclose(fp);
			    } else {
			        printf("Failed to open the file.\n");
			    }
			}
			break;
			case 3: {
			    system("cls");
			    fp = fopen("marksheet.dat", "r");
			    if(fp != NULL) {
			        for(int i = 0; i < num; i++) {
			            fread(&st[i], sizeof(struct st), 1, fp);
			            
			            // Calculate the average before checking conditions
			            st[i].tot = total_marks(st[i]);
			            st[i].avg = marks_persentage(st[i]);
			            
			            if(st[i].avg >= 90) {
			                printf("Student Name %s\t\tTotal Achieved Percentage %.2f\n", st[i].name, st[i].avg);
			            } else if(st[i].avg > 80) {
			                printf("Student Name %s\t\tTotal Achieved Percentage %.2f\n", st[i].name, st[i].avg);
			            } else if(st[i].avg > 70) {
			                printf("Student Name %s\t\tTotal Achieved Percentage %.2f\n", st[i].name, st[i].avg);
			            } else if(st[i].avg > 35) {
			                printf("Passed Student Name %s\t\tTotal Achieved Percentage %.2f\n", st[i].name, st[i].avg);
			            } else {
			                printf("Failed Student Name %s\t\tTotal Achieved Percentage %.2f\n", st[i].name, st[i].avg);
			            }
			            
			        }
			        // Reset the file pointer to the beginning
			        fseek(fp, 0, SEEK_SET);
			        fclose(fp);
			    } else {
			        printf("Failed to open the file.\n");
			    }
			}
			break;
		}
	} while(1);
	return 0;
}
