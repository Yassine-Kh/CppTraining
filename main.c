#include <stdio.h>
#include <ctype.h>
#include "functions1.c"
#include "test.c"
#include "CCI.c"

void session1(){
    printf("my_aff_alpha\n");
    my_aff_alpha();
    printf("\n\n");
    printf("my_aff_num\n");
    my_aff_num();
    printf("\n\n");
    printf("my_isneg(-5) \n");
    my_isneg(-5);
    printf("\n");
    printf("my_isneg(5) \n");
    my_isneg(5);
    printf("\n");
    printf("my_isneg(0) \n");
    my_isneg(0);
    printf("\n");
    printf("my_isneg('okcden')\n");
    my_isneg('5');
    printf("\n\n");
    printf("aff_comb\n");
    aff_comb();
}

void session2()
    {
        printf("my_putNbr(0):\n");
        my_putNbr(0);
        printf("\n\n");
        printf("my_putNbr(500):\n");
        my_putNbr(500);
        printf("\n\n");
        printf("my_putNbr(-500):\n");
        my_putNbr(-500);
        printf("\n\n");
        printf("my_putNbr(2 147 483 647):\n");
        my_putNbr(2147483647);
        printf("\n\n");
        printf("my_putNbr(-2 147 483 648):\n");
        my_putNbr(-2147483648);
        printf("\n\n");
    }

void session3()
{
    int i;
    int j;
    int* pi;
    int* pj;
    char test[] = "whatever";

    i = 1;
    j = 2;
    pi = &i;
    pj = &j;
    printf("values were equal to  %i %i\n", *pi, *pj);
    printf("my_swap(*i, *j):\n");
    my_swap(pi, pj);
    printf("values are now %i %i\n\n", *pi, *pj);
    printf("my_strlen( 'ma chaine de caracteres' )\n");
    printf("%i\n\n", my_strlen("ma chaine de caracteres"));
    printf("my_strlen( '' )\n");
    printf("%i\n\n", my_strlen(""));
    printf("my_strlen( 0 )\n");
    printf("%i\n\n", my_strlen("\0"));

    printf("my_putstr( 'ma chaine de caracteres' )\n");
    my_putstr("ma chaine de caracteres");
    printf("\n\n");

    printf("evil_str( 'whatever' )\n");
    evil_str(test);
    printf(test);
    printf("\n\n");

    char * l = "fiebfi12345r";
    printf("%i",my_getnbr(l));
}

void session4()
{
    int n;
    int power;
    char *dest;
    char *src;

    n = 5;
    power = 2;
    printf("my_pow_it(5, 2) = %i\n", my_pow_it(2,2));
    printf("my_pow_rec(5, 2) = %i\n", my_pow_rec(2,2));
    printf("my_factoriel_it(5) = %i\n", my_factoriel_it(5));
    printf("my_factoriel_rec(5) = %i\n", my_factoriel_rec(2));

    src = "test";
    dest = malloc(sizeof(char) * my_strlen(src)*2);

    my_strncpy(dest, src, 8);
    printf('\0');

    dest = "ttestijdi";

    printf("La comparaison donne: %i \n",my_strncmp( dest, src, 8 ));

    printf("Ca contient : %s\n", my_strstr( dest, src ));

    printf("%s\n", my_str_upper(src));
    char* test2 = "TESTINGthis";
    printf("%s\n", my_str_lower(test2));
    printf("%s\n", my_str_capitalize(test2));
    char *test3 = ";";
    printf("Is it alpha %i\n", my_str_is_alpha(test3));
    char *test4 = "l";
    printf("Is it num %i\n", my_str_is_num(test4));

    printf("testing %i\n",  isprint(32));
    printf("my_testing %i\n", my_str_is_printable("i"));
    printf("searching target in %s", my_strchr("test", 't'));
    //printf("%c", 116-'a'+'A');
// a 97  z 122 A 65  Z 90
}


int main() {
    //session1();
    //test();
    //session2();
    //session3();
    //session4();
    /*
    printf("\n");
    int k;
    int u;
    int * pu = &u;
    *pu = 100;

    k = *pu;
    printf("Premier k est %i\n", k);
    printf("Premier pu est %i\n", *pu);
    *pu = 500;
    printf("Second k est %i\n",k );
    printf("Second pu est %i\n", *pu);
    double x;
    x=123.54547;
    int c =x;
    printf("%f\n", x/1);
    printf("%i\n", c);
    while(x > 1){
        x --;
    }
    c = x;
    printf("%i\n", c);
    while (!( c <= x + 0.001 && c >= x - 0.001)) {
        x= x * 10;
        c=x;
    }
    printf("%i\n", c);
     */
    cci();
    //int test[3] = {5, 6, 9};

    //printf("%i", *(test + 1));
    return 0;
}
