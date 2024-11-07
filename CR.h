//
// Created by Siddharth Narsipur on 11/27/23.
//

#ifndef DATABASE_CR_H
#define DATABASE_CR_H

typedef struct CR_TUPLE *CR_TUPLELIST;
typedef struct CR_TUPLE CR_TUPLE;
struct CR_TUPLE {
    char course[10];
    char room [50];
    CR_TUPLELIST next;
};

#define CR_HASHTABLE_SIZE 11
typedef CR_TUPLELIST CR_HASHTABLE[CR_HASHTABLE_SIZE];

CR_TUPLE* CR_NEW(char* course, char* room);
int CR_HASH(char course[10]);
void CR_INSERT(CR_TUPLE* t, CR_HASHTABLE r);
void CR_DELETE(CR_TUPLE* t, CR_HASHTABLE r);
void CR_DELETE_TUPLE(CR_TUPLE* t, CR_HASHTABLE r);
void CR_LOOKUP(CR_TUPLE* t, CR_HASHTABLE r);
void CR_HASHTABLE_INIT(CR_HASHTABLE r);
void CR_HASHTABLE_PRINT(CR_HASHTABLE table);
void CR_TUPLE_PRINT(CR_TUPLE* this);

#endif //DATABASE_CR_H

