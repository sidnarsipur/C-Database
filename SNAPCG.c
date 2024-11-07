//
// Created by Siddharth Narsipur on 11/28/23.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "SNAPCG.h"
#include "SNAP.h"
#include "CSG.h"
#include "string-extras.h"

SNAPCG_TUPLE* SNAPCG_NEW(char* studentID, char* name, char* address, char* phone, char* course, char* grade){
    SNAPCG_TUPLE* this = malloc(sizeof(struct SNAPCG_TUPLE));

    strcpy(this->studentID, studentID);
    strcpy(this->name, name);
    strcpy(this->address, address);
    strcpy(this->phone, phone);
    strcpy(this->course, course);
    strcpy(this->grade, grade);

    return this;
}

bool SNAPCG_TUPLE_EQUALS(SNAPCG_TUPLE* t, SNAPCG_TUPLE* p){
    return streq(t->studentID ,p->studentID) && streq(t->phone, p->phone) && streq(t->name, p->name)
    && streq(t->address, p->address) && streq(t->course, p->course) && streq(t->grade, p->grade);
}

void SNAPCG_INSERT(SNAPCG_TUPLE* t, SNAPCG_HASHTABLE r){
    int i = SNAPCG_HASH(t);

    SNAPCG_TUPLE* q = r[i];
    if(q == NULL){
        SNAPCG_TUPLE *n = SNAPCG_NEW(t->studentID, t->name, t->address, t->phone, t->course, t->grade);
        r[i] = n;
        return;
    }

    while(q->next!=NULL){
        if(SNAPCG_TUPLE_EQUALS(t, q)){
            return;
        }
        else{
            q = q->next;
        }
    }
    SNAPCG_TUPLE *n = SNAPCG_NEW(t->studentID, t->name, t->address, t->phone, t->course, t->grade);
    q->next = n;
}


int SNAPCG_HASH(SNAPCG_TUPLE* t){
    int count = 0;

    for(int i = 0; i< strlen(t->studentID); i++){
        count += t->studentID[i];
    }

    return count % SNAPCG_HASHTABLE_SIZE;
}

void JOIN_SNAP_CSG(SNAP_HASHTABLE snap, CSG_HASHTABLE csg, SNAPCG_HASHTABLE join){
    for(int i = 0; i < SNAP_HASHTABLE_SIZE; i++){
        SNAP_TUPLE *p = snap[i];

        while(p != NULL){
            char* studentID = p->studentID;
            int j = CSG_HASH(studentID);

            CSG_TUPLE *q = csg[j];

            while(q != NULL){
                if(streq(studentID, q->studentID)) {
                    SNAPCG_TUPLE *new = SNAPCG_NEW(studentID, p->name, p->address, p->phone, q->course, q->grade);
                    SNAPCG_INSERT(new, join);
                }
                q = q->next;
            }
            p = p->next;
        }
    }
}

void SNAPCG_HASHTABLE_INIT(SNAPCG_HASHTABLE r){
    for(int i = 0; i< SNAPCG_HASHTABLE_SIZE; i++){
        r[i] = NULL;
    }
}

void SNAPCG_HASHTABLE_PRINT(SNAPCG_HASHTABLE table) {
    printf("   %-10s | %-15s | %-20s | %-15s | %-15s | %-15s\n", "StudentID", "Name", "Address", "Phone No.", "Course", "Grade");
    printf("------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < SNAPCG_HASHTABLE_SIZE; i++) {
        if (table[i] != NULL) {
            for (SNAPCG_TUPLELIST p = table[i]; p != NULL; p = p->next) {
                SNAPCG_TUPLE_PRINT(p);
            }
        }
    }
    printf("\n");
}

void SNAPCG_TUPLE_PRINT(SNAPCG_TUPLE* this){
    printf("   %-10s | %-15s | %-20s | %-15s | %-15s | %-15s\n", this->studentID, this->name, this->address, this->phone, this->course, this->grade);
}

void SELECT_SNAPCG_NAME(char* name, SNAPCG_HASHTABLE table, SNAPCG_HASHTABLE n_table){
    for(int i = 0; i < SNAPCG_HASHTABLE_SIZE; i++){
        SNAPCG_TUPLE *p = table[i];

        while(p != NULL){
            if(streq(name, p->name)){
                SNAPCG_INSERT(p, n_table);
            }
            p = p->next;
        }
    }
}

void PROJECT_CSG(SNAPCG_HASHTABLE snapcsg, CSG_HASHTABLE csg){
    for(int i = 0; i<SNAPCG_HASHTABLE_SIZE; i++){
        SNAPCG_TUPLE *p = snapcsg[i];

        while(p!=NULL){
            CSG_TUPLE *ct = CSG_NEW(p->course, p->studentID, p->grade);
            CSG_INSERT(ct, csg);
            p = p->next;
        }
    }
}

