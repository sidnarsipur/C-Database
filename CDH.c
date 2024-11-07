//
// Created by Siddharth Narsipur on 11/27/23.
//

#include "CDH.h"
#include "string-extras.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

CDH_TUPLE* CDH_NEW(char* course, char* day, char* hour){
    CDH_TUPLE* this = malloc(sizeof(struct CDH_TUPLE));

    strcpy(this->course, course);
    strcpy(this->day, day);
    strcpy(this->hour, hour);

    return this;
}

bool CDH_TUPLE_EQUALS(CDH_TUPLE* t, CDH_TUPLE* p){
    return streq(t->course, p->course) && streq(t->day, p->day) && streq(t->hour, p->hour);
}

void CDH_TUPLE_PRINT(CDH_TUPLE* this) {
    printf("   %-10s | %-5s | %-10s\n", this->course, this->day, this->hour);
}

int CDH_HASH(char course[10]){
    int count = 0;

    for(int i = 0; i < strlen(course); i++){
        count += course[i];
    }

    return count % CDH_HASHTABLE_SIZE;
}

void CDH_INSERT(CDH_TUPLE* t, CDH_HASHTABLE r){
    int i = CDH_HASH(t->course);

    CDH_TUPLE* p = r[i];
    if(p == NULL){
        r[i] = t;
        return;
    }

    while(p->next!=NULL){
        if(CDH_TUPLE_EQUALS(t, p)){
            return;
        }
        else{
            p = p->next;
        }
    }
    p->next = t;
}

void CDH_LOOKUP(CDH_TUPLE* t, CDH_HASHTABLE r) {
    if(!streq(t->course, "")) {
        int i = CDH_HASH(t->course);

        CDH_TUPLE *p = r[i];

        while (p != NULL) {
            if (p->course == t->course) {
                bool match = true;
                if (!streq(t->day, "")) {
                    if (!streq(t->day, p->day)) {
                        match = false;
                    }
                }
                if (!streq(t->hour, "")) {
                    if (!streq(t->hour, p->hour)) {
                        match = false;
                    }
                }
                if (match) {
                    CDH_TUPLE_PRINT(p);
                    printf("\n");
                    return;
                }
            }
            p = p->next;
        }
        printf("Tuple Not Found In Table");
    }
    else{
        for(int i = 0; i < CDH_HASHTABLE_SIZE; i++){
            CDH_TUPLE *p = r[i];
            bool match = true;

            while(p != NULL){
                if (!streq(t->day, "")) {
                    if (!streq(t->day, p->day)) {
                        match = false;
                    }
                }
                if (!streq(t->hour, "")) {
                    if (!streq(t->hour, p->hour)) {
                        match = false;
                    }
                }
                if (match) {
                    CDH_TUPLE_PRINT(p);
                    printf("\n");
                    return;
                }
                p=p->next;
                match = true;
            }
        }
    }
}

void CDH_DELETE(CDH_TUPLE* t, CDH_HASHTABLE r){
    bool del = false;
    if(!streq(t->course, "")) {
        int i = CDH_HASH(t->course);

        CDH_TUPLE *p = r[i];

        while (p != NULL) {
            if (streq(p->course, t->course)) {
                bool match = true;
                if (!streq(t->day, "")) {
                    if (!streq(t->day, p->day)) {
                        match = false;
                    }
                }
                if (!streq(t->hour, "")) {
                    if (!streq(t->hour, p->hour)) {
                        match = false;
                    }
                }
                if (match) {
                    del = true;
                    CDH_DELETE_TUPLE(p, r);
                }
            }
            p = p->next;
        }
    }
    else{
        for(int i = 0; i < CDH_HASHTABLE_SIZE; i++){

            CDH_TUPLE *p = r[i];

            bool match = true;

            while(p != NULL){
                if(!streq(t->day, "")){
                    if(!streq(t->day, p->day)){
                        match = false;
                    }
                }
                if(!streq(t->hour, "")){
                    if(!streq(t->hour, p->hour)){
                        match = false;
                    }
                }
                if(match){
                    CDH_DELETE_TUPLE(p, r);
                    del = true;
                }
                p=p->next;
                match = true;
            }
        }
    }
    if(del){
        printf("\n   Tuple(s) Deleted\n");
        CDH_HASHTABLE_PRINT(r);
    }
    else{
        printf("   No Tuple(s) found\n");
    }
}

void CDH_DELETE_TUPLE(CDH_TUPLE* t, CDH_HASHTABLE r){
    int i = CDH_HASH(t->course);

    CDH_TUPLE *p = r[i];

    if(CDH_TUPLE_EQUALS(t, p)){
        r[i] = p->next;
        return;
    }
    else{
        while(!CDH_TUPLE_EQUALS(t, p->next)){
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

void CDH_HASHTABLE_INIT(CDH_HASHTABLE r){
    for(int i = 0; i< CDH_HASHTABLE_SIZE; i++){
        r[i] = NULL;
    }
}

void CDH_HASHTABLE_PRINT(CDH_HASHTABLE table) {
    printf("   %-10s | %-5s | %-10s\n", "Course", "Day", "Hour");
    printf("----------------------------------------\n");

    for (int i = 0; i < CDH_HASHTABLE_SIZE; i++) {
        if (table[i] != NULL) {
            for (CDH_TUPLELIST p = table[i]; p != NULL; p = p->next) {
                CDH_TUPLE_PRINT(p);
            }
        }
    }
    printf("\n");
}



