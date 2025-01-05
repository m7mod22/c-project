#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SDB.h"
#include "STD.h"

//the data base.
student arr[9];
/*
this array was subbosed to be arr[7], but i ran into a problem that
when i enterd the 8th student the number of students became 9 for
unknown memory issue ,so i made it arr[8],the i ran into another problem
that when i filled the school with students and deleted the last ID and 
used the SDB_GetList it appears the 8th student ID remained for
unknown memory issue,so i changed it to arr[9]   :) 
*/
uint32 x = 0;

//the database will have maximum 8 students. 
bool SDB_IsFull()
{
    if(x >= 8)
    {
        printf("\n\t\tThe school is full.");
        return true;
    }else{
        printf("\n\t\tThe school is not full yet.");
        return false;
    }
}

uint8 SDB_GetUsedSize()
{
    return x;
}

//this function cant be used after 8 students enterd.
//you cant use an ID that you used before.  
bool SDB_AddEntry()
{
    uint16 i,z = x;
    if(x == 8)
    {
        printf("\n\t\tthe school is full.");
        return false;
    }
    printf("\n");
    printf("\tenter the following student info .\n\tenter the student ID : ");
    scanf("%d",&(arr[x]).Student_ID);
    for ( i = 0; i < x; i++)
    {
        if ((arr[x]).Student_ID == (arr[z-1]).Student_ID)
        {
            printf("\n\tthe ID is already used.");
            return false;
        }
        z--;
    }
    printf("\tenter the student year : ");
    scanf("%d",&(arr[x]).Student_year);
    printf("\tenter Course1 ID : ");
    scanf("%d",&(arr[x]).Course1_ID);
    printf("\tenter Course1 grade : ");
    scanf("%d",&(arr[x]).Course1_grade);
    printf("\tenter Course2 ID : ");
    scanf("%d",&(arr[x]).Course2_ID);
    printf("\tenter Course2 grade : ");
    scanf("%d",&(arr[x]).Course2_grade);
    printf("\tenter Course3 ID : ");
    scanf("%d",&(arr[x]).Course3_ID);
    printf("\tenter Course3 grade : ");
    scanf("%d",&(arr[x]).Course3_grade);
    if ((arr[x]).Student_ID < 1 || (arr[x]).Student_year<4 ||(arr[x]).Course1_ID < 1||(arr[x]).Course1_grade < 1 ||(arr[x]).Course2_ID < 1 ||(arr[x]).Course2_grade < 1 ||(arr[x]).Course3_ID < 1 ||(arr[x]).Course3_grade < 1)
    {
        printf("invalid input.");
        return false;
    }
    x++;
    printf("\n\tstudent added.");
    return true;
}


//this function checks first if the ID existed and if it does it will delete the student.
//i changed the void function to bool to check if the ID existed or not.
bool SDB_DeletEntry(uint32 id)
{
    uint32 c;
    for (c = 0; c < x + 1; c++)
    {
        if ((arr[c]).Student_ID == id)
        {
            int32 i , j;
            for ( i = 0; i < x + 1; i++)
            {
                if ((arr[i]).Student_ID == id)
                {
                    while (i<8)
                    {
                        (arr[i]).Student_ID = (arr[i+1]).Student_ID;
                        (arr[i]).Student_year = (arr[i+1]).Student_year;
                        (arr[i]).Course1_ID = (arr[i+1]).Course1_ID;
                        (arr[i]).Course1_grade = (arr[i+1]).Course1_grade;
                        (arr[i]).Course2_ID = (arr[i+1]).Course2_ID;
                        (arr[i]).Course2_grade = (arr[i+1]).Course2_grade;
                        (arr[i]).Course3_ID = (arr[i+1]).Course3_ID;
                        (arr[i]).Course3_grade = (arr[i+1]).Course3_grade;
                        i++;
                    }
                    x--;
                }
            }
            printf("\t\tstudent removed.");
            return true;
        }
    }
    printf("\t\tthe student doesent exist already.");
    return false;
}

bool SDB_ReadEntry(uint32 id)
{
    uint32 i;
    for ( i = 0; i < x + 1; i++)
    {
        if ((arr[i]).Student_ID == id)
        {
            printf("\tthe student ID : %d\n",(arr[i]).Student_ID);
            printf("\tthe student year : %d\n",(arr[i]).Student_year);
            printf("\tCourse1 ID : %d\n",(arr[i]).Course1_ID);
            printf("\tCourse1 grade : %d\n",(arr[i]).Course1_grade);
            printf("\tCourse2 ID : %d\n",(arr[i]).Course2_ID);
            printf("\tCourse2 grade : %d\n",(arr[i]).Course2_grade);
            printf("\tCourse3 ID : %d\n",(arr[i]).Course3_ID);
            printf("\tCourse3 grade : %d\n",(arr[i]).Course3_grade);
            return 1;
        }
        
    }
    return 0;
}

bool SDB_GetList(uint8* count,uint32* list)
{
    if (*count > 8)
    {
        printf("\t\tthe school only contains maximum 8 IDs.");
        return false;
    }else if (*count < 1)
    {
        printf("\t\tinvalid number of IDs.");
        return false;
    }
    
    uint32 i,j;
    for ( i = 0; i < *count; i++)
    {
        list[i] = (arr[i]).Student_ID;
    }
    for ( j = 0; j < *count; j++)
    {
        printf("\t\tID %d: %d\n",(j+1),list[j]);
    }
    return true;
}

//in the return value functions i add some text before return value for readability.
bool SDB_IsIdExist(uint32 id)
{
    uint32 i;
    for (i = 0; i < x + 1; i++)
    {
        if ((arr[i]).Student_ID == id)
        {
            printf("\t\tThe ID exists.");
            return 1;
        }
    }
    printf("\t\tthe ID doesent exist.");
    return 0;
}


