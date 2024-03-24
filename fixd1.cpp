#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Class {
    char code[30];
    char name[88];
} Class;

typedef struct Student {
    char name[80];
    char surname[90];
    int studentNumber;
    Class* courses;
    int courseCount;
} Student;

typedef struct StudentList {
    Student* students;
    int studentCount;
} StudentList;

void addClassToStudent(Class classes, Student* student) {
    // Allocates memory for a new course
    student->courses = (Class*)realloc(student->courses, (student->courseCount + 1) * sizeof(Class));

    // Checks if memory allocation was successful
    if (student->courses == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Adds the new course to the student's course list
    strcpy(student->courses[student->courseCount].code, classes.code);
    strcpy(student->courses[student->courseCount].name, classes.name);
    student->courseCount++;
}

void addStudent(StudentList* list, Student studentToBeAdded) {
    // Allocates memory for a new student
    list->students = (Student*)realloc(list->students, (list->studentCount + 1) * sizeof(Student));

    // Checks if memory allocation was successful
    if (list->students == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Adds the new student to the student list
    list->students[list->studentCount] = studentToBeAdded;
    list->studentCount++;
}

int deleteStudent(StudentList* list, int studentNumber) {
    int success = -1;
    int foundIndex = -1;

    // Find the index of the student to be deleted
    for (int a = 0; a < list->studentCount; a++) {
        if (list->students[a].studentNumber == studentNumber) {
            foundIndex = a;
            break;
        }
    }

    // If student to be deleted was found
    if (foundIndex != -1) {
        // Create a new array to hold the updated student list
        Student* updatedStudents = (Student*)malloc((list->studentCount - 1) * sizeof(Student));
        if (updatedStudents == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }

        // Copy students before the one to be deleted
        for (int a = 0; a < foundIndex; a++) {
            updatedStudents[a] = list->students[a];
        }

        // Copy students after the one to be deleted
        for (int a = foundIndex + 1; a < list->studentCount; a++) {
            updatedStudents[a - 1] = list->students[a];
        }

        // Free memory of the old student array
        free(list->students);

        // Update the student list
        list->students = updatedStudents;
        list->studentCount--;

        success = 1;
    }

    return success;
}


void printStudentList(StudentList list) {
    printf("\nSTUDENT LIST:\n");

    for (int a = 0; a < list.studentCount; a++) {
        printf("---------------------------------\n");
        printf("Student information: \n");
        printf("Name         : %s %s\n", list.students[a].name, list.students[a].surname);
        printf("Student ID   : %d\n", list.students[a].studentNumber);

        printf("Taken Courses:");
        for (int b = 0; b < list.students[a].courseCount; b++) {
            printf(" %s ", list.students[a].courses[b].code);
        }
        printf("\n---------------------------------\n");
        printf("\n");
    }
}

// Sorts students by their ID
void sort(StudentList* list) {
    for (int a = 0; a < list->studentCount - 1; a += 1) {
        for (int b = 0; b < list->studentCount - a - 1; b += 1) {
            if (list->students[b].studentNumber > list->students[b + 1].studentNumber) {
                Student temp = list->students[b];
                list->students[b] = list->students[b + 1];
                list->students[b + 1] = temp;
            }
        }
    }
}

int main() {
    Class classes[3] = {
        {"CENG 111", "Programming With C"},
        {"CENG 105", "Orientation"},
        {"CENG 241", "Object Oriented Programming"}
    };

    // Create a student list
    StudentList slist;
    slist.students = NULL;  // Initialize to NULL (no students initially)
    slist.studentCount = 0; // Initialize student count

    // Student1
    Student student1;
    strcpy(student1.name, "Kaan");
    strcpy(student1.surname, "Aydemir");
    student1.studentNumber = 2021;
    student1.courseCount = 0; // Sets course count
    student1.courses = NULL;   // Sets to NULL (no courses initially)

    // Adding courses to student
    addClassToStudent(classes[0], &student1);
    addClassToStudent(classes[2], &student1);

    // Student 2
    Student student2;
    strcpy(student2.name, "Faruk");
    strcpy(student2.surname, "Demir");
    student2.studentNumber = 2022;
    student2.courseCount = 0;
    student2.courses = NULL;

    addClassToStudent(classes[0], &student2);

    // Student 3
    Student student3;
    strcpy(student3.name, "Efe");
    strcpy(student3.surname, "Ay");
    student3.studentNumber = 2023;
    student3.courseCount = 0;
    student3.courses = NULL;

    addClassToStudent(classes[0], &student3);
    addClassToStudent(classes[1], &student3);
    addClassToStudent(classes[2], &student3);

    // Adding students to the student list
    addStudent(&slist, student1);
    addStudent(&slist, student2);
    addStudent(&slist, student3);

    printStudentList(slist); // Prints the student list

    // Sorts the student list based on student numbers
    sort(&slist);
    printf("\nSorting List\n \n");
    printStudentList(slist);

    int delstu;
    printf("Enter Student ID to be deleted:");
    scanf("%d", &delstu);

    // Deletes student
    int deleted = deleteStudent(&slist, delstu);
    if (deleted == 1) {
        printf("\nSuccessfully deleted student %d \n\n", delstu);
    } else if (deleted == -1) {
        printf("\nStudent with student number %d not found.\n", delstu);
    }

    printStudentList(slist);

    // Free memory for students and their courses
    for (int a = 0; a < slist.studentCount; a += 1) {
        free(slist.students[a].courses);
    }
    free(slist.students);

    return 0;
}

