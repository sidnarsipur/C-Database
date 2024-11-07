//
// Created by Siddharth Narsipur on 11/27/23.
//

#include "SNAP.h"
#include "string-extras.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

SNAP_TUPLE* SNAP_NEW(char* studentID, char* name, char* address, char* phone){
    SNAP_TUPLE* this = malloc(sizeof(struct SNAP_TUPLE));

    strcpy(this->studentID, studentID);
    strcpy(this->name, name);
    strcpy(this->address, address);
    strcpy(this->phone, phone);

    return this;
}

bool SNAP_TUPLE_EQUALS(SNAP_TUPLE* t, SNAP_TUPLE* p){
    return p->studentID == t->studentID && streq(t->phone, p->phone) && streq(t->name, p->name) && streq(t->address, p->address);
}

void SNAP_TUPLE_PRINT(SNAP_TUPLE* this){
    printf("   %-10s | %-15s | %-20s | %-15s\n", this->studentID, this->name, this->address, this->phone);
}

int SNAP_HASH(SNAP_TUPLE* t){
    int count = 0;

    for(int i = 0; i< strlen(t->studentID); i++){
        count += t->studentID[i];
    }

    return count % SNAP_HASHTABLE_SIZE;
}

void SNAP_INSERT(SNAP_TUPLE* t, SNAP_HASHTABLE r){
    int i = SNAP_HASH(t);

    SNAP_TUPLE* p = r[i];
    if(p == NULL){
        r[i] = SNAP_NEW(t->studentID, t->name, t->address, t->phone);
        return;
    }

    while(p->next!=NULL){
        if(streq(p->studentID, t->studentID)){
            return;
        }
        else{
            p = p->next;
        }
    }
    p->next = SNAP_NEW(t->studentID, t->name, t->address, t->phone);
}

void SNAP_LOOKUP(SNAP_TUPLE* t, SNAP_HASHTABLE r) {
    bool f = false;
    if(!streq(t->studentID, "")) {
        int i = SNAP_HASH(t);

        SNAP_TUPLE *p = r[i];

        while (p != NULL) {
            if (streq(t->studentID, p->studentID)) {
                bool match = true;
                if (!streq(t->name, "")) {
                    if (!streq(t->name, p->name)) {
                        match = false;
                    }
                }
                if (!streq(t->address, "")) {
                    if (!streq(t->address, p->address)) {
                        match = false;
                    }
                }
                if (!streq(t->phone, "")) {
                    if (!streq(t->phone, p->phone)) {
                        match = false;
                    }
                }
                if (match) {
                    f = true;
                    SNAP_TUPLE_PRINT(p);
                }
            }
            p = p->next;
        }
    }
    else{
        for(int i = 0; i < SNAP_HASHTABLE_SIZE; i++){
            SNAP_TUPLE *p = r[i];
            bool match = true;

            while(p != NULL){
                if(!streq(t->name, "")){
                    if(!streq(t->name, p->name)){
                        match = false;
                    }
                }
                if(!streq(t->address, "")){
                    if(!streq(t->address, p->address)){
                        match = false;
                    }
                }
                if(!streq(t->phone, "")){
                    if(!streq(t->phone, p->phone)){
                        match = false;
                    }
                }
                if(match){
                    f = true;
                    SNAP_TUPLE_PRINT(p);
                }
                p=p->next;
                match = true;
            }
        }
    }
    if(!f){
        printf("Tuple Not Found In Table");
    }
    else{
        printf("   Tuple(s) found");
    }
}

void SNAP_DELETE(SNAP_TUPLE* t, SNAP_HASHTABLE r){
    if(streq(t->studentID, "")) {
        int i = SNAP_HASH(t);

        SNAP_TUPLE *p = r[i];

        while (p != NULL) {
            if (p->studentID == t->studentID) {
                bool match = true;
                if (!streq(t->name, "")) {
                    if (!streq(t->name, p->name)) {
                        match = false;
                    }
                }
                if (!streq(t->address, "")) {
                    if (!streq(t->address, p->address)) {
                        match = false;
                    }
                }
                if (!streq(t->phone, "")) {
                    if (!streq(t->phone, p->phone)) {
                        match = false;
                    }
                }
                if (match) {
                    SNAP_DELETE_TUPLE(p, r);
                    SNAP_TUPLE_PRINT(p);
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
        for(int i = 0; i < SNAP_HASHTABLE_SIZE; i++){

            SNAP_TUPLE *p = r[i];

            bool match = true;

            while(p != NULL){
                if(!streq(t->name, "")){
                    if(!streq(t->name, p->name)){
                        match = false;
                    }
                }
                if(!streq(t->address, "")){
                    if(!streq(t->address, p->address)){
                        match = false;
                    }
                }
                if(!streq(t->phone, "")){
                    if(!streq(t->phone, p->phone)){
                        match = false;
                    }
                }
                if(match){
                    SNAP_DELETE_TUPLE(p, r);
                    SNAP_TUPLE_PRINT(p);
                    printf(" Tuple Deleted");
                    printf("\n");
                }
                p=p->next;
                match = true;
            }
        }
    }
}

void SNAP_DELETE_TUPLE(SNAP_TUPLE* t, SNAP_HASHTABLE r){
    int i = SNAP_HASH(t);

    SNAP_TUPLE *p = r[i];

    if(SNAP_TUPLE_EQUALS(t, p)){
        r[i] = p->next;
        return;
    }
    else{
        while(!SNAP_TUPLE_EQUALS(t, p->next)){
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

void SNAP_HASHTABLE_INIT(SNAP_HASHTABLE r){
    for(int i = 0; i< SNAP_HASHTABLE_SIZE; i++){
        r[i] = NULL;
    }
}

void SNAP_HASHTABLE_PRINT(SNAP_HASHTABLE table) {
    printf("   %-10s | %-15s | %-20s | %-15s\n", "StudentID", "Name", "Address", "Phone No.");
    printf("------------------------------------------------------------------------\n");

    for (int i = 0; i < SNAP_HASHTABLE_SIZE; i++) {
        if (table[i] != NULL) {
            for (SNAP_TUPLELIST p = table[i]; p != NULL; p = p->next) {
                SNAP_TUPLE_PRINT(p);
            }
        }
    }
    printf("\n");
}

void SELECT_SNAP_NAME(char* name, SNAP_HASHTABLE table, SNAP_HASHTABLE n_table){
    for(int i = 0; i < SNAP_HASHTABLE_SIZE; i++){
        SNAP_TUPLE *p = table[i];

        while(p != NULL){
            if(streq(name, p->name)){
                SNAP_INSERT(p, n_table);
            }
            p = p->next;
        }
    }
}




