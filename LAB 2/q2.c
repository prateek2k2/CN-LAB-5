#include <stdio.h>
#include <string.h>

struct dob {
    int day;
    int month;
    int year;
};

struct student_info {
    int roll_no;
    char name[20];
    float CGPA;
    struct dob age;
};

void printStudentInfoValue(struct student_info student) {
    printf("Roll No: %d\n", student.roll_no);
    printf("Name: %s\n", student.name);
    printf("CGPA: %.2f\n", student.CGPA);
    printf("Date of Birth: %d/%d/%d\n", student.age.day, student.age.month, student.age.year);
}
void printStudentInfoAddress(struct student_info *student) {
    printf("Call-by-Address:\n");
    printf("Roll No: %d\n", student->roll_no);
    printf("Name: %s\n", student->name);
    printf("CGPA: %.2f\n", student->CGPA);
    printf("Date of Birth: %d/%d/%d\n", student->age.day, student->age.month, student->age.year);
}

int main() {
    struct student_info student1;
    int r,d,m,y;
    float cg;
    printf("Enter Roll Number: ");
    scanf("%d",&r);
    student1.roll_no = r;
    strcpy(student1.name,"Prateek Raj");
    printf("\nEnter CGPA: ");
    scanf("%f",&cg);
    student1.CGPA = cg;
    printf("\nEnter DAY of DOB: ");
    scanf("%d",&d);
    printf("\nEnter MONTH of DOB: ");
    scanf("%d",&m);
    printf("\nEnter YEAR of DOB: ");
    scanf("%d",&y);
    student1.age.day = d;
    student1.age.month = m;
    student1.age.year = y;
    printStudentInfoValue(student1);
    printf("\n");
    printStudentInfoAddress(&student1);

    return 0;
}
