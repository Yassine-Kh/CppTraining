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
//Given a string, write a function to check if it is a permutation of a palin-
//drome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation
//is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.

_Bool permPal(char *s)
{
    char ascii[126] = {0};
    int pos;
    int one = 0;

    pos = 0;
    while( *s != '\0')
    {
        ascii[*s]++;
        s++;
    }
    while(pos < 126)
    {
        if (ascii[pos] % 2 == 0 || pos == ' ')
        {
            pos++;
            continue;
        }
        else if(ascii[pos] % 2 == 1)
        {
            if (one == 0)
            {
                one++;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
        pos++;
    }
    return 1;
}

//Implement a method to perform basic string compression using the counts
//of repeated characters. For example, the string a a b c c c c c a a a would become a 2 b l c 5 a 3 , If the
//"compressed" string would not become smaller than the original string, your method should return
//the original string. You can assume the string has only uppercase and lowercase letters (a - z).

// FALSE IMPLEMENTATION ==> doesn't give the right order of the first string
char* falseCompression(char *s)
{
    char newStr[52];
    char ascii[26] = {0};
    int i;
    char *newStrPtr;
    char letter;
    char previousLetter;
    char* sPtr;

    sPtr = s;
    while( *sPtr != '\0' )
    {
        ascii[*sPtr - 'a']++;
        sPtr++;
    }
    letter = *s;
    previousLetter = *s;
    newStr[0] =  letter ;
    newStr[1] =  ascii[letter - 'a'] + '0';
    i = 2;
    while(letter != '\0')
    {
        if (previousLetter != letter)
        {
            newStr[i] =  letter ;
            newStr[i + 1] =  ascii[letter - 'a'] + '0';
            i += 2;
        }
        previousLetter = letter;
        s++;
        letter = *(s);
    }
    newStr[i] = '\0';
    newStrPtr = newStr;
    return newStrPtr;
}

char* compression(char *s, char* newStr)
{
    char    previousLetter;
    char    *newStrPtr;
    char    letter;
    char    *sPtr;
    int     count;
    int     length;
    int     newLength;

    letter = *s;
    previousLetter = letter;
    newStr[0] = letter;
    newLength = 1;
    length = 0;
    count = 0;
    sPtr = s;
    while(*sPtr != '\0')
    {
        length++;
        if (letter != previousLetter)
        {
            newStr[newLength] = count + '0';;
            newStr[newLength + 1] = letter;
            count = 0;
            newLength += 2;
        }
        else
        {
            count++;
        }
        previousLetter = letter;
        sPtr++;
        if (*sPtr == ' ')
        {
            sPtr += 2;
        }
        letter = *sPtr;
    }
    newStr[newLength] = count + 1 + '0';
    newStr[newLength + 1] = '\0';
    newStrPtr = newStr;
    if (length <= newLength) return s;
    else return newStrPtr;
}

//One Away: There are three types of edits that can be performed on strings: insert a character,
//remove a character, or replace a character. Given two strings, write a function to check if they are
//one edit (or zero edits) away.
_Bool edit(char* oldString, char* newString)
{
    int nbrModif;

    nbrModif = 0;
    while(*oldString != '\0')
    {
        if (*newString == '\0' )
        {
            if (*(newString - 1) == *(oldString)) newString = newString - 1;
            else
            {
                nbrModif++;
                if (nbrModif > 1)
                {
                    return 0;
                }
            }
        }
        if( *oldString != *newString)
        {
            if ( nbrModif == 1 && *oldString == *(newString + 1))
            {
                oldString = oldString - 1;
            }
            else if ( nbrModif == 1 && *oldString == *(newString - 1))
            {
                newString = newString - 1;
            }
            else
            {
                nbrModif++;
                if (nbrModif > 1)
                {
                    return 0;
                }
            }
        }
        oldString++;
        if (*newString != '\0')
        {
            if (*oldString == '\0') {
                if (*(oldString-1) == *(newString+1))
                {
                    newString ++;
                }
            }
            newString++;
        }
    }
    while (*newString != '\0')
    {
        nbrModif++;
        if (nbrModif > 1)
        {
            return 0;
        }
        newString++;
    }
    return 1;
}

//String Rotation; Assume you have a method isSubstring which checks if one word is a substring
//of another. Given two strings, si and s2, write code to check if s2 is a rotation of si using only one
//call to isSubstring [e.g., "waterbottle" is a rotation of 'erbottlewat" )
char *isSubstring(char *haystack, char *needle) {
    {
        int countNeedle;
        int countHaystack;

        countHaystack = 0;
        while (*(haystack + countHaystack) != '\0') {
            countNeedle = 0;
            while (*(haystack + countHaystack + countNeedle) == *(needle + countNeedle)) {
                if (*(needle + countNeedle) == '\0') {
                    return haystack + countHaystack;
                }
                countNeedle++;
            }
            if (*(needle + countNeedle) == '\0')  // Si *(haystack + countHaystack + countNeedle) != '\0'
            {
                return haystack + countHaystack;
            }
            countHaystack++;
        }
        return NULL;
    }
}

_Bool checkRotation(char* s1, char* s2)
{
    int length;
    char *doubleStr;
    char *ptr;

    ptr = s1;
    length = 0;
    while ( *ptr != '\0')
    {
        length++;
        ptr++;
    }
    doubleStr = malloc(2 * length * sizeof(char));
    strcpy(doubleStr, s1);
    strcpy(doubleStr + length, s1);
    if (isSubstring(doubleStr, s2))
    {
        return 1;
    }
    return 0;
}


/////////////////////////////////////////////////////////PYTHON LIST ///////////////////////////////////////////////////
#define typeList char*

typedef struct
{
    typeList *list;
    int length;
    int used;
}python_list;

void initList(python_list *list)
{
    list -> list = malloc(sizeof(typeList));
    list -> length = 1;
    list -> used = 0;
}

void add(python_list* list, typeList element)
{
    if (list -> length == list -> used + 1)
    {
        int pos;

        typeList *newList;
        newList = malloc(sizeof(typeList) * 2 * list -> length);
        pos = 0;
        while (pos < list -> length - 1)
        {
            newList[pos] = list -> list[pos];
            pos++;
        }
        free(list -> list);
        list -> list = malloc(sizeof(typeList) * 2 * list -> length);
        list -> list = newList;
        list -> length = list -> length * 2;
    }
    list -> list[list -> length - 2] = element;
    printf("%s", list -> list[list -> length -2]);
    list -> used++;
}

//Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
//column are set to 0,
void zeroMatrix(size_t rows, size_t columns, int matrix[rows][columns])
{
    typedef struct {
        int row;
        int col;
    } ztuple;
    int i,j, zi, zj;
    

    i = 0;
    j = 0;
    zi = 0;
    zj = 0;
    while ( i < rows )
    {
        while ( j < columns )
        {
            if (matrix[i][j] == 0 )
            {
                zi = 0;
                zj = 0;
                while ( zi < rows )
                {
                    matrix[zi][j] = 0;
                    zi++;
                }
                while ( zj < columns )
                {
                    matrix[i][zj] = 0;
                    zj++;
                }
                i++;
                j++;
                break;
            }
            j++;
        }
        i++;
    }

}

void cci()
{
    printf("%i\n", isUnique("jesai    pa"));
    printf("%i\n", isUnique2("jesaipa"));
    printf("%i\n", permutation("qwer", "rewq"));
    char test[] = "test test test    ";
    printf("%s\n", URLify(test, 14));
    printf("%i\n", permPal("tsseeeetthhh nnnnnnnnt"));
    char newStr[52];
    printf("Result %s\n", compression("tsseeeetthhh nnnnnnnnt", newStr));
    printf("%i\n", edit("pl","pale" ));
    printf("%i\n", checkRotation("xijijiy","iyxijij" ));

    python_list testList;
    python_list *ptrTestList = &testList;
    initList(ptrTestList);
    char * test1 = "ok";
    add(ptrTestList, test1);
    char * test2 = "now";
    add(ptrTestList, test2);
    char * test3 = "how";
    add(ptrTestList, test3);
    char * test4 = "is";
    add(ptrTestList, test4);
    add(ptrTestList, "it");
    add(ptrTestList, "possible");
    add(ptrTestList, "?");
    int pos;
    pos = 0;
    while (pos < testList.length - 1)
    {
        //printf("%s", testList.list[pos] );
        pos++;
    }
}