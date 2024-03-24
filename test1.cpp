#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Class {
	
    char code[10];
    char name[50];
    
} Class;

typedef struct Student {
	
    char name[50];
    char surname[50];
    int studentNumber;
    Class* courses;
    int courseCount;
    
} Student;

typedef struct StudentList {
   
    Student* students;
	int studentCount;
	
} StudentList;

void addClassToStudent(Class classes, Student* student) {
	
   	//Allocates memory for a new course
    student->courses = (Class*)realloc(student->courses, (student->courseCount + 1) * sizeof(Class));

    //Checks if memory allocation was successful
    if (student->courses == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

   	//Adds the new course to the student's course list
    strcpy(student->courses[student->courseCount].code, classes.code);
    strcpy(student->courses[student->courseCount].name, classes.name);
    student->courseCount++;
}

void addStudent(StudentList* list, Student studentToBeAdded) {
	
    //Allocates memory for a new student
    list->students = (Student*)realloc(list->students, (list->studentCount + 1) * sizeof(Student));

    //Checks if memory allocation was successful 
    if (list->students == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    //Adds the new student to the student list
    list->students[list->studentCount] = studentToBeAdded;
    list->studentCount++;
}

int deleteStudent(StudentList* list, int studentNumber) {
	
    int success = -1;
	int a=0;
	
    while(a < (list->studentCount)) {
    	
        if (list->students[a].studentNumber == studentNumber) {
        	
           	//Founds the student, delates them by shifting elements
            for (int end = a; end < (list->studentCount - 1); end+=1) {
            	
                list->students[end] = list->students[end + 1];
            }

            //Updates the student count and reallocate memory
            list->studentCount--;
            list->students = (Student*)realloc(list->students, list->studentCount * sizeof(Student));
            success = 1;
            break;
        }
        a+=1;
    }
    return success ? 1 : -1;//Returns 1 if succeeds and -1 if fails
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

//Sorts students by their ID
void sort(StudentList* list) {		
   
    for (int a = 0; a < list->studentCount - 1; a+=1) {
    	
        for (int b = 0; b < list->studentCount - a - 1; b+=1) {
        	
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

    //Create a student list
    StudentList slist;
    slist.students = NULL;  	//Initialize to NULL (no students initially)
    slist.studentCount = 0;  	//Initialize student count


   	//Student1
    Student student1;
    strcpy(student1.name, "Kaan");
    strcpy(student1.surname, "Aydemir");
    student1.studentNumber = 2021;
    student1.courseCount = 0; 	//SEts course count
    student1.courses = NULL;   	//Sets to NULL (no courses initially)

    //Adding courses to student 
    addClassToStudent(classes[0], &student1);
    addClassToStudent(classes[2], &student1);


 	//Student 2 
    Student student2;
    strcpy(student2.name, "Kaan");
    strcpy(student2.surname, "Aydemir");
    student2.studentNumber = 2022;
    student2.courseCount = 0;  
    student2.courses = NULL;   

    addClassToStudent(classes[0], &student2);


  	//Student 3
    Student student3;
    strcpy(student3.name, "Kaan");
    strcpy(student3.surname, "Aydemir");
    student3.studentNumber = 2023;
    student3.courseCount = 0;  
    student3.courses = NULL; 


    addClassToStudent(classes[0], &student3);
    addClassToStudent(classes[1], &student3);
    addClassToStudent(classes[2], &student3); 


   	//Adding students to the student list
    addStudent(&slist, student1);
    addStudent(&slist, student2);
    addStudent(&slist, student3);
    


    printf("Student list before deletion:\n");
    printStudentList(slist);  // Print the student list before deletion

    //Deletes student
    int deleted = deleteStudent(&slist, 2022);

    printf("\nStudent list after deletion:\n");
    printStudentList(slist);  // Print the student list after deletion

    // ... (rest of the code)



    //Free memory for students and their courses
    for (int a = 0 ; a < slist.studentCount; a+=1) {
    	
        free(slist.students[a].courses);
    }
    free(slist.students);

    return 0;
}
