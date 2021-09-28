#include <stdlib.h>

#include <stdio.h>

#include "history.h"

#include "tokenizer.h"





/* Initialize the linked list to keep the history. */

List* init_history(){

  List *list = malloc(sizeof(List));

  list->root = malloc(sizeof(Item));

  return (list);

}

/* Add a history item to the end of the list.

   List* list - the linked list

   char* str - the string to store

*/

void add_history(List *list, char *str){

  Item *new_node;

  Item *ptr = list->root;

  while (ptr->next != NULL){

    ptr = ptr->next;

  }

  new_node = malloc(sizeof(Item));

  ptr->next = new_node;

  new_node->str = str;

  char *myptr;

  char *str_ptr = copy_str(str);

  new_node->id = ptr->id + 1;

}





/* Retrieve the string stored in the node where Item->id == id.

   List* list - the linked list

   int id - the id of the Item to find */

char *get_history(List *list, int id){

  int count = 0;

  char* char_ptr;

  Item *ptr = list->root;

  while (ptr->id != NULL){

        ptr

	  }



}

/*Print the entire contents of the list. */

void print_history(List *list);



/*Free the history list and the strings it references. */

void free_history(List *list);
