//
// Created by Siddharth Narsipur on 11/28/23.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Database.h"
#include "string-extras.h"

Database* CREATE_DB(){
    Database* db = malloc(sizeof(struct Database));

    SNAP_HASHTABLE snap_table;
    SNAP_HASHTABLE_INIT(snap_table);

    SNAP_TUPLE* a = SNAP_NEW("66252", "L. Adams", "55 Pear Ave.", "455-9284");
    SNAP_TUPLE* b = SNAP_NEW("01376", "R. Johnson", "88 Apple Dr.", "717-5542");
    SNAP_TUPLE* c = SNAP_NEW("39391", "O. Gonzalez", "62 Durian Blvd.", "687-6203");
    SNAP_TUPLE* d = SNAP_NEW("74533", "C. Johnson", "5 Raisin Ln.", "992-4616");
    SNAP_TUPLE* e = SNAP_NEW("58429", "O. Gonzalez", "78 Rhubarb Ave.", "171-8839");
    SNAP_TUPLE* f = SNAP_NEW("99730", "R. Johnson", "56 Kiwi Blvd.", "903-9855");

    SNAP_INSERT(a,snap_table);
    SNAP_INSERT(b,snap_table);
    SNAP_INSERT(c,snap_table);
    SNAP_INSERT(d,snap_table);
    SNAP_INSERT(e,snap_table);
    SNAP_INSERT(f,snap_table);

    CSG_HASHTABLE csg_table;
    CSG_HASHTABLE_INIT(csg_table);

    CSG_TUPLE* g = CSG_NEW("CSC171", "66252", "A");
    CSG_TUPLE* h = CSG_NEW("CSC171", "58429", "B");
    CSG_TUPLE* i = CSG_NEW("MATH150", "39391", "A");
    CSG_TUPLE* j = CSG_NEW("DSCC201", "66252", "C");
    CSG_TUPLE* k = CSG_NEW("DSCC201", "01376", "B+");
    CSG_TUPLE* l = CSG_NEW("CSC172", "99730", "A-");
    CSG_TUPLE* m = CSG_NEW("MATH150", "58429", "C+");
    CSG_TUPLE* n = CSG_NEW("CSC173", "74533", "B+");
    CSG_TUPLE* o = CSG_NEW("CSC173", "99730", "A");
    CSG_TUPLE* p = CSG_NEW("DSCC201", "99730", "C");


    CSG_INSERT(g, csg_table);
    CSG_INSERT(h, csg_table);
    CSG_INSERT(i, csg_table);
    CSG_INSERT(j, csg_table);
    CSG_INSERT(k, csg_table);
    CSG_INSERT(l, csg_table);
    CSG_INSERT(m, csg_table);
    CSG_INSERT(n, csg_table);
    CSG_INSERT(o, csg_table);
    CSG_INSERT(p, csg_table);

    CP_HASHTABLE cp_table;
    CP_HASHTABLE_INIT(cp_table);

    CP_TUPLE* q = CP_NEW("CSC172", "CSC171");
    CP_TUPLE* r = CP_NEW("CSC172", "MATH150");
    CP_TUPLE* s = CP_NEW("CSC173", "CSC172");
    CP_TUPLE* t = CP_NEW("CSC252", "CSC172");
    CP_TUPLE* u = CP_NEW("CSC254", "CSC252");
    CP_TUPLE* v = CP_NEW("DSCC201", "CSC171");
    CP_TUPLE* w = CP_NEW("DSCC202", "DSCC201");
    CP_TUPLE* x = CP_NEW("DSCC265", "CSC262");
    CP_TUPLE* y = CP_NEW("DSCC265", "CSC171");

    CP_INSERT(q, cp_table);
    CP_INSERT(r, cp_table);
    CP_INSERT(s, cp_table);
    CP_INSERT(t, cp_table);
    CP_INSERT(u, cp_table);
    CP_INSERT(v, cp_table);
    CP_INSERT(w, cp_table);
    CP_INSERT(x, cp_table);
    CP_INSERT(y, cp_table);

    CDH_HASHTABLE cdh_table;
    CDH_HASHTABLE_INIT(cdh_table);

    CDH_TUPLE* aa = CDH_NEW("CSC171", "M", "1400");
    CDH_TUPLE* ab = CDH_NEW("CSC171", "W", "1400");
    CDH_TUPLE* ac = CDH_NEW("CSC172", "M", "1525");
    CDH_TUPLE* ad = CDH_NEW("CSC172", "W", "1640");
    CDH_TUPLE* ae = CDH_NEW("CSC173", "M", "1400");
    CDH_TUPLE* af = CDH_NEW("CSC173", "W", "1400");
    CDH_TUPLE* ag = CDH_NEW("CSC252", "M", "1230");
    CDH_TUPLE* ah = CDH_NEW("CSC252", "W", "1230");
    CDH_TUPLE* ai = CDH_NEW("DSCC201", "T", "900");
    CDH_TUPLE* aj = CDH_NEW("DSCC201", "R", "900");
    CDH_TUPLE* ak = CDH_NEW("DSCC202", "T", "1650");
    CDH_TUPLE* al = CDH_NEW("DSCC202", "R", "1650");
    CDH_TUPLE* am = CDH_NEW("DSCC265", "T", "1400");
    CDH_TUPLE* an = CDH_NEW("DSCC265", "R", "1400");

    CDH_INSERT(aa, cdh_table);
    CDH_INSERT(ab, cdh_table);
    CDH_INSERT(ac, cdh_table);
    CDH_INSERT(ad, cdh_table);
    CDH_INSERT(ae, cdh_table);
    CDH_INSERT(af, cdh_table);
    CDH_INSERT(ag, cdh_table);
    CDH_INSERT(ah, cdh_table);
    CDH_INSERT(ai, cdh_table);
    CDH_INSERT(aj, cdh_table);
    CDH_INSERT(ak, cdh_table);
    CDH_INSERT(al, cdh_table);
    CDH_INSERT(am, cdh_table);
    CDH_INSERT(an, cdh_table);

    CR_HASHTABLE cr_table;
    CR_HASHTABLE_INIT(cr_table);

    CR_TUPLE* ba = CR_NEW("CSC171", "Hutchinson Hall 141");
    CR_TUPLE* bb = CR_NEW("CSC172", "Hutchinson Hall 141");
    CR_TUPLE* bc = CR_NEW("CSC173", "Wegmans 1400");
    CR_TUPLE* bd = CR_NEW("CSC252", "Wegmans 1400");
    CR_TUPLE* be = CR_NEW("CSC254", "Wegmans 1400");
    CR_TUPLE* bf = CR_NEW("DSCC201", "Bausch & Lomb 109");
    CR_TUPLE* bg = CR_NEW("DSCC202", "Dewey 2162");
    CR_TUPLE* bh = CR_NEW("DSCC265", "Wegmans 1400");
    CR_TUPLE* bi = CR_NEW("MATH150", "Harkness 115");

    CR_INSERT(ba, cr_table);
    CR_INSERT(bb, cr_table);
    CR_INSERT(bc, cr_table);
    CR_INSERT(bd, cr_table);
    CR_INSERT(be, cr_table);
    CR_INSERT(bf, cr_table);
    CR_INSERT(bg, cr_table);
    CR_INSERT(bh, cr_table);
    CR_INSERT(bi, cr_table);

    memcpy(db->SNAP_TABLE, snap_table, sizeof(SNAP_HASHTABLE));
    memcpy(db->CDH_TABLE, cdh_table, sizeof(CDH_HASHTABLE));
    memcpy(db->CR_TABLE, cr_table, sizeof(CR_HASHTABLE));
    memcpy(db->CSG_TABLE, csg_table, sizeof(CSG_HASHTABLE));
    memcpy(db->CP_TABLE, cp_table, sizeof(CP_HASHTABLE));

    return db;
}

