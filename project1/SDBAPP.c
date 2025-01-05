#include <stdio.h>
#include "SDB.c"

uint8 g=10;

void SDB_Action();

//all the text is moved to the right a little for more readability.
void SDB_APP()
{
    while (g != 0)
    {
    printf("\n\n\t\t\t------<: Options :>------\n\t\t1.To add entry , enter 1 . ");
    printf("\n\t\t2.To get used size in database , enter 2 .");
    printf("\n\t\t3.To read student data , enter 3.");
    printf("\n\t\t4.To get the list of the student ID , enter 4.");
    printf("\n\t\t5.To check is ID existed , enter 5.");
    printf("\n\t\t6.To delete student data , enter 6.");
    printf("\n\t\t7.To check is database full , enter 7.");
    printf("\n\t\t8.To exite enter 0.");
    printf("\n\n\t\t\tChoice : ");
        SDB_Action();
    }
    
}

//in the return value functions i add some text before return value for readability.
//its added to all return value functions.
void SDB_Action()
{
    uint32 d;
    uint8 f;
    uint32 arr2[7];
    scanf("%d",&g);
    switch (g)
    {
    case 1:
        printf(" (%d)",SDB_AddEntry());
        break;
    case 2:
        printf("\n\t\tthe number of students is : %i.",SDB_GetUsedSize());
        break;
    case 3:
        printf("\n\t\tenter the ID : ");
        scanf("%d",&d);
        SDB_ReadEntry(d);
        break;
    case 4:
        printf("\n\t\tenter the number of student's IDs : ");
        scanf("%d",&f);
        printf(" (%d)",SDB_GetList(&f,arr2));
        break;
    case 5:
        printf("\n\t\tenter the ID : ");
        scanf("%d",&d);
        printf(" (%d)",SDB_IsIdExist(d));
        break;
    case 6:
        printf("\n\t\tenter the ID : ");
        scanf("%d",&d);
        printf(" (%d)",SDB_DeletEntry(d));
        break;
    case 7:
        printf(" (%i)",SDB_IsFull());
        break;
    case 8:
        
        break;
    
    default:
        printf("\n\t\tinvalid input.");
        break;
    }
}