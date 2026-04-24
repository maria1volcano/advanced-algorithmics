/**
 * @file list.c
 * @brief Implementation file for a linked list
 *
 * This file contains the implementation of the linked list data structure
 * and its associated functions.
 *
 * @author Loïck Lhote
 * @date February 2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * @brief Creates a new linked list
 *
 * @return A pointer to the newly created linked list
 */
List newList() {
    return NULL;
}

/**
 * @brief Frees the memory used by a linked list
 *
 * @param L Pointer to the linked list to be freed
 */
void freeList(List L) {
    Cell *current = L;
    if (current != NULL){
        Cell *next = current->nextCell;
        if (current->key != NULL){
            free(current->key);
        }
        free(current);
        current = next;
    }
}

/**
 * @brief Prints the contents of a linked list
 *
 * @param L Pointer to the linked list to be printed
 * @param type If type==0, prints only the values, otherwise print the couples (key,vlaue)
 *
 * Prints the linked list in the following way if k!=0:
 * [(key 1, value 1),(key 2, value 2), … ,(key k, value k)]
 * Prints the linked list in the following way if k==0:
 * [value 1,value 2,…,value k]
 */

void printList(List L, int type) {
    Cell *current=L;
    printf("[");
    while(current !=NULL){
        
        if(type==0){
            printf("valeur %d", current->value);
        }else{
            if(current->key==NULL){
                printf("(NULL, valeur %d)", current->value);
            }else{
                printf("(key %s, valeur %d)",current->key, current->value);
            }
            if (current->nextCell != NULL){
                printf(","); 
            }
             current= current->nextCell;
        }
    }
    printf("]\n");
    return;
}

/**
 * @brief Finds a key in a linked list
 *
 * @param L Pointer to the linked list to search in
 * @param key Key to search for
 *
 * @return A pointer to the first cell containing the key, or NULL if the key is not found
 */
Cell* findKeyInList(List L, string key) {
    Cell *current= L;
    while (current != NULL){
        if ( key==NULL && current->key ==NULL){
            return current;
        }
        if (key != NULL && current->key != NULL && strcmp(current->key, key) == 0){
            return current;
        }
        current = current->nextCell;  
    }
    return NULL;
}

/**
 * @brief Deletes a key from a linked list
 *
 * @param L Pointer to the linked list to search in
 * @param key Key to delete
 *
 * @return A pointer to the modified linked list
 * Only the first occurrence of the key is deleted.
 */
List delKeyInList(List L, string key) {
    if (L == NULL) return NULL;
   
    if (( key==NULL && L->key ==NULL)||
        (key != NULL && L->key != NULL && strcmp(L->key, key) == 0)){
         Cell *Newhead= L->nextCell; 
        if(key != NULL) free(L->key);
        free(L)
        return Newhead;
    }    
    Cell *prev=L;
    Cell *current= L->nextCell;
    while(current != NULL){
        if (( key==NULL && current->key ==NULL)||
            (key != NULL && current->key != NULL && strcmp(current->key, key) == 0)){
            if(key != NULL) free(L->key);
            free(L);
            if (current->key != NULL) free(current->key);
            free(current);
            return L;
        }
        prev=current;
        current=current ->nextCell; 
    }
    return L;
}

/**
 * @brief Adds a key-value pair to a linked list
 *
 * @param L Pointer to the linked list to add to
 * @param key Key to add
 * @param value Value to add
 *
 * @return A pointer to the modified linked list
 *
 * The key-value pair is added at the beginning of the list
 */

 List addKeyValueInList(List L, string key, int value) {
    
    Cell *newCell = (Cell*) malloc(sizeof(Cell));

    if (newCell == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
    }

    if (key == NULL) {
        newCell->key = NULL;
    } else {
        newCell->key = (string) malloc((strlen(key) + 1) * sizeof(char));
        strcpy(newCell->key, key);
    }
    newCell->value = value;
    newCell->nextCell = L;
    return newCell;
}
