#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // malloc ()

typedef struct student
{
	int id;
	char name[100];
}Student;

typedef struct node
{
	Student s; // 104 bytes
	struct node *pNext; // 4 bytes
	struct node *pPrev; // for doubly linked lists // 4 bytes
} Node; // container

Node *makeNode(Student newStudent); // place the value inside the container
int insertAtFront(Node **pList, Student newStudent); // list operation
// a - z based on name
int insertInOrder(Node **pList, Student newStudent);
Student *deleteAtFront(Node **pList);
int deleteStudent(Node **pList, Student searchKey);
void printListRec(Node *pList);


#endif