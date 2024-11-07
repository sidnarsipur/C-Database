//
// Created by Siddharth Narsipur on 11/27/23.
//

#include "CSG.h"
#include "string-extras.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

CSG_TUPLE* CSG_NEW(char* course, char* studentID, char* grade){
    CSG_TUPLE* this = malloc(sizeof(struct CSG_TUPLE));

    strcpy(this->studentID, studentID);
    strcpy(this->course, course);
    strcpy(this->grade, grade);

    return this;
}

COURSE_TUPLE* COURSE_NEW(char* course){
    COURSE_TUPLE* this = malloc(sizeof(struct COURSE_TUPLE));
    strcpy(this->course, course);
    return this;
}

bool CSG_TUPLE_EQUALS(CSG_TUPLE* t, CSG_TUPLE* p){
    return streq(p->studentID, t->studentID) && streq(t->course, p->course) && streq(t->grade, p->grade);
}

void CSG_TUPLE_PRINT(CSG_TUPLE* this, int i){
    if(i == 0) {
        printf("   %-10s | %-12s | %-20s\n", this->course, this->studentID, this->grade);
    }
    else{
        printf("   %-12s | %-10s | %-20s\n", this->studentID, this->course, this->grade);
    }
}

void COURSE_TUPLE_PRINT(COURSE_TUPLE* this){
    printf("   %-10s\n", this->course);
}

int CSG_HASH(char* studentID){
    int count = 0;

    for(int i = 0; i< strlen(studentID); i++){
        count += studentID[i];
    }

    return count % CSG_HASHTABLE_SIZE;
}

int COURSE_HASH(COURSE_TUPLE* t){
    int count = 0;

    for(int i = 0; i< strlen(t->course); i++){
        count += t->course[i];
    }

    return count % CSG_HASHTABLE_SIZE;
}

void CSG_INSERT(CSG_TUPLE* t, CSG_HASHTABLE r){
    int i = CSG_HASH(t->studentID);

    CSG_TUPLE* p = r[i];
    if(p == NULL){
        r[i] = t;
        return;
    }

    while(p->next!=NULL){
        if(streq(p->course, t->course) && streq(p->studentID, t->studentID)){
            return;
        }
        else{
            p = p->next;
        }
    }
    if(streq(p->course, t->course) && streq(p->studentID, t->studentID)){
        return;
    }
    else {
        p->next = t;
    }
}

void COURSE_INSERT(COURSE_TUPLE* t, COURSE_HASHTABLE r){
    int i = COURSE_HASH(t);

    COURSE_TUPLE* p = r[i];
    if(p == NULL){
        r[i] = t;
        return;
    }

    while(p->next!=NULL){
        if(streq(p->course, t->course)){
            return;
        }
        else{
            p = p->next;
        }
    }
    if(streq(p->course, t->course)){
        return;
    }
    else {
        p->next = t;
    }
}

void CSG_DELETE(CSG_TUPLE* t, CSG_HASHTABLE r) {
    if (streq(t->studentID, "")) {
        int i = CSG_HASH(t->studentID);

        CSG_TUPLE *p = r[i];

        while (p != NULL) {
            if (streq(t->studentID, p->studentID)) {
                bool match = true;
                if (!streq(t->course, "")) {
                    if (!streq(t->course, p->course)) {
                        match = false;
                    }
                }
                if (!streq(t->grade, "")) {
                    if (!streq(t->grade, p->grade)) {
                        match = false;
                    }
                }
                if (match) {
                    CSG_DELETE_TUPLE(p, r);
                    CSG_TUPLE_PRINT(p, 0);
                    printf(" Tuple Deleted");
                    printf("\n");
                    return;
                }
            }
            p = p->next;
        }
        printf("Tuple Not Found In Table");
    } else {
        for (int i = 0; i < CSG_HASHTABLE_SIZE; i++) {

            CSG_TUPLE *p = r[i];

            bool match = true;

            while (p != NULL) {
                if (!streq(t->course, "")) {
                    if (!streq(t->course, p->course)) {
                        match = false;
                    }
                }
                if (!streq(t->grade, "")) {
                    if (!streq(t->grade, p->grade)) {
                        match = false;
                    }
                }
                if (match) {
                    CSG_DELETE_TUPLE(p, r);
                    CSG_TUPLE_PRINT(p, 0);
                    printf(" Tuple Deleted");
                    printf("\n");
                }
                p = p->next;
                match = true;
            }
        }
    }
}

