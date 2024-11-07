//
// Created by Siddharth Narsipur on 11/27/23.
//

#ifndef DATABASE_CSG_H
#define DATABASE_CSG_H

#include <stdbool.h>

typedef struct CSG_TUPLE *CSG_TUPLELIST;
typedef struct CSG_TUPLE CSG_TUPLE;
struct CSG_TUPLE {
    char course[10];
    char studentID[10];
    char grade[3];
    CSG_TUPLELIST next;
};

typedef struct COURSE_TUPLE *COURSE_TUPLELIST;
typedef struct COURSE_TUPLE COURSE_TUPLE;
struct COURSE_TUPLE{
    char course[10];
    COURSE_TUPLELIST next;
};

#define CSG_HASHTABLE_SIZE 11

typedef CSG_TUPLELIST CSG_HASHTABLE[CSG_HASHTABLE_SIZE];
typedef COURSE_TUPLELIST COURSE_HASHTABLE[CSG_HASHTABLE_SIZE];

CSG_TUPLE* CSG_NEW(char* course, char* studentID, char* grade);
bool SNAP_TUPLE_EQUALS(CSG_TUPLE* t, CSG_TUPLE* p);
int CSG_HASH(char* studentID);
void CSG_INSERT(CSG_TUPLE* t, CSG_HASHTABLE r);
void CSG_DELETE(CSG_TUPLE* t, CSG_HASHTABLE r);
void CSG_LOOKUP(CSG_TUPLE* t, CSG_HASHTABLE r);
void CSG_DELETE_TUPLE(CSG_TUPLE* t, CSG_HASHTABLE r);
void CSG_HASHTABLE_INIT(CSG_HASHTABLE r);
void CSG_HASHTABLE_PRINT(CSG_HASHTABLE table, int i);
void CSG_TUPLE_PRINT(CSG_TUPLE* this, int i);

void COURSE_TUPLE_PRINT(COURSE_TUPLE* this);
int COURSE_HASH(COURSE_TUPLE* t);
COURSE_TUPLE* COURSE_NEW(char* course);
void COURSE_HASHTABLE_INIT(COURSE_HASHTABLE r);
void COURSE_INSERT(COURSE_TUPLE* t, COURSE_HASHTABLE r);
void COURSE_HASHTABLE_PRINT(COURSE_HASHTABLE table);
void PROJECT_COURSE(CSG_HASHTABLE csg, COURSE_HASHTABLE c);

#endif //DATABASE_CSG_H
