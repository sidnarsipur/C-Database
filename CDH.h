//
// Created by Siddharth Narsipur on 11/27/23.
//

#ifndef CDH_SNAP_H
#define CDH_SNAP_H

typedef struct CDH_TUPLE *CDH_TUPLELIST;
typedef struct CDH_TUPLE CDH_TUPLE;
struct CDH_TUPLE {
    char course[10];
    char day[2];
    char hour[5];
    CDH_TUPLELIST next;
};

#define CDH_HASHTABLE_SIZE 11
typedef CDH_TUPLELIST CDH_HASHTABLE[CDH_HASHTABLE_SIZE];

CDH_TUPLE* CDH_NEW(char* course, char* day, char* hour);
int CDH_HASH(char course[10]);
void CDH_INSERT(CDH_TUPLE* t, CDH_HASHTABLE r);
void CDH_DELETE(CDH_TUPLE* t, CDH_HASHTABLE r);
void CDH_DELETE_TUPLE(CDH_TUPLE* t, CDH_HASHTABLE r);
void CDH_LOOKUP(CDH_TUPLE* t, CDH_HASHTABLE r);
void CDH_HASHTABLE_INIT(CDH_HASHTABLE r);
void CDH_HASHTABLE_PRINT(CDH_HASHTABLE table);
void CDH_TUPLE_PRINT(CDH_TUPLE* this);

#endif //CDH_SNAP_H


