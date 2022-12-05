#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    char* name;
    char* grade;
};

int main(int argc, char* argv[]){
    struct student* s1 = malloc(sizeof(struct student));
    s1->name = "mino\0";
    s1->grade = "B\0";
    fprintf(stderr, "name: %s\tgrade: %s\n", s1->name, s1->grade);

    struct student* s2 = malloc(sizeof(struct student));
    s2->name = "citron\0";
    s2->grade = "A\0";
    fprintf(stderr, "name: %s\tgrade: %s\n", s2->name, s2->grade);

    struct student* s3 = malloc(sizeof(struct student));
    s3->name = "ja\0";
    s3->grade = "C\0";
    fprintf(stderr, "name: %s\tgrade: %s\n", s3->name, s3->grade);

    free(s2);

    struct student* s4 = malloc(sizeof(struct student));
    fprintf(stderr, "name: %s\tgrade: %s\n", s4->name, s4->grade);

    return 0;
}