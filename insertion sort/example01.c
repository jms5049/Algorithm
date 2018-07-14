#include <stdio.h>
#include <stdlib.h>

typedef struct _person {
	char id[10];
	int score;
	struct _person *next;	
	struct _person *prev;	
} person;

person* head;
person* tail;

void insertNode(person *newPerson, int score) {

	person *newNode = newPerson;	
	person *current = head->next;	

	if (current == tail) {			
		head->next = newNode;
		tail->prev = newNode;
		newNode->prev = head;
		newNode->next = tail;
		return;						
	}

	while (score > current->score && current->score > 0) {
		current = current->next;	
	}

	current->prev->next = newNode;
	newNode->prev = current->prev;
	
	current->prev = newNode;
	newNode->next = current;
	
}
void main() {

	char id[10];
	int score = 0;

	person * temp;		

	head = (person *)malloc(sizeof(person));		
	tail = (person *)malloc(sizeof(person));		

	head->next = tail;								
	head->prev = head;								

	tail->next = tail;								
	tail->prev = head;										

	FILE *file;
	file = fopen("test10.txt", "r");					

	if (file) {
		while (fscanf(file, "%s %d", id, &score) > 0) {
			temp = createNode(id, score);			
			insertNode(temp, score);				
		}
		printNode();								
		fclose(file);								
	}

}