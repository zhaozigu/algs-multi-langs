#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct Student_
{
  int id;
  char name[100];
  int age;
  char *descript;
} Student;

void student_destroy(void *student)
{
  Student *stu = (Student *)student;
  stu->id = 0;
  stu->name[0] = '\0';
  stu->age = 0;
  free(stu->descript);
}

int main()
{
  // raw int
  List list;
  list_init(&list, NULL);
  printf("size = %d\n", list.size);

  list_ins_next(&list, NULL, (void *)5);
  printf("size = %d, head data = %d\n", list.size, (int)list_head(&list)->data);

  list_destroy(&list);

  // define type
  List students;
  list_init(&students, student_destroy);
  Student student = {.id = 1, .name = "Jack Ma", .age = 23};
  asprintf(&student.descript, "I love money.");
  list_ins_next(&list, NULL, (void *)&student);
  printf("size = %d, student descript = %s\n", list.size, ((Student *)list_head(&list)->data)->descript);
  list_destroy(&students);
}
