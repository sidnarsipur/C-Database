//
// Created by Siddharth Narsipur on 11/27/23.
//

#include "CP.h"
#include "string-extras.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

CP_TUPLE* CP_NEW(char* course, char* prereq){
    CP_TUPLE* this = malloc(sizeof(struct CP_TUPLE));

    strcpy(this->course, course);
    strcpy(this->prereq, prereq);

    return this;
}

bool CP_TUPLE_EQUALS(CP_TUPLE* t, CP_TUPLE* p){
    return streq(t->course, p->course) && streq(t->prereq, p->prereq);
}

void CP_TUPLE_PRINT(CP_TUPLE* this){
    printf("   %-10s | %-12s\n", this->course, this->prereq);
}

int CP_HASH(CP_TUPLE* t){
    int count = 0;

    for(int i = 0; i< strlen(t->course); i++){
        count += t->course[i];
    }

    return count % CP_HASHTABLE_SIZE;
}

void CP_INSERT(CP_TUPLE* t, CP_HASHTABLE r){
    int i = CP_HASH(t);

    CP_TUPLE* p = r[i];
    if(p == NULL){
        r[i] = t;
        return;
    }

    while(p->next != NULL){
        if(CP_TUPLE_EQUALS(t, p)){
            return;
        }
        else{
            p = p->next;
        }
    }
    p->next = t;
}

void CP_LOOKUP(CP_TUPLE* t, CP_HASHTABLE r) {
    if (!streq(t->course, "")) {
        int i = CP_HASH(t);

        CP_TUPLE *p = r[i];

        while (p != NULL) {
            if (streq(p->course, t->course)) {
                bool match = true;
                if (!streq(t->prereq, "")) {
                    if (!streq(t->prereq, p->prereq)) {
                        match = false;
                    }
                }
                if (match) {
                    CP_TUPLE_PRINT(p);
                    printf("\n");
                    return;
                }
            }
            p = p->next;
        }
        printf("   Tuple Not Found In Table");
    }
    else {
        for (int i = 0; i < CP_HASHTABLE_SIZE; i++) {
            CP_TUPLE *p = r[i];
            bool match = true;

            while (p != NULL) {
                if (streq(t->prereq, "")) {
                    if (!streq(t->prereq, p->prereq)) {
                        match = false;
                    }
                }
                if (match) {
                    CP_TUPLE_PRINT(p);
                    printf("\n");
                }
                p = p->next;
                match = true;
            }
        }
    }
}

void CP_DELETE(CP_TUPLE* t, CP_HASHTABLE r){
    if(!streq(t->course, "")) {
        int i = CP_HASH(t);

        CP_TUPLE *p = r[i];

        while (p != NULL) {
            if (p->course == t->course) {
                bool match = true;
                if (!streq(t->prereq, "")) {
                    if (!streq(t->prereq, p->prereq)) {
                        match = false;
                    }
                }
                if (match) {
                    CP_DELETE_TUPLE(p, r);
                    CP_TUPLE_PRINT(p);
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
        for(int i = 0; i < CP_HASHTABLE_SIZE; i++){

            CP_TUPLE *p = r[i];

            bool match = true;

            while(p != NULL){
                if(!streq(t->prereq, "")){
                    if(!streq(t->prereq, p->prereq)){
                        match = false;
                    }
                }
                if(match){
                    CP_DELETE_TUPLE(p, r);
                    CP_TUPLE_PRINT(p);
                    printf(" Tuple Deleted");
                    printf("\n");
                }
                p=p->next;
                match = true;
            }
        }
    }
}

void CP_DELETE_TUPLE(CP_TUPLE* t, CP_HASHTABLE r){
    int i = CP_HASH(t);

    CP_TUPLE *p = r[i];

    if(CP_TUPLE_EQUALS(t, p)){
        r[i] = p->next;
        return;
    }
    else{
        while(!CP_TUPLE_EQUALS(t, p->next)){
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

void CP_HASHTABLE_INIT(CP_HASHTABLE r){
    for(int i = 0; i< CP_HASHTABLE_SIZE; i++){
        r[i] = NULL;
    }
}

void CP_HASHTABLE_PRINT(CP_HASHTABLE table) {
    printf("   %-10s | %-10s |\n", "Course", "Prerequisite");
    printf("--------------------------------------------\n");

    for (int i = 0; i < CP_HASHTABLE_SIZE; i++) {
        if (table[i] != NULL) {
            for (CP_TUPLELIST p = table[i]; p != NULL; p = p->next) {
                CP_TUPLE_PRINT(p);
            }
        }
    }
    printf("\n");
}




