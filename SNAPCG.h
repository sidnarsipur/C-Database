//
// Created by Siddharth Narsipur on 11/28/23.
//

#ifndef DATABASE_SNAPCG_H
#define DATABASE_SNAPCG_H

#include <stdbool.h>
#include "SNAP.h"
#include "CSG.h"

typedef struct SNAPCG_TUPLE *SNAPCG_TUPLELIST;
typedef struct SNAPCG_TUPLE SNAPCG_TUPLE;
struct SNAPCG_TUPLE {
    char studentID[10];
    char name[30];
    char address[50];
    char phone[9];
    char course[30];
    char grade[3];
    SNAPCG_TUPLELIST next;
};

#define SNAPCG_HASHTABLE_SIZE 11
typedef SNAPCG_TUPLELIST SNAPCG_HASHTABLE[SNAPCG_HASHTABLE_SIZE];

SNAPCG_TUPLE* SNAPCG_NEW(char* studentID, char* name, char* address, char* phone, char* course, char* grade);
int SNAPCG_HASH(SNAPCG_TUPLE* t);
void SNAPCG_HASHTABLE_INIT(SNAPCG_HASHTABLE r);
bool SNAPCG_TUPLE_EQUALS(SNAPCG_TUPLE* t, SNAPCG_TUPLE* p);
void JOIN_SNAP_CSG(SNAP_HASHTABLE snap, CSG_HASHTABLE csg, SNAPCG_HASHTABLE join);
void SNAPCG_HASHTABLE_PRINT(SNAPCG_HASHTABLE table);
void SNAPCG_TUPLE_PRINT(SNAPCG_TUPLE* this);
void SELECT_SNAPCG_NAME(char* name, SNAPCG_HASHTABLE table, SNAPCG_HASHTABLE n_table);
void PROJECT_CSG(SNAPCG_HASHTABLE snapcsg, CSG_HASHTABLE csg);

#endif //DATABASE_SNAPCG_H
