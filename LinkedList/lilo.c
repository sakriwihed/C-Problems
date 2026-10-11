#include <stdio.h>
#include <stdlib.h>

typedef struct list_element {
	int value;
	struct list_element *next;
} list_element_t;

typedef struct list {
	struct list_element *head; //zeigt auf das erste Element der Liste
} list_t;


int list_append(list_t *list, int value) {
	if (value<0) { // wenn value ist negativ dann Error
		return -1;
	}
	list_element_t *currentElement=list->head;
	while (currentElement !=NULL) {  // durchlaufen, bis die Liste zu Ende ist
		if (currentElement->value==value) {
			return -1; //wenn value gefunden ist dann Error
		}
		currentElement=currentElement->next; //nächstes Element zugreifen
	}
	// jetzt sind wir safe, dass value nicht gefunden ist
	list_element_t *newElement=malloc((sizeof(list_element_t))); //Speicherplatz für das neue Element reservieren
	if (newElement == NULL) {
		return -1; // Speicher konnte nicht reserviert werden
	}
	newElement->value=value;
	newElement->next=NULL;
	//wenn die Liste leer ist dann ist unseres neue Element das erste
	if (list->head==NULL) {
		list->head=newElement;
	}else {
		currentElement = list->head;
		while (currentElement->next != NULL) {
			currentElement = currentElement->next;
		}
		currentElement->next = newElement;
	}

	return value;
}

int list_pop(list_t *list) {
	if (list->head==NULL) {
		return -1;
	}
	list_element_t* currentElement=list->head;
	int value=currentElement->value;
	list_element_t* nextElement=currentElement->next;
	free(currentElement); //Speicherplatz leeren
	list->head=nextElement;
	return value;
}

int main (void) {

	list_t list;
	list.head = NULL;

	printf("insert 47: %d\n", list_append(&list, 47));
	printf("insert 11: %d\n", list_append(&list, 11));
	printf("insert 23: %d\n", list_append(&list, 23));
	printf("insert 11: %d\n", list_append(&list, 11));

	printf("remove: %d\n", list_pop(&list));
	printf("remove: %d\n", list_pop(&list));
	exit(EXIT_SUCCESS);
}