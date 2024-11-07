//
// Created by Siddharth Narsipur on 11/27/23.
//

#include "CR.h"
#include "string-extras.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

CR_TUPLE* CR_NEW(char* course, char* room){
    CR_TUPLE* this = malloc(sizeof(struct CR_TUPLE));

    strcpy(this->course, course);
    strcpy(this->room, room);

    return this;
}

bool CR_TUPLE_EQUALS(CR_TUPLE* t, CR_TUPLE* p){
    return streq(t->course, p->course) && streq(t->room, p->room) ;
}

void CR_TUPLE_PRINT(CR_TUPLE* this){
    printf("   %-10s | %-15s\n", this->course, this->room);
}

int CR_HASH(char course[10]){
    int count = 0;

    for(int i = 0; i< strlen(course); i++){
        count += course[i];
    }

    return count % CR_HASHTABLE_SIZE;
}

void CR_INSERT(CR_TUPLE* t, CR_HASHTABLE r){
    int i = CR_HASH(t->course);

    CR_TUPLE* p = r[i];
    if(p == NULL){
        r[i] = t;
        return;
    }

    while(p->next!=NULL){
        if(streq(t->course, p->course)){
            return;
        }
        else{
            p = p->next;
        }
    }
    p->next = t;
}

void CR_LOOKUP(CR_TUPLE* t, CR_HASHTABLE r) {
    if(!streq(t->course, "")) {
        int i = CR_HASH(t->course);

        CR_TUPLE *p = r[i];

        while (p != NULL) {
            if (p->course == t->course) {
                bool match = true;
                if (!streq(t->room, "")) {
                    if (!streq(t->room, p->room)) {
                        match = false;
                    }
                }
                if (match) {
                    CR_TUPLE_PRINT(p);
                    printf("\n");
                    return;
                }
            }
            p = p->next;
        }
        printf("Tuple Not Found In Table");
    }
    else{
        for(int i = 0; i < CR_HASHTABLE_SIZE; i++){
            CR_TUPLE *p = r[i];
            bool match = true;

            while(p != NULL){
                if(!streq(t->room, "")){
                    if(!streq(t->room, p->room)){
                        match = false;
                    }
                }
                if(match){
                    CR_TUPLE_PRINT(p);
                    printf("\n");
                }
                p=p->next;
                match = true;
            }
        }
    }
}

void CR_DELETE(CR_TUPLE* t, CR_HASHTABLE r){
    if(!streq(t->course, "")) {
        int i = CR_HASH(t->course);

        CR_TUPLE *p = r[i];

        while (p != NULL) {
            if (p->course == t->course) {
                bool match = true;
                if (!streq(t->room, "")) {
                    if (!streq(t->room, p->room)) {
                        match = false;
                    }
                }
                if (match) {
                    CR_DELETE_TUPLE(p, r);
                    CR_TUPLE_PRINT(p);
                    printf(" Tuple Deleted");
                    printf("\n");
                    return;
                }
            }
            p = p->next;
        }
        printf("Tuple Not Found In Table");
    }
    else{
        for(int i = 0; i < CR_HASHTABLE_SIZE; i++){

            CR_TUPLE *p = r[i];

            bool match = true;

            while(p != NULL){
                if(!streq(t->room, "")){
                    if(!streq(t->room, p->room)){
                        match = false;
                    }
                }
                if(match){
                    CR_DELETE_TUPLE(p, r);
                    CR_TUPLE_PRINT(p);
                    printf(" Tuple Deleted");
                    printf("\n");
                }
                p=p->next;
                match = true;
            }
        }
    }
}

void CR_DELETE_TUPLE(CR_TUPLE* t, CR_HASHTABLE r){
    int i = CR_HASH(t->course);

    CR_TUPLE *p = r[i];

    if(CR_TUPLE_EQUALS(t, p)){
        r[i] = p->next;
        return;
    }
    else{
        while(!CR_TUPLE_EQUALS(t, p->next)){
            p = p->next;
        }
        if(p->next->next == NULL){
            p->next = NULL;
        }
        else {
            p->next = p->next->next;
        }
    }
}

void CR_HASHTABLE_INIT(CR_HASHTABLE r){
    for(int i = 0; i< CR_HASHTABLE_SIZE; i++){
        r[i] = NULL;
    }
}

void CR_HASHTABLE_PRINT(CR_HASHTABLE table) {
    printf("   %-10s | %-15s\n", "Course", "Room");
    printf("--------------------------------------\n");

    for (int i = 0; i < CR_HASHTABLE_SIZE; i++) {
        if (table[i] != NULL) {
            for (CR_TUPLELIST p = table[i]; p != NULL; p = p->next) {
                CR_TUPLE_PRINT(p);
            }
        }
    }
    printf("\n");
}




