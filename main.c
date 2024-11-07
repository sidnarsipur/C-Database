//
// Created by Siddharth Narsipur on 11/28/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Database.h"
#include "string-extras.h"
#include "SNAPCG.h"

int main(){
    Database* db = CREATE_DB();
    PRINT_DB(db);

    printf("\n ---PERFORMING PART 1 OPERATIONS--- \n");

    printf("\n   --PART A--\n");
    CSG_TUPLE* l1 = CSG_NEW("DSCC201", "01376", "B+");
    CSG_LOOKUP(l1, db->CSG_TABLE);

    printf("\n   --PART B--\n");
    SNAP_TUPLE* l2 = SNAP_NEW("", "R. Johnson", "", "");
    SNAP_LOOKUP(l2, db->SNAP_TABLE);

    printf("\n\n   --PART C--\n");
    CP_TUPLE* l3 = CP_NEW("CSC252", "CSC173");
    CP_LOOKUP(l3, db->CP_TABLE);

    printf("\n\n   --PART D--\n");
    CDH_TUPLE* l4 = CDH_NEW("DSCC201", "T", "900");
    CDH_DELETE(l4, db->CDH_TABLE);

    printf("   --PART E--\n");
    CDH_TUPLE* l5 = CDH_NEW("CSC171", "T", "");
    CDH_DELETE(l5, db->CDH_TABLE);

    printf("\n   --PART F--\n");
    CDH_TUPLE* l6 = CDH_NEW("CSC173", "", "");
    CDH_DELETE(l6, db->CDH_TABLE);

    printf("\n   --PART G--\n");
    CSG_TUPLE* l7 = CSG_NEW("CSC252", "74533", "A-");
    CSG_INSERT(l7, db->CSG_TABLE);
    CSG_HASHTABLE_PRINT(db->CSG_TABLE, 0);

    printf("\n   --PART H--\n");
    CSG_TUPLE* l8 = CSG_NEW("DSCC201", "66252", "C");
    CSG_INSERT(l8, db->CSG_TABLE);
    CSG_HASHTABLE_PRINT(db->CSG_TABLE, 0);

    Database* db2 = CREATE_DB();

    printf("\n ---PERFORMING PART 2 OPERATIONS--- \n");

    char* name = (char *) malloc(300);
    char* course = (char *) malloc(300);

    while (1){
        printf("\n%s\n", "--GET GRADE- ");
        printf("%s", "Enter a name (q to quit): ");
        fgets(name, 300, stdin);
        strtok(name, "\n");

        if(streq(name, "q")){
            break;
        }

        printf("%s", "Enter a course: ");
        fgets(course, 300, stdin);
        strtok(course, "\n");

        GET_GRADE(name, course, db2->SNAP_TABLE, db2->CSG_TABLE);
    }

    char* name2 = (char *) malloc(300);
    char* day = (char *) malloc(300);
    char* hour = (char *) malloc(300);

    while (1){
        printf("\n%s\n", "--GET LOCATION- ");
        printf("%s", "Enter a name (q to quit): ");
        fgets(name2, 300, stdin);
        strtok(name2, "\n");

        if(streq(name2, "q")){
            break;
        }

        printf("%s", "Enter a day: ");
        fgets(day, 300, stdin);
        strtok(day, "\n");

        printf("%s", "Enter a hour: ");
        fgets(hour, 300, stdin);
        strtok(hour, "\n");

        GET_LOCATION(name2, hour, day, db2->SNAP_TABLE, db2->CDH_TABLE, db2->CSG_TABLE, db2->CR_TABLE);
    }

    printf("\n ---PERFORMING PART 2 OPERATIONS--- \n");

    SNAP_HASHTABLE select;
    SNAP_HASHTABLE_INIT(select);

    SELECT_SNAP_NAME("O. Gonzalez", db2->SNAP_TABLE, select);
    printf("\n   1. Selection: σName=“O. Gonzalez”(SNAP)\n\n");
    SNAP_HASHTABLE_PRINT(select);

    COURSE_HASHTABLE project;
    COURSE_HASHTABLE_INIT(project);

    PROJECT_COURSE(db2->CSG_TABLE, project);
    printf("\n   2. Projection: πCourse(CSG)\n\n");
    COURSE_HASHTABLE_PRINT(project);

    SNAPCG_HASHTABLE join;
    SNAPCG_HASHTABLE_INIT(join);

    JOIN_SNAP_CSG(db2->SNAP_TABLE, db2->CSG_TABLE, join);
    printf("\n    3. Join: SNAP ▷◁ CSG\n\n");
    SNAPCG_HASHTABLE_PRINT(join);

    SNAPCG_HASHTABLE select_gon;
    SNAPCG_HASHTABLE_INIT(select_gon);
    SELECT_SNAPCG_NAME("O. Gonzalez", join, select_gon); //Select O. Gonzalez from SNAP ▷◁ CSG

    CSG_HASHTABLE result;
    CSG_HASHTABLE_INIT(result);
    PROJECT_CSG(select_gon, result); //Project CSG from the previous table

    printf("\n  4. All three operators: πStudentId,Course,Grade(σName=“O. Gonzalez”(SNAP ▷◁ CSG))\n\n");
    CSG_HASHTABLE_PRINT(result, 1);

    free(name2);
    free(day);
    free(hour);
    free(name);
    free(course);
    free(db);
    free(db2);
}