//
// Created by yassine on 12/10/22.
//
#include <unistd.h>
#include <assert.h>
#include <stdlib.h>

void my_putchar(char c){
    write(1, &c, 1);
}

void my_aff_alpha(){
    char alphabet;

    alphabet = 'a';
    while (alphabet <= 'z'){
        my_putchar(alphabet);
        alphabet ++;
    }
}

void my_aff_num(){
    char i;

    i = '0';
    while (i <= '9'){
        my_putchar(i);
        i++;
    }
}

void my_isneg(int n){
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
}

void aff_nbr(int cent, int deca, int unit) {
    my_putchar(cent);
    my_putchar(deca);
    my_putchar(unit);
    if (cent != '7' ) {
        my_putchar(',');
        my_putchar(' ');
    }
}

void aff_comb() {
    char cent;
    char deca;
    char unit;

    cent = '1';
    while (cent <= '7') {
        deca = cent + 1;
        while (deca <= '8') {
            unit = '3';
            while (unit <= '9') {
                if (unit > deca && deca > cent) {
                    aff_nbr(cent, deca, unit);
                }
                unit = unit + 1;
            }
            deca = deca + 1;
        }
        cent = cent + 1;
    }
}

void my_putNbr(int param)
{
    if ( param < 0 )
    {
        my_putchar('-' );
        if ( param == -2147483648 )
        {
            my_putchar( 2 + '0' );
            param = 147483648;
        }
        else
        {
            param = param * -1;
        }

    }
    if ( param < 9 )
    {
        my_putchar( param + '0' );
    }
    else
    {
        my_putNbr( param / 10 );
        my_putchar(param%10 + '0' );
    }
}

void my_putNbr2(int param)
{
    int unit;

    if ( param < 0 )
    {
        my_putchar('-' );
        if ( param == -2147483648 )
        {
            my_putchar( 2 + '0' );
            param = 147483648;
        }
        else
        {
            param = param * -1;
        }

    }
    unit = param;
    while( unit > 9 )
    {
        unit = unit / 10;
        if ( unit < 9 )
        {
            my_putchar( unit + '0' );
            param = param / 10;
            unit = param;
        }
    }
}

void my_swap(int* v1, int* v2)
{
    int v3;

    v3 = *v2;
    *v2 = *v1;
    *v1 = v3;
}

int my_strlen(const char* s)
{
    int i;

    i = 0;
    while( s[i] != '\0' )
    {
        i++;
    }
    return(i);
}

void my_putstr(char* s)
{
    while( *s != '\0' )
    {
        my_putchar(*s);
        s++;
    }
}

char* evil_str(char s[])
{
    int len;
    int i;
    char temp;

    i = 0;
    len = my_strlen(s);
    while(i <= len / 2 - 1)
    {
        temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
        i++;
    }
    return(s);
}

int my_getnbr(char* s)
{
    int i;
    int checkOneNumber;

    checkOneNumber = 0;
    i = 0;

    while( *s != '\0' )
    {
        if ( *s >= '0' && *s <= '9' )
        {
            if (checkOneNumber == -1)
            {
                return 0;
            }
            checkOneNumber++;
            i = i * 10;
            i += *s -'0';
        }
        else
        {
            if ( checkOneNumber > 0 )
            {
                checkOneNumber = -1;
            }
        }
        s++;
    }
    return i;
}


// calcule la puissance en iteratif
int my_pow_it(int n, int power)
{
    int number;

    assert( power >= 0 );
    if ( power == 0 )
    {
        return 1;
    }
    number = n ;
    while( power > 1 )
    {
        number = number * n;
        power --;
    }
    return number;
}

// calcule la puissance en recursif
int my_pow_rec(int n, int power)
{
    if ( power == 1 )
    {
        return n;
    }
    else if ( power == 0 )
    {
        return 1;
    }
    return n * my_pow_rec( n, power - 1);
}

// calcule la factorielle en iteratif
int my_factoriel_it(int n)
{
    int range;

    assert( n >= 0 );
    if ( n == 0 )
    {
        return 1;
    }
    range = n - 1;
    while ( range > 1 )
    {
        n = n * range ;
        range --;
    }
    return n;
}

// calcule la factiorielle en recursif
int my_factoriel_rec(int n)
{
    if ( n == 1 )
    {
        return n;
    }
    else if ( n == 0 )
    {
        return 1;
    }
    return n * my_factoriel_rec( n - 1 );
}

char *my_strcpy(char *dest, const char *src)
{
    while( *src != '\0' )
    {
        *dest = *src;
        src += 1;
        dest += 1;
    }
    *dest = '\0';
    return dest;
}

char *my_strncpy(char *dest, char *src, size_t n)
{
    size_t len;

    len = 0;
    while( *(src + len) != '\0' && len < n)
    {
        *(dest + len) = *(src + len);
        len ++;
    }
    while(len < n )
    {
        *(dest + len) = '\0';
        len ++;
    }
    return dest;
}

int my_strcmp(char *s1, char *s2)
{
    int index;

    index = 0;
    while( s1[index] != '\0' && s1[index] == s2[index])
    {
        index++;
    }
    return ( s1[index] - s2[index] );
}