void PRINT_DB(Database* db){
    printf("\n");
    SNAP_HASHTABLE_PRINT(db->SNAP_TABLE);
    CSG_HASHTABLE_PRINT(db->CSG_TABLE, 0);
    CP_HASHTABLE_PRINT(db->CP_TABLE);
    CDH_HASHTABLE_PRINT(db->CDH_TABLE);
    CR_HASHTABLE_PRINT(db->CR_TABLE);

}

void GET_GRADE(char* name, char* course, SNAP_HASHTABLE s, CSG_HASHTABLE c){
    bool match = false;
    for(int i = 0; i<SNAP_HASHTABLE_SIZE; i++){
        SNAP_TUPLE *p = s[i];

        while(p != NULL){
            if(streq(p->name, name)){
                int j = CSG_HASH(p->studentID);
                CSG_TUPLE *r = c[j];
                    while(r != NULL){
                        if(streq(r->course, course)){
                            printf("%s GOT GRADE %s IN %s\n", name, r->grade, course);
                            match = true;
                        }
                        r = r->next;
                    }
                    break;
            }
            p = p->next;
        }}

    if(!match) {
        printf("No such student and course combination");
    }
}

void GET_LOCATION(char* name, char* hour, char* day, SNAP_HASHTABLE sp, CDH_HASHTABLE cdh, CSG_HASHTABLE csg, CR_HASHTABLE cr){
    bool match = false;

    for(int i = 0; i<SNAP_HASHTABLE_SIZE; i++) {
        SNAP_TUPLE *p = sp[i];

        while(p != NULL){
            if(streq(p->name, name)) {
                char* id = p->studentID;
                int j = CSG_HASH(id);

                CSG_TUPLE *q = csg[j];

                while(q != NULL){
                    if(streq(q->studentID, id)){
                        char* course = q->course;
                        int k = CDH_HASH(course);

                        CDH_TUPLE *r = cdh[k];

                        while(r != NULL){
                            if(streq(r->course, course) && streq(r->day, day) && streq(r->hour, hour)){
                                int l = CR_HASH(course);

                                CR_TUPLE *s = cr[l];

                                while(s != NULL){
                                    if(streq(course, s->course)){
                                        char* room = s->room;
                                        printf("%s is in %s at %s on %s\n", name, room, hour, day);
                                        match = true;
                                    }
                                    s = s->next;
                                }
                            }
                            r = r->next;
                        }
                    }
                    q = q->next;
                }
            }
            p = p->next;
        }
    }
    if(!match) {
        printf("No such student and hour/day combination");
    }
}
