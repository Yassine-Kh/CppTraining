//
// Created by yassine on 03/11/22.
//

// Is Unique: Implement an algorithm to determine if a string has all unique characters.

_Bool isUnique(char *unique)
{
    char ascii[127] = {0};
    while(*unique != '\0')
    {
        ascii[*unique] ++;
        unique++;
    }
    int pos = 0;
    while ( pos <= 126 )
    {
        if (ascii[pos] > 1 )
        {
            return(0);
        }
        pos ++;
    }
    return 1;
}
// What if you cannot use additional data structures?
_Bool isUnique2(char *unique)
{
    char* ptr;

    ptr = unique;
    while (*ptr != '\0')
    {
        unique = ptr + 1;
        while (*unique != '\0')
        {
            if (*ptr == *unique)
            {
                return 0;
            }
            unique++;
        }
        ptr++;
    }
    return 1;
}

//Check Permutation: Given two strings, write a method to decide if one is a permutation of the
//other
_Bool permutation(char *s1, char* s2)
{
    char ascii[126] = {0};
    while (*s1 != '\0')
    {
        ascii[*s1]++;
        s1++;
    }
    while (*s2 != '\0')
    {
        ascii[*s2]--;
        s2++;
    }
    int pos = 0;
    while(pos<=125)
    {
        if (ascii[pos] != 0)
        {
            return 0;
        }
        pos++;
    }
    return 1;
}

//URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string
//has sufficient space at the end to hold the additional characters, and that you are given the "true"
//length of the string.

char* URLify(char s[], int len)
{
    int pos;
    int pos2;
    int spaceCount;

    spaceCount = 0;
    pos = 0;
    while(pos < len)
    {
        if (s[pos] == ' ')
        {
            spaceCount++;
        }
        pos++;
    }
    pos = len - 1;
    pos2 = len + spaceCount * 2 - 1;
    while (pos >= 0)
    {
        if (s[pos] == ' ') {
            s[pos2] = '0';
            s[pos2 - 1] = '2';
            s[pos2 - 2] = '%';
            pos2 = pos2 - 3;
        }
        else
        {
            s[pos2] = s[pos];
            pos2--;
        }
        pos--;
    }
    return s;
}

void cci()
{
    printf("%i\n", isUnique("jesai    pa"));
    printf("%i\n", isUnique2("jesaipa"));
    printf("%i\n", permutation("qwer", "rewq"));
    char test[] = "test test test    ";
    printf("%s\n", URLify(test, 14));
}