void CSG_LOOKUP(CSG_TUPLE* t, CSG_HASHTABLE r) {
    if (streq(t->studentID, "")) {
        int i = CSG_HASH(t->studentID);

        CSG_TUPLE *p = r[i];

        while (p != NULL) {
            if (streq(t->studentID, p->studentID)) {
                bool match = true;
                if (!streq(t->course, "")) {
                    if (!streq(t->course, p->course)) {
                        match = false;
                    }
                }
                if (!streq(t->grade, "")) {
                    if (!streq(t->grade, p->grade)) {
                        match = false;
                    }
                }
                if (match) {
                    CSG_TUPLE_PRINT(p, 0);
                    return;
                }
            }
            p = p->next;
        }
        printf("Tuple Not Found In Table");
    } else {
        for (int i = 0; i < CSG_HASHTABLE_SIZE; i++) {

            CSG_TUPLE *p = r[i];

            bool match = true;

            while (p != NULL) {
                if (!streq(t->course, "")) {
                    if (!streq(t->course, p->course)) {
                        match = false;
                    }
                }
                if (!streq(t->grade, "")) {
                    if (!streq(t->grade, p->grade)) {
                        match = false;
                    }
                }
                if (match) {
                    CSG_TUPLE_PRINT(p, 0);
                    printf("\n");
                }
                p = p->next;
                match = true;
            }
        }
    }
}

void CSG_DELETE_TUPLE(CSG_TUPLE* t, CSG_HASHTABLE r){
        int i = CSG_HASH(t->studentID);

        CSG_TUPLE *p = r[i];

        if(CSG_TUPLE_EQUALS(t, p)){
            r[i] = p->next;
            return;
        }
        else{
            while(!CSG_TUPLE_EQUALS(t, p->next)){
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

void CSG_HASHTABLE_INIT(CSG_HASHTABLE r){
    for(int i = 0; i < CSG_HASHTABLE_SIZE; i++){
        r[i] = NULL;
    }
}

void COURSE_HASHTABLE_INIT(COURSE_HASHTABLE r){
    for(int i = 0; i < CSG_HASHTABLE_SIZE; i++){
        r[i] = NULL;
    }
}

void CSG_HASHTABLE_PRINT(CSG_HASHTABLE table, int j) {
    if(j==0){
    printf("   %-10s | %-12s | %-20s\n", "Course", "StudentID", "Grade");
        }
    else{
        printf("   %-12s | %-10s | %-20s\n", "StudentID", "Course", "Grade");
    }
    printf("-------------------------------------------------\n");

    for (int i = 0; i < CSG_HASHTABLE_SIZE; i++) {
        if (table[i] != NULL) {
            for (CSG_TUPLELIST p = table[i]; p != NULL; p = p->next) {
                CSG_TUPLE_PRINT(p, j);
            }
        }
    }
    printf("\n");
}

void COURSE_HASHTABLE_PRINT(COURSE_HASHTABLE table) {
    printf("   %-10s\n", "Course");
    printf("--------------\n");

    for (int i = 0; i < CSG_HASHTABLE_SIZE; i++) {
        if (table[i] != NULL) {
            for (COURSE_TUPLELIST p = table[i]; p != NULL; p = p->next) {
                COURSE_TUPLE_PRINT(p);
            }
        }
    }
    printf("\n");
}

void PROJECT_COURSE(CSG_HASHTABLE csg, COURSE_HASHTABLE c){
    for(int i = 0; i<CSG_HASHTABLE_SIZE; i++){
        CSG_TUPLE *p = csg[i];

        while(p!=NULL){
            COURSE_TUPLE *ct = COURSE_NEW(p->course);
            COURSE_INSERT(ct, c);
            p = p->next;
        }
    }
}
