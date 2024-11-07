//
// Created by Siddharth Narsipur on 11/27/23.
//

#ifndef DATABASE_SNAP_H
#define DATABASE_SNAP_H

typedef struct SNAP_TUPLE *SNAP_TUPLELIST;
typedef struct SNAP_TUPLE SNAP_TUPLE;
struct SNAP_TUPLE {
    char studentID[10];
    char name[30];
    char address[50];
    char phone[9];
    SNAP_TUPLELIST next;
};

#define SNAP_HASHTABLE_SIZE 11
typedef SNAP_TUPLELIST SNAP_HASHTABLE[SNAP_HASHTABLE_SIZE];

SNAP_TUPLE* SNAP_NEW(char* studentID, char* name, char* address, char* phone);
int SNAP_HASH(SNAP_TUPLE* t);
void SNAP_INSERT(SNAP_TUPLE* t, SNAP_HASHTABLE r);
void SNAP_DELETE(SNAP_TUPLE* t, SNAP_HASHTABLE r);
void SNAP_DELETE_TUPLE(SNAP_TUPLE* t, SNAP_HASHTABLE r);
void SNAP_LOOKUP(SNAP_TUPLE* t, SNAP_HASHTABLE r);
void SNAP_HASHTABLE_INIT(SNAP_HASHTABLE r);
void SNAP_HASHTABLE_PRINT(SNAP_HASHTABLE table);
void SNAP_TUPLE_PRINT(SNAP_TUPLE* this);
void SELECT_SNAP_NAME(char* name, SNAP_HASHTABLE table, SNAP_HASHTABLE n_table);

#endif //DATABASE_SNAP_H
