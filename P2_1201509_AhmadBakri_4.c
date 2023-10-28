#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 250 // The size of all arrays in this project

                                      /************* Ahmad Bakri 1201509 :) *************/

typedef struct AVLnode *Tree_AVL; // Define a typedef to make it easier to write
// struct that every node in the tree have the following data
typedef struct AVLnode{
    char CourseName[SIZE];
    int CourseHours;
    char CourseCode[SIZE];
    char DepartmentCourse[SIZE];
    char topics[SIZE];
    struct AVLnode*AVL_TLeft;
    struct AVLnode*AVL_TRight;
    int Height;
} AVLnode;
// we define all function to make function prototype successfully
Tree_AVL Insertion(Tree_AVL t,char [],int,char[],char [],char[]);
Tree_AVL RotateToLeftSingle(Tree_AVL );
Tree_AVL RotateToRightSingle(Tree_AVL );
Tree_AVL RotateToLeftDouble(Tree_AVL );
Tree_AVL RotateToRightDouble(Tree_AVL );
Tree_AVL FindingByCode( char [], Tree_AVL  );
Tree_AVL DeleteByCode(Tree_AVL, char []);
Tree_AVL MinimumValue(Tree_AVL );
Tree_AVL deleteByDep(Tree_AVL T,char Dep[]);
Tree_AVL DeleteForSpecific (Tree_AVL T);
Tree_AVL DeleteByGivingLetter(Tree_AVL,char );
void InOrderPrinting(Tree_AVL );
void printinAlpabeticalOrder(Tree_AVL );
void FindingDepartmentCourse( char [],Tree_AVL );
void FilePrint(FILE *fileWriter,Tree_AVL );
int HeightForTree(Tree_AVL );
int Maximimum (int, int );
int BalanceOfAvlTree(Tree_AVL );
int Height(Tree_AVL );
int MAX(int, int );

