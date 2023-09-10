#include <stdio.h>

struct dob {
    int day;
    int month;
    int year;
};

struct student_info {
    int roll_no;
    char name[50];
    float CGPA;
    struct dob age;
};

void print_by_value(struct student_info s);
void print_by_address(struct student_info *s);

int main() {
    struct student_info s1;
    
    printf("Enter the roll number: ");
    scanf("%d", &s1.roll_no);
    printf("Enter the name: ");
    scanf("%s", s1.name);
    printf("Enter the CGPA: ");
    scanf("%f", &s1.CGPA);
    printf("Enter the date of birth (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &s1.age.day, &s1.age.month, &s1.age.year);
    
    print_by_value(s1);
    print_by_address(&s1);
    
    return 0;
}

void print_by_value(struct student_info s) {
    printf("Roll number: %d\n", s.roll_no);
    printf("Name: %s\n", s.name);
    printf("CGPA: %.2f\n", s.CGPA);
    printf("Date of birth: %d/%d/%d\n", s.age.day, s.age.month, s.age.year);
}

void print_by_address(struct student_info *s) {
    printf("Roll number: %d\n", s->roll_no);
    printf("Name: %s\n", s->name);
    printf("CGPA: %.2f\n", s->CGPA);
    printf("Date of birth: %d/%d/%d\n", s->age.day, s->age.month, s->age.year);
}
