#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    //0.1 : 
    FILE* fdouble_1 = fopen("double_0p3.csv", "w");
    FILE* fldouble_1 = fopen("ldouble_0p3.csv", "w");

    double sum_double = 0.25; 
    long double sum_ldouble = 0.25; 
    double denominator_double = 1/32.0;
    long double denominator_ldouble = 1/32.0L;

    //Ensuring that it is open : 
    fprintf(stdout, "Check open file : \n");
    if(!fdouble_1 || !fldouble_1) {
        fprintf(stderr, "File opening fail");
        return EXIT_FAILURE;
    }

    fprintf(stdout, "For representation of 0.3 in 0.1 + 0.2 : \n");
    fprintf(fdouble_1, "iteration,value\n");
    fprintf(fldouble_1, "iteration,value\n");
    
    for(int i = 0; i<=20; i++) {
        sum_double += (denominator_double + 0.5*denominator_double);
        sum_ldouble += (denominator_ldouble + 0.5L*denominator_ldouble);
        denominator_ldouble /= 16L;
        denominator_double /= 16.0;
        fprintf(fdouble_1, "%i,%.30f\n", i, sum_double);
        fprintf(fldouble_1, "%i,%.30Lf\n", i, sum_ldouble);
    }

    fclose(fdouble_1); fclose(fldouble_1);



    //0.6 : 
    FILE* fdouble_2 = fopen("double_0p6.csv", "w");
    FILE* fldouble_2 = fopen("ldouble_0p6.csv", "w");

    sum_double = 0.5; 
    sum_ldouble = 0.5; 
    denominator_double = 1/16.0;
    denominator_ldouble = 1/16.0L;

    //Ensuring that it is open : 
    fprintf(stdout, "Check open file : \n");
    if(!fdouble_1 || !fldouble_1) {
        fprintf(stderr, "File opening fail");
        return EXIT_FAILURE;
    }

    puts("\n\nFor representation of 0.6 in 0.1 + 0.5\n");
    fprintf(fdouble_2, "iteration,value\n");
    fprintf(fldouble_2, "iteration,value\n");
    for(int i = 0; i<=20; i++) {
        sum_double += (denominator_double + 0.5*denominator_double);
        sum_ldouble += (denominator_ldouble + 0.5L*denominator_ldouble);
        denominator_ldouble /= 16L;
        denominator_double /= 16.0;
        fprintf(fdouble_2, "%i,%.30f\n", i, sum_double);
        fprintf(fldouble_2, "%i,%.30Lf\n", i, sum_ldouble);
    }
    fclose(fdouble_2); fclose(fldouble_2);

    return 0; 
}