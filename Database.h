//
// Created by Siddharth Narsipur on 11/28/23.
//

#ifndef DATABASE_DATABASE_H
#define DATABASE_DATABASE_H

#include "SNAP.h"
#include "CDH.h"
#include "CP.h"
#include "CR.h"
#include "CSG.h"

typedef struct Database Database;
struct Database {
    SNAP_HASHTABLE SNAP_TABLE;
    CDH_HASHTABLE CDH_TABLE;
    CP_HASHTABLE CP_TABLE;
    CR_HASHTABLE CR_TABLE;
    CSG_HASHTABLE CSG_TABLE;
};

Database* CREATE_DB();
void PRINT_DB(Database* db);

void GET_GRADE(char* name, char* course, SNAP_HASHTABLE s, CSG_HASHTABLE c);
void GET_LOCATION(char* name, char* hour, char* day, SNAP_HASHTABLE sp, CDH_HASHTABLE cdh, CSG_HASHTABLE csg, CR_HASHTABLE cr);

#endif //DATABASE_DATABASE_H
