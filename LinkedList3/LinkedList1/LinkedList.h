#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // malloc ()

typedef struct student {
	int id;
	char name[100];
}Student;

typedef struct node {
	Student s; // 104 bytes
	struct node *pNext; // 4 bytes
} Node; // container

Node *makeNode(Student newStudent); // place the value inside the container
int insertAtFront(Node **pList, Student newStudent); // list operation
Student *deleteAtFront(Node **pList);

void printListRec(Node *pList); //you don't need to modify the value of pList so it's just one *

#endif