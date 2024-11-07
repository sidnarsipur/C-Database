//
// Created by Siddharth Narsipur on 11/27/23.
//

//
// Created by Siddharth Narsipur on 11/27/23.
//

#ifndef DATABASE_CP_H
#define DATABASE_CP_H

typedef struct CP_TUPLE *CP_TUPLELIST;
typedef struct CP_TUPLE CP_TUPLE;
struct CP_TUPLE {
    char course[10];
    char prereq[10];
    CP_TUPLELIST next;
};

#define CP_HASHTABLE_SIZE 11
typedef CP_TUPLELIST CP_HASHTABLE[CP_HASHTABLE_SIZE];

CP_TUPLE* CP_NEW(char* course, char* prereq);
int CP_HASH(CP_TUPLE* t);
void CP_INSERT(CP_TUPLE* t, CP_HASHTABLE r);
void CP_DELETE(CP_TUPLE* t, CP_HASHTABLE r);
void CP_DELETE_TUPLE(CP_TUPLE* t, CP_HASHTABLE r);
void CP_LOOKUP(CP_TUPLE* t, CP_HASHTABLE r);
void CP_HASHTABLE_INIT(CP_HASHTABLE r);
void CP_HASHTABLE_PRINT(CP_HASHTABLE table);
void CP_TUPLE_PRINT(CP_TUPLE* this);

#endif //DATABASE_CP_H