int main()
{
    struct AVLnode*Root=NULL;

    printf("Choose One Of The Following:\n\n");
    printf("{1}Read the file courses.txt file and create the tree:\n");
    printf("{2}Insert a new course from the user with all its associated data:\n");
    printf("{3}Find a course and support updating of its information.:\n");
    printf("{4}List courses in lexicographic order with their associated information (credit hours, IDs, and topics):\n");
    printf("{5}List all topics associated with a given course:\n");
    printf("{6}List all courses in lexicographic order that belong to the same department:\n");
    printf("{7}Delete a course:\n");
    printf("{8}Delete all courses that start with a specific letter:\n");
    printf("{9}Delete all courses belong to a given department:\n");
    printf("{10}Save all words in file offered_courses.txt:\n");
    printf("{11}EXIT:\n\n");

    int U;
    printf("Enter the number you want from 1 to 11\n");
    scanf("%d",&U);

    for (;U!=11;)
    {
        if (U==1)
        {
            char storingString[SIZE];
             char *NameC;
              char *HoursString;
               char *Code;
                char *Dep;
                 char *Topics;
                  int Hours;

            FILE *courses;
            courses=fopen("courses.txt","r");// to open the file and read the information

            if (courses==NULL)
            {
                printf("the tree is empty:(try again\n");// if the file is empty and does not has any data
            }

            while(fgets(storingString,SIZE,courses))
            {

                NameC= strtok(storingString,":");// split the string in the : and take the word or int or char before:
                printf("[%s]\t",NameC);

                HoursString=strtok(NULL,"#");// split the string in the # and take the word or int or char before#
                Hours=atoi(HoursString);//convert string to int
                printf("[%d]\t",Hours);

                Code= strtok(NULL,"#");
                printf("[%s]\t",Code);

                Dep= strtok(NULL,"/");// split the string in the / and take the word or int or char before/
                printf("[%s]\t",Dep);

                Topics= strtok(NULL,"\n");// Split at the end of the line of file
                printf("[%s]\t",Topics);

                printf("\n\n");
                Root=Insertion(Root,NameC,Hours,Code,Dep,Topics);//This function insert the nodes and Arrange them according to the definition of the AVL Tree
            }
            printf("<><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
            printf("<><><><><><><><><><><><><><><><><><><><><><><><><><>\n\n");
            printf("Enter the number you want from 1 to 11\n");
            scanf("%d",&U);
        }

        else if (U==2)
        {
            char nameOfCourse[SIZE],Key[SIZE],Dep[SIZE],Type[SIZE];
            int Hour;

            printf("Enter the Name of course:\n");
            scanf(" %[^\n]s",&nameOfCourse);

            printf("Enter the Hours of the course:\n");
            scanf("%d",&Hour);

            printf("Enter the key**code**of the course:\n");
            scanf(" %[^\n]s",&Key);

            printf("Enter the department or college that the is in:\n");
            scanf(" %[^\n]s",&Dep);

            printf("Enter Types**Topics** you want:\n");
            scanf(" %[^\n]s",&Type);

            Root=Insertion(Root,nameOfCourse,Hour,Key,Dep,Type);//Create a node and insert it to the tree
            InOrderPrinting(Root);// InOrder Sorting from left to right

            printf("<><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
            printf("<><><><><><><><><><><><><><><><><><><><><><><><><><>\n\n");
            printf("Enter the number you want from 1 to 11\n");
            scanf("%d",&U);
        }

        else if (U==3)
        {
            //find and update
            char CODE[SIZE];Tree_AVL W;

            printf("Enter the Code to find Then Update:\n");
            scanf(" %[^\n]s",&CODE);

            W=FindingByCode(CODE,Root);
            printf("Enter the data you want to update\n");

            char N[SIZE],code[SIZE],D[SIZE],T[SIZE];
            int HourS;

            printf("Enter the course Name:\n");
            scanf("%s",&N);
            strcpy(W->CourseName,N);//Copy the String in N to CourseName

            printf("Enter the Hours:\n");
            scanf("%d",&HourS);
            W->CourseHours=HourS;//Copy the Hours in HourS to CourseHours

            printf("Enter Department\n");
            scanf("%s",&D);
            strcpy(W->DepartmentCourse,D);//Copy the String in D to DepartmentCourse

            printf("Enter The topics you want:\n");
            scanf("%s",&T);
            strcpy(W->topics,T);//Copy the String in T to topics

            InOrderPrinting(Root);// InOrder Sorting from left to right

            printf("<><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
            printf("<><><><><><><><><><><><><><><><><><><><><><><><><><>\n\n");

            printf("Enter the number you want from 1 to 11\n");
            scanf("%d",&U);

        }

        else if (U==4)
        {
            printinAlpabeticalOrder(Root); // InOrder Sorting from left to right

            printf("<><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
            printf("<><><><><><><><><><><><><><><><><><><><><><><><><><>\n\n");

            printf("Enter the number you want from 1 to 11\n");
            scanf("%d",&U);
        }

        else if (U==5)
        {
            char C[SIZE];Tree_AVL M;

            printf("Enter the Code:\n");
            scanf(" %[^\n]s",&C);

            M=FindingByCode(C,Root);
            printf("the Course Code is [%s] have the following topics [%s]\n",M->CourseCode,M->topics);

            printf("<><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
            printf("<><><><><><><><><><><><><><><><><><><><><><><><><><>\n\n");

            printf("Enter the number you want from 1 to 11\n");
            scanf("%d",&U);

        }

        else if (U==6)
        {
            char D[SIZE];Tree_AVL h;

            printf("Enter The Department you Want:\n");
            scanf(" %[^\n]s",&D);

            FindingDepartmentCourse(D,Root); // Give the name of the department you sent

            printf("<><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
            printf("<><><><><><><><><><><><><><><><><><><><><><><><><><>\n\n");

            printf("Enter the number you want from 1 to 11\n");
            scanf("%d",&U);
        }

        else if (U==7)
        {
            char H[SIZE];

            printf("Enter the Code To Delete:\n");
            scanf(" %[^\n]s",&H);

            DeleteByCode(Root,H);// Delete the node that has the node you sent
            printinAlpabeticalOrder(Root);// InOrder Sorting from left to right

            printf("<><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
            printf("<><><><><><><><><><><><><><><><><><><><><><><><><><>\n\n");

            printf("Enter the number you want from 1 to 11\n");
            scanf("%d",&U);
        }

        else if (U==8)
        {
            char Q;

            printf("Enter letter For Delete :\n");
            scanf(" %c",&Q);

            DeleteByGivingLetter(Root,Q);// function that delete the node begin with letter you sent
            DeleteForSpecific (Root);

            printinAlpabeticalOrder(Root);// InOrder Sorting from left to right

            printf("<><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
            printf("<><><><><><><><><><><><><><><><><><><><><><><><><><>\n\n");

            printf("Enter the number you want from 1 to 11\n");
            scanf("%d",&U);

        }
        else if (U==9)
        {
            char B[SIZE];

            printf("Enter Department To delete:\n");
            scanf(" %s",&B);

            deleteByDep(Root,B); // Function that delete the node the has the same dep sent
            printinAlpabeticalOrder(Root);// InOrder Sorting from left to right

            printf("<><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
            printf("<><><><><><><><><><><><><><><><><><><><><><><><><><>\n\n");

            printf("Enter the number you want from 1 to 11\n");
            scanf("%d",&U);
        }
        else if (U==10)
        {
            FILE*WriterFile;

            WriterFile= fopen("offered_courses.txt","w");
            FilePrint(WriterFile,Root);

            printf("<><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
            printf("<><><><><><><><><><><><><><><><><><><><><><><><><><>\n\n");

            printf("Enter the number you want from 1 to 11\n");
            scanf("%d",&U);

        }
        else if(U==11){
            break;//Exit
        }
    }
    return 0;
}
//This function is to insert every node in the tree then check the balance and rotation of every node in tree and if there are no tree this function will create a perfect tree
Tree_AVL Insertion(Tree_AVL R,char CourseName[SIZE],int CourseHours,char CourseCode[SIZE],char DepartmentCourse[SIZE],char topics[SIZE]){

    // if the root of the tree points to NULL then make the root
    if(R==NULL)
    {
        R=malloc(sizeof (struct AVLnode));
        strcpy(R->CourseName,CourseName);
        strcpy(R->CourseCode,CourseCode);
        strcpy(R->DepartmentCourse,DepartmentCourse);
        strcpy(R->topics,topics);

        R->CourseHours=CourseHours;
        R->Height=0;
        R->AVL_TLeft= R->AVL_TRight=NULL;
    }

    else if(strcmp(CourseCode, R->CourseCode)<0)
    {
        R->AVL_TLeft=Insertion(R->AVL_TLeft,CourseName, CourseHours,CourseCode,DepartmentCourse,topics);
        // check the height and balance of the tree in every node from the left side
        if(HeightForTree(R->AVL_TLeft) - HeightForTree(R->AVL_TRight) >= 2)
        {
            if(strcmp(CourseCode, R->AVL_TLeft->CourseCode)<0)
                R=RotateToRightSingle(R);
            else
                R=RotateToLeftDouble(R);
        }
    }

    else if(strcmp(CourseCode, R->CourseCode)>0)
    {
        R->AVL_TRight = Insertion(R->AVL_TRight, CourseName, CourseHours,CourseCode,DepartmentCourse,topics);
        // check the height and balance of the tree in every node from the right side
        if(HeightForTree(R->AVL_TRight) - HeightForTree(R->AVL_TLeft) >= 2)
        {
            if(strcmp(CourseCode, R->AVL_TRight->CourseCode)>0)
                R=RotateToLeftSingle(R);
            else
                R=RotateToRightDouble(R);
        }
    }
    R->Height = 1 + Maximimum(HeightForTree(R->AVL_TRight), HeightForTree(R->AVL_TLeft));

    return R;
}
//This function to check the height of the tree and return a height of the tree
int HeightForTree (Tree_AVL R){
    char*S=NULL;

    if(R==S)
        return -1;
    else
        return R->Height;
}
//Compare two integers then return the biggest one
int Maximimum (int A, int B){
    if(A>B)
        return A;
    else
        return B;
}
// This function is to check the rotate of the tree and make the tree rotate if has zag or zig rotation or single rotate from the left side
Tree_AVL RotateToLeftSingle(Tree_AVL R){

    Tree_AVL S;
    S = R->AVL_TRight;
    R->AVL_TRight  = S->AVL_TLeft;
    S->AVL_TLeft = R;

    R->Height = 1 + Maximimum(HeightForTree(R->AVL_TLeft), HeightForTree(R->AVL_TRight));
    S->Height = 1 + Maximimum(HeightForTree(R), HeightForTree(S->AVL_TRight));

    return S;
}
// This function is to check the rotate of the tree and make the tree rotate if has zag or zig rotation or single rotate from the right side
Tree_AVL RotateToRightSingle(Tree_AVL R){

    Tree_AVL S;
    S= R->AVL_TLeft;
    R->AVL_TLeft  = S->AVL_TRight;
    S->AVL_TRight = R;

    R->Height = 1 + Maximimum(HeightForTree(R->AVL_TRight), HeightForTree(R->AVL_TLeft));
    S->Height = 1 + Maximimum(HeightForTree(R), HeightForTree(S->AVL_TLeft));

    return S;
}
// This function is to check the rotate of the tree and make the tree rotate if has zag-zag rotation or double rotate from the left side
Tree_AVL RotateToLeftDouble(Tree_AVL R){
    R->AVL_TLeft  = RotateToLeftSingle(R->AVL_TLeft);
    return RotateToRightSingle(R);
}
// This function is to check the rotate of the tree and make the tree rotate if has zag-zag rotation or double rotate from the right side
Tree_AVL RotateToRightDouble(Tree_AVL R){
    R->AVL_TRight  = RotateToRightSingle(R->AVL_TRight);
    return RotateToLeftSingle(R);
}

// InOrder Sorting from left Then root then right
void InOrderPrinting(Tree_AVL t)
{
    char*S=NULL;
    if(t!=S){
        InOrderPrinting(t->AVL_TLeft);
        printf("[%s]\t[%s]\t[%d]\t[%s]\t[%s]\n\n",t->CourseCode,t->CourseName,t->CourseHours,t->DepartmentCourse,t->topics);
        InOrderPrinting(t->AVL_TRight);
    }
}
//This function is to find all courses by giving Code to the function
Tree_AVL FindingByCode( char courseCode[SIZE], Tree_AVL TR )
{
    char*S=NULL;

    if( TR == S )
        return S;
    if( strcmp(courseCode, TR->CourseCode)<0)
        return FindingByCode( courseCode, TR->AVL_TLeft );
    else if( strcmp(courseCode, TR->CourseCode)>0)
        return FindingByCode( courseCode, TR->AVL_TRight );
    else
        return TR;
}
// InOrder Sorting from left Then root then right
void printinAlpabeticalOrder(Tree_AVL t)
{
    InOrderPrinting(t);
}
//This function is to find all courses by giving department to the function
void FindingDepartmentCourse( char Department[SIZE],Tree_AVL TR)
{
    char*S=NULL;

    if( TR == S )
        return NULL;

    FindingDepartmentCourse(Department, TR->AVL_TLeft );
    if (strcmp(TR->DepartmentCourse,Department)==0)
    {
        printf("%s\n",TR->CourseName);
    }
    FindingDepartmentCourse(Department, TR->AVL_TRight );
}
//This function is to delete the node By givinf the course code to the function and this function check balance and all cases of rotate and balance
Tree_AVL DeleteByCode(Tree_AVL RootOfTree, char CourseCode[SIZE])
{
    if (RootOfTree == NULL)
        return RootOfTree;

    if ( strcmp(CourseCode,RootOfTree->CourseCode) ==-1)
        RootOfTree->AVL_TLeft = DeleteByCode(RootOfTree->AVL_TLeft,CourseCode);

    else if( strcmp(CourseCode,RootOfTree->CourseCode) ==1 )
        RootOfTree->AVL_TRight = DeleteByCode(RootOfTree->AVL_TRight, CourseCode);

    else
    {
        if( (RootOfTree->AVL_TLeft == NULL) || (RootOfTree->AVL_TRight == NULL) )
        {
            Tree_AVL temp = RootOfTree->AVL_TLeft ? RootOfTree->AVL_TLeft : RootOfTree->AVL_TRight;
            if (temp == NULL)
            {
                temp = RootOfTree;
                RootOfTree = NULL;
            }
            else
                *RootOfTree = *temp;
                 free(temp);
        }
        else
        {
            Tree_AVL temp = MinimumValue(RootOfTree->AVL_TRight);
            strcpy(RootOfTree->CourseCode, temp->CourseCode);
            RootOfTree->CourseHours = temp->CourseHours;
            strcpy(RootOfTree->CourseName, temp->CourseName);
            strcpy(RootOfTree->DepartmentCourse, temp->DepartmentCourse);
            strcpy(RootOfTree->topics, temp->topics);

            RootOfTree->AVL_TRight = DeleteByCode(RootOfTree->AVL_TRight, temp->CourseCode);
        }
        if (RootOfTree == NULL)
            return RootOfTree;
        RootOfTree->Height=1+Maximimum(Height(RootOfTree->AVL_TLeft),Height(RootOfTree->AVL_TRight));

        int balance = BalanceOfAvlTree(RootOfTree);
        if (balance > 1 && BalanceOfAvlTree(RootOfTree->AVL_TLeft) >= 0)
            return RotateToRightSingle(RootOfTree);

        if (balance > 1 && BalanceOfAvlTree(RootOfTree->AVL_TLeft) < 0){
            RootOfTree->AVL_TLeft = RotateToLeftSingle(RootOfTree->AVL_TLeft);
            return RotateToRightSingle(RootOfTree);
        }

        if (balance < -1 && BalanceOfAvlTree(RootOfTree->AVL_TRight) <= 0)
            return RotateToLeftSingle(RootOfTree);

        if (balance < -1 && BalanceOfAvlTree(RootOfTree->AVL_TRight) > 0)
        {
            RootOfTree->AVL_TRight = RotateToRightSingle(RootOfTree->AVL_TRight);
            return RotateToLeftSingle(RootOfTree);
        }
        return RootOfTree;
    }
}
//This function is to check the balance of the tree and return int and for AVL tree the perfect balance is 1 or 0 or -1
int BalanceOfAvlTree(Tree_AVL B)
{
    char*S=NULL;

    if (B == S)
        return 0;
    return Height(B->AVL_TLeft) - Height(B->AVL_TRight);
}
//this function is to return the height of the tree
int Height(Tree_AVL H)
{
    char*S=NULL;

    if (H == S)
        return 0;
    return H->Height;
}
//This function is to compare between two integers and return the biggest one
int MAX(int A, int B)
{
    return (A > B)? A : B;
}
//This function is to find the Minimum Value in the tree
Tree_AVL MinimumValue(Tree_AVL N)
{
    char*S=NULL;

    Tree_AVL temp = N;
    while (temp->AVL_TLeft != S)
        temp = temp->AVL_TLeft;
    return temp;
}
//This function is to delete a node that has the same department as we sent to it
Tree_AVL deleteByDep(Tree_AVL TR,char Dep[SIZE]){

    char*S=NULL;

    if( TR != S ){
           if(TR!=S){

    if(TR->AVL_TLeft==S)
    TR->AVL_TLeft=deleteByDep(TR->AVL_TLeft,Dep);//check all nodes of the left side of the tree
        }

    if (strcmp(TR->DepartmentCourse,Dep)==0){
        DeleteByCode(TR,TR->CourseCode);
    }

    if (TR!=S){

    if(TR->AVL_TRight!=S)
    TR->AVL_TRight=deleteByDep(TR->AVL_TRight,Dep);//check all nodes of the right side of the tree
    }
}
    return TR;
}
// This function is to print the information in the tree on a file
void FilePrint(FILE *WriterFile,Tree_AVL T)
{
    char*S=NULL;

    if (T!=S)
    {
        FilePrint(WriterFile,T->AVL_TLeft);// To check all the node at the left in tree
        fprintf(WriterFile,"%s:%d#%s#%s/%s\n",T->CourseName,T->CourseHours,T->CourseCode,T->DepartmentCourse,T->topics);
        FilePrint(WriterFile,T->AVL_TRight);// To check all the node at the right in tree
    }

}
//Define a Global tree to make work easier
Tree_AVL GlobelAVL;
//This function is to compare if the character i passed to the function is equal or not to the first letter in each Course Code
Tree_AVL DeleteByGivingLetter(Tree_AVL TR,char O)
{
    Tree_AVL R=TR;
    char*S=NULL;
    if( TR != S )
    {
        if (O>R->CourseCode[0])
        {
            DeleteByGivingLetter(R->AVL_TRight,O);
        }
        if(O<R->CourseCode[0])
        {
            DeleteByGivingLetter(R->AVL_TLeft,O);
        }
        if(O==R->CourseCode[0])
        {
            DeleteByGivingLetter(R->AVL_TLeft,O);
            GlobelAVL=Insertion(GlobelAVL,R->CourseName,R->CourseHours,R->CourseCode,R->DepartmentCourse,R->topics);
            DeleteByGivingLetter(R->AVL_TRight,O);
        }
    }
    return R;
}
//This function is to delete the node that has a letter with the same the first letter in the course code with the Global tree to make the work easier
Tree_AVL DeleteForSpecific(Tree_AVL P)
{
    char*S=NULL;

    for(;GlobelAVL!=NULL;)
    {
        P=DeleteByCode(P,GlobelAVL->CourseCode);
        GlobelAVL=DeleteByCode(GlobelAVL,GlobelAVL->CourseCode);
    }
    return P;
}