int my_strncmp(char *s1, char *s2, size_t n)
{
    int index;

    index = 0;
    while( s1[index] != '\0' && s1[index] == s2[index] && index < n)
    {
        index++;
    }
    return ( s1[index] - s2[index] );
}


char *my_strstr(char *haystack, char *needle)
{
    int countNeedle;
    int countHaystack;

    countHaystack = 0;
        while( *(haystack + countHaystack) != '\0')
        {
            countNeedle = 0;
            while(*(haystack + countHaystack + countNeedle) == *(needle + countNeedle))
            {
                if (*(needle + countNeedle) == '\0')
                {
                    return haystack + countHaystack;
                }
                countNeedle ++;
            }
            if (*(needle + countNeedle) == '\0')  // Si *(haystack + countHaystack + countNeedle) != '\0'
            {
                return haystack + countHaystack;
            }
            countHaystack ++;
        }
        return NULL;
}

char *my_str_upper(char *s)
{
    char *dest;
    int pos;

    pos = 0;
    dest = malloc(sizeof(char) * (my_strlen(s)+1));
    while (*(s + pos) != '\0')
    {
        if (*(s + pos) <= 'z' && *(s + pos) >= 'a')
        {
            *(dest + pos) = *(s + pos) - 'a' + 'A';
        }
        else
        {
            *(dest + pos) = *(s + pos);
        }
        pos++;
    }
    *(dest + pos) = '\0';
    return dest;
}

char *my_str_lower(char *s)
{
    char *dest;
    int pos;

    pos = 0;
    dest = malloc(sizeof(char) * (my_strlen(s)+1));
    while (*(s + pos) != '\0')
    {
        if (*(s + pos) <= 'Z' && *(s + pos) >= 'A')
        {
            *(dest + pos) = *(s + pos) + 'a' - 'A';
        }
        else
        {
            *(dest + pos) = *(s + pos);
        }
        pos++;
    }
    *(dest + pos) = '\0';
    return dest;
}
char *my_str_capitalize(char *s)
{
    char *dest;
    int pos;

    dest = malloc(sizeof(char) * (my_strlen(s)+1));
    if (*s <= 'z' && *s >= 'a')
    {
        *dest = *s - 'a' + 'A';
    }
    else
    {
        *dest = *s;
    }
    pos = 1;
    while (*(s + pos) != '\0')
    {
        if (*(s + pos) <= 'Z' && *(s + pos) >= 'A')
        {
            *(dest + pos) = *(s + pos) + 'a' - 'A';
        }
        else
        {
            *(dest + pos) = *(s + pos);
        }
        pos++;
    }
    *(dest + pos) = '\0';
    return dest;
}

int my_str_is_alpha(char *s)
{
    if ((*s <= 'z' && *s >= 'a') || (*s <= 'Z' && *s >= 'A'))
    {
        return 1;
    }
    return 0;
}

int my_str_is_num(char *s)
{
    if (*s <= '9' && *s >= '0')
    {
        return 1;
    }
    return 0;
}

int my_str_is_printable(char *s)
{
    if (*s >= ' ' && *s <= '~')
    {
        return 1;
    }
    return 0;
}

char *my_strchr(char *s, char target)
{
    while (*s != '\0')
    {
        if (*s == target)
        {
            return s;
        }
        s ++;
    }
    return NULL;
}

char *my_strcat(char *dest, const char *src) {
    int index1;
    int index2;

    index1 = 0;
    index2 = 0;
    while(dest[index1] != '\0')
    {
        index1++;
    }
    while(src[index2] != '\0')
    {
        dest[index1 + index2] = src[index2];
        index2++;
    }
    dest[index1 + index2] = '\0';
    return dest;
}

char *my_strncat(char *dest, const char *src, size_t n)
{
    int index1;
    int index2;

    index1 = 0;
    index2 = 0;
    while(dest[index1] != '\0')
    {
        index1++;
    }
    while(src[index2] != '\0' && index2 < n)
    {
        dest[index1 + index2] = src[index2];
        index2++;
    }
    dest[index1 + index2] = '\0';
    return dest;
}

char * my_strdup( const char * source )
{
    int leng;
    int index;
    char *s = (char *) 0;

    index = 0;
    leng = my_strlen(source) + 1;
    while(s == (char *) 0)
    {
        s = malloc(leng * sizeof *s);
    }
    while(source[index] != '\0')
    {
        s[index] = source[index];
        index++;
    }
    s[index] = '\0';
    return s;
}

char * my_strdup2( const char * source ) {
    int leng;
    char *s = (char *) 0;

    leng = my_strlen(source);
    while (s == (char *) 0) {         // Ne jamais faire caaaa !!! Ca va niquer la memoire. Mettre un if a la place.
        s = malloc(( leng + 1 ) * sizeof *s);
    }
    return my_strcat(s, source);
}



// Argc et argv :

void show(int argc, char** argv)
{
    int index;

    index = 0;
    while( index < argc )
    {
        my_putstr(argv[index]);
        index++;
    }
}

void showWeird(int argc, char** argv)
{
    int index;

    index = argc - 1;
    while( index >= 0 )
    {
        my_putstr(argv[index]);
        index--;
    }
}

