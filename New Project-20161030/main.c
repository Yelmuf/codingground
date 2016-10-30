#include <stdio.h>


int main(void) {
    FILE *input;
    int i,j,k, n = 0, r = 1, a, b;
    input = fopen("darky.in", "r");
    fscanf(input, "%i", &n);

    int rule[n+1];
    rule[0] = 0;

    for (i = 1; i <= n; ++i) fscanf(input, "%i", &rule[i]);
    fclose(input);

    char dareno[n+1];

    for (k = 1; k <= n; ++k) {
        b=1;
        //printf("Pro k=%i:\n", k);
        for (j = 0; j <= n; ++j) {
            dareno[j] = 'n';
        }

        a = rule[k];
        dareno[k] = 'y';
        while(dareno[a]!='y') {
            dareno[a]='y';
            b++;

            /*printf("r=%i: (new dareno[%i]=%c) ", r, a, dareno[a]);
            for (int l = 1; l <= n; ++l) {
                printf("%c", dareno[l]);
            }
            printf(" %i->",  a);   */
            a = rule[a];
            //printf("%i\n", a);
        }
        if(b>r) r=b;
    }

    FILE *output;
    output = fopen("darky.out", "w");
    fprintf(output, "%i", r);
    fclose(output);
    printf("%i\n", r);
    return r;
}