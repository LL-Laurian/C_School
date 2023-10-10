/*
 *  CSC A48 - Winter 2023 - Assignment 1 starter
 * 
 *  (c) 2020-23 Francisco Estrada
 *  - No part of this code may be reproduced without written authorization
 * 
 * This is the file where you will be doing most of your work. The
 * functionality you must provide for part 1 of the assignment is described
 * in the handout. Given in detail in the comments at the head of each
 * function below. 
 * 
 * Plan your work carefully, review the notes for Unit 3, and work carefully
 * to complete the functions in this file. You can bring 
 * questions to your TAs or instructors during office hours. Please
 * remember:
 * 
 * - You should not share any part of your solution in any form
 * - You should not post any assignment code on Piazza
 * - You should definitely *help* other understand any ideas and
 *   concepts regarding linked lists that you have already mastered,
 *   but being careful not to give away parts of the solution, or
 *   descriptions of how to implement functions below.
 * - If you are not sure whether you can or can not discuss some
 *   particular aspect of the work to be done, remember it's always 
 *   safe to talk with your TAs.
 * - Obtaining external 'help' including being given code by an
 *   external party, or being tutored on how to solve
 *   the assignment constitutes an academic offense.
 * 
 * All tasks to be completed by you are clearly labeled with a
 * ***** TO DO ****** comment block, which also gives you details
 * about what you have to implement. Look carefully and make sure
 * you don't miss a thing!
 * 
 * NOTE: This file contains no main() function! you can not compile
 * it on its own to create an executable. It's meant to be used
 * together with Part1_driver.c - be sure to read that file carefully
 * to understand how to use the tests there - Any additional tests
 * you want to run on the code below should be added to Part1_driver.c
 * 
 * Before you even get starter implementing, please complete the
 * student identification section below, and check that you are aware
 * of the policy on academic honesty and plagiarism.
 */

/* Student identification:
 * 
 * Student Name (Last name, First name):LI, LANGXIN
 * Student Number:1008831374
 * UTORid:lilangxi
 * Your instructor's name is:Paco Estrada
 */

/* Academic Integrity Statement:
 * 
 * I hereby certify that the work contained in this file is my own, and
 * that I have not received any parts of my solution from other sources
 * including my fellow students, external tutoring services, the internet,
 * or algorithm implementations found online.
 * 
 * Sign here with your name:LANGXIN LI
 *
 *  
 */

#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STR_LEN 1024

/* Compound data type declarations */
/***************************************************************************/
/******                         TO DO                               ********/
/****** In the space below, complete the definitions of the compound *******/
/****** data types that will be needed to implement the movie review *******/
/****** linked list. This includes the MovieReview type, and the     *******/
/****** ReviewNode. Details about the contents of these can be       *******/
/****** found in the assignment handout. Read them carefully!        *******/
/******                                                              *******/
/****** AFTER completing the basic linked list, complete the CDT     *******/
/****** required to implement a list for the movie's cast.           *******/
/***************************************************************************/

typedef struct castList_struct
{   char name[MAX_STR_LEN];
    float salary;
    struct castList_struct *next;

    
} CastList;

typedef struct movieReview_struct
{   char movie_title[MAX_STR_LEN];
    char movie_studio[MAX_STR_LEN];
    int year;
    float BO_total;
    int score;
    CastList *cast;

    
} MovieReview;

typedef struct reviewNode_struct
{   MovieReview review;
    struct reviewNode_struct *next;

    
} ReviewNode;

ReviewNode *newMovieReviewNode()
{
    /*
     * This function allocates an empty ReviewNode, and initializes the
     * contents of the MovieReview for this node to reasonable (uninitialized) values.
     * The fields in the MovieReview should be set to:
     *  movie_title=""
     *  movie_studio=""
     *  year = -1
     *  BO_total = -1
     *  score = -1
     *  scoreList = NULL;
     * 
     * The *next pointer for the new node MUST be set to NULL
     * 
     * The function must return a pointer to the newly allocated and initialized
     * node. If something goes wrong, the function returns NULL
     */
 
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    ReviewNode *new_node=NULL;

    new_node = (ReviewNode *) calloc(1, sizeof(ReviewNode));

    if (new_node ==NULL){
        return NULL;
    }
    for(int i=0; i<MAX_STR_LEN; i++){
        new_node->review.movie_title[i] = '\0';
        new_node->review.movie_studio[i] = '\0';
    }
    new_node->review.year=-1;
    new_node->review.BO_total=-1;
    new_node->review.score=-1;
    new_node->review.cast=NULL;
    new_node->next=NULL;

    return(new_node);    
}

//int same_string(char title[MAX_STR_LEN],char name[MAX_STR_LEN]){
    //for (int i=0; name[i]!='\0'; i++){
        //if (title[i]!=name[i]){
            //return 0;
        //}
    //}
   // return 1;
//}

ReviewNode *findMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, ReviewNode *head)
{
    /*
     * This function searches through the linked list for a review that matches the input query. 
     * The movie review must match the title, studio, and year provided in the 
     * parameters for this function.
     * 
     * If a review matching the query is found, this function returns the address of the node that
     * contains that review. 
     * 
     * If no such review is found, this function returns NULL
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    
    ReviewNode *p=NULL;

    if (head == NULL){
        return head;
    }
    p=head;

    while(p!=NULL){
        if (strcmp(p->review.movie_title,title)==0){
            if (strcmp(p->review.movie_studio, studio)==0){
                if (p->review.year==year){
                    return p;
                }
            }
        }
        p=p->next;
    }
    return NULL;
}

ReviewNode *insertMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, float BO_total, int score, ReviewNode *head)
{
    /*
     * This function inserts a new movie review into the linked list.
     * 
     * The function takes as input parameters the data neede to fill-in the review,
     * as well as apointer to the current head of the linked list.
     * 
     * If head==NULL, then the list is still empty.
     * 
     * The function inserts the new movie review *AT THE HEAD* of the linked list,
     * and returns the pointer to the new head node.
     * 
     * The function MUST check that the movie is not already in the list before
     * inserting (there should be no duplicate entries). If a movie with matching
     * title, studio, and year is already in the list, nothing is inserted and the
     * function returns the current list head.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    ReviewNode *p=NULL;
    p=newMovieReviewNode();

    int i;
    strcpy(p->review.movie_title,title);
    //for (i=0;title[i]!='\0';i++){
        //p->review.movie_title[i]=title[i];
    //}
    strcpy(p->review.movie_studio,studio);
    //for (i=0;studio[i]!='\0';i++){
    //    p->review.movie_studio[i]=studio[i];
    //}
    p->review.year=year;
    p->review.BO_total=BO_total;
    p->review.score=score;

    if (head==NULL){
        p->next=NULL;
        return p;
    }

    if (findMovieReview(title,studio,year,head)==NULL){
        p->next=head;
        return p;
    }

    else{
        printf("The movie is already in the Database\n");
        return head;
    }

}

int countReviews(ReviewNode *head)
{
  /*
   * This function returns the number of reviews. 
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/  

    int count=0;
    ReviewNode *p=head;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
}

void updateMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, float BO_total, int score, ReviewNode *head)
{
    /*
     * This function looks for a review matching the input query [title, studio, year].
     * If such a review is found, then the function updates the Box-office total, and the score.
     * If no such review is found, the function prints out 
     * "Sorry, no such movie exists in the database"
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    ReviewNode *p=findMovieReview(title,studio,year,head);
    if(p==NULL){
        printf("Sorry, no such movie exists in the database\n");
    }
    else{
        p->review.BO_total=BO_total;
        p->review.score=score;
    }
}

ReviewNode *deleteMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN],int year, ReviewNode *head)
{
    /*
     * This function removes a review matching the input query from the database. If no such review can
     * be found, it does nothing.
     * 
     * The function returns a pointer to the head of the linked list (which may have changed as a result
     * of the deletion process)
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    
     if(findMovieReview(title,studio,year,head)==NULL){
         return head;
     }

     ReviewNode *p=findMovieReview(title,studio,year,head);

     //if p is the head
     if (p==head){
         p=head->next;
         free(head);
         return p;
     }

     // if p is the last one
     ReviewNode *before=head;
     if (p->next==NULL){
        while(before!=p){
            if(before->next==p){
                before->next=NULL;
                free(p);
                break;
            }
            before=before->next;

        }
        return head;
    }

     // if p is in the middle
    while(before!=p) {
        if (before->next == p) {
            before->next = p->next;
            free(p);
            break;
        }
        before = before->next;
    }
    return head;

}

float printMovieReviews(ReviewNode *head)
{
    /*
     * This function prints out all the reviews in the database, one after another.
     * Each field in the review is printed in a separate line, with *no additional text*
     * (that means, the only thing printed is the value of the corresponding field).
     * 
     * Reviews are separated from each other by a line of
     * "*******************"

     * The function also computes and returns the Box-office total, for all the
     * movies that match the query.
     * 
     * See the A1 handout for a sample of the output that should be produced
     * by this function
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
        
    float sum=0;
    int i;
    ReviewNode *p=head;
    while(p!=NULL){
        for(i=0; p->review.movie_title[i]!='\0';i++){
            printf("%c",p->review.movie_title[i]);
        }
        printf("\n");
        for(i=0; p->review.movie_studio[i]!='\0';i++){
            printf("%c",p->review.movie_studio[i]);
        }
        printf("\n");
        printf("%d\n",p->review.year);
        printf("%f\n",p->review.BO_total);
        printf("%d\n",p->review.score);
        printf("*******************\n");
        sum=sum+p->review.BO_total;
        p=p->next;
    }
    return sum;
}

float queryReviewsByStudio(char studio[MAX_STR_LEN], ReviewNode *head)
{
    /*
     * This function looks for reviews whose studio matches the input query.
     * It prints out the contents of all reviews matching the query in exactly
     * the same format used by the printMovieReviews() function above.
     * 
     * Additionally, it computes and returns the Box-office total, for all the
     * movies that match the query.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    int i;
    float total_BO=0;
    ReviewNode *p=head;
    while(p!=NULL){
        if(strcmp(p->review.movie_studio,studio)==0) {
            for (i = 0; p->review.movie_title[i] != '\0'; i++) {
                printf("%c", p->review.movie_title[i]);
            }
            printf("\n");
            for (i = 0; p->review.movie_studio[i] != '\0'; i++) {
                printf("%c", p->review.movie_studio[i]);
            }
            printf("\n");
            printf("%d\n", p->review.year);
            printf("%f\n", p->review.BO_total);
            printf("%d\n", p->review.score);
            printf("*******************\n");
            total_BO=total_BO+p->review.BO_total;
        }
        p=p->next;
    }
    return total_BO;
}

float queryReviewsByScore(int min_score, ReviewNode *head)
{
    /*
     * This function looks for reviews whose score is greater than, or equal to
     * the input 'min_score'.
     * It prints out the contents of all reviews matching the query in exactly
     * the same format used by the printMovieReviews() function above.
     * 
     * Additionally, it computes and returns the Box-office total, for all the
     * movies that match the query.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    int i;
    float total_BO=0;
    ReviewNode *p=head;
    while(p!=NULL){
        if(p->review.score>=min_score) {
            for (i = 0; p->review.movie_title[i] != '\0'; i++) {
                printf("%c", p->review.movie_title[i]);
            }
            printf("\n");
            for (i = 0; p->review.movie_studio[i] != '\0'; i++) {
                printf("%c", p->review.movie_studio[i]);
            }
            printf("\n");
            printf("%d\n", p->review.year);
            printf("%f\n", p->review.BO_total);
            printf("%d\n", p->review.score);
            printf("*******************\n");
            total_BO=total_BO+p->review.BO_total;
        }
        p=p->next;
    }
    return total_BO;
}

ReviewNode *deleteReviewList(ReviewNode *head)
{
  /*
   * This function deletes the movie review database, releasing all the
   * memory allocated to the nodes in the linked list.
   * 
   * Returns a NULL pointer so that the head of the list can be set to NULL
   * after deletion.
   */
      
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    if(head == NULL)return NULL;

    ReviewNode *p;
    ReviewNode *q=head;

    while (q!=NULL)
    {
        p=q->next;
        free(q);
        q=p;
    }
    return NULL;
}

/* CRUNCHY SECTION! Do not work on the functions below until
 * your basic linked list is working properly and is fully tested!
 */ 



/*int index_position(ReviewNode *head, ReviewNode *p){
    int count=1;
    while (head !=NULL){
        if (head==p){
            return count;
        }
        head=head->next;
        count++;
    }
    return -1;
}

ReviewNode *find_before(ReviewNode *head, ReviewNode *p){
    ReviewNode *before;
    if(p==head){
        return head;
    }
    else{
        while (head !=NULL){
            if (head==p){
                return before;
            }
            before=head;
            head=head->next;
        }
    }
}
*/

ReviewNode *bubble_up(ReviewNode *head, int i){
    int count;
    ReviewNode *current=head;
    ReviewNode *later=NULL;
    //ReviewNode *before=NULL;
    MovieReview temp;
    //ReviewNode *new_head=head;

    for(count=1; count<i; count++) {
        later = current->next;
        //int length1 = count_char(current->review.movie_title);
        //int length2 = count_char(later->review.movie_title);
        if (strcmp(current->review.movie_title, later->review.movie_title)>0) {
            temp = current->review;
            current->review = later->review;
            later->review = temp;
        }
        current = later;
    }
    return head;
}
            //swap the first two terms
            //if (current == new_head){
            //    new_head=later;
            //    current->next=later->next;
            //    later->next=current;
            //}else{
                //swap the last two terms
            //    if (index_position(head, later) == countReviews(head)){
            //        before= find_before(head,current);
            /*        before->next=later;
                    current->next=NULL;
                }
                //swap the middle terms
                else{
                    before= find_before(head,current);
                    before->next=later;
                    current->next=later->next;
                    later->next=current;
                }
            }
        }
        current=later;
    }
    return new_head;

}*/


ReviewNode *sortReviewsByTitle(ReviewNode *head)
{
  /*
   * This function sorts the list of movie reviews in ascending order of movie
   * title. If duplicate movie titles exist, the order is arbitrary (i.e. you
   * can choose which one goes first).
   * 
   * However you implement this function, it must return a pointer to the head
   * node of the sorted list.
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/      
    int num= countReviews(head);
    int i;
    for (i=num; i>=2;i--){
        head=bubble_up(head, i);
    }

    return head;
}

int count_cast(CastList *cast){

    int count=0;
    while(cast!=NULL){
        count++;
        cast=cast->next;
    }
    return count;
}

/*int index_cast_position(CastList *head, CastList *p){
    int count=1;
    while (head !=NULL){
        if (head==p){
            return count;
        }
        head=head->next;
        count++;
    }
    return -1;
}

ReviewNode *find_cast_before(CastList *head, CastList *p){
    CastList *before;
    if(p==head){
        return head;
    }
    else{
        while (head !=NULL){
            if (head==p){
                return before;
            }
            before=head;
            head=head->next;
        }
    }
}
*/
CastList *bubble_down(CastList *head, int i) {
    int count;
    CastList *current = head;
    CastList *later = NULL;
    float temp_salary = 0.0;
    char temp_name[MAX_STR_LEN];

    for (count = 1; count < i; count++) {
        later = current->next;
        float salary1 = current->salary;
        float salary2 = later->salary;
        if (salary1 < salary2) {
            temp_salary=current->salary;
            strcpy(temp_name, current->name);
            current->salary = later->salary;
            strcpy(current->name, later->name);
            later->salary= temp_salary;
            strcpy(later->name, temp_name);
        }
        current=current->next;
    }
    return head;
}

void insertCastMember(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, ReviewNode *head, char name[MAX_STR_LEN], float salary)
{
  /*
   * This function inserts the name of a cast member for the given movie into the
   * linked list of cast members. The new cast member must go to the end of the list.
   * 
   * Duplicate names are allowed - this time! 
   * 
   * Notice the function receives the title, studio, and year for the movie, as
   * well as a pointer to the movie DB linked list. The function must find the 
   * correct movie and if such a movie exists, add the cast member's name to its
   * cast list.
   * 
   * If no such movie is found, this function does nothing.
   * 
   * You're free to add helper functions to insert the cast member's name
   * into the cast list.
   */   

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    ReviewNode *p=findMovieReview(title,studio,year,head);
    if (p==NULL){
        return;
    }
    CastList *intro=(CastList *)calloc(1, sizeof(CastList));
    if(intro == NULL){
        return;
    }
    strcpy(intro->name,name);
    intro->salary=salary;
    intro->next=NULL;
    intro->next = p->review.cast;
    p->review.cast=intro;


    int num= count_cast(p->review.cast);
    int i;
    for (i=num; i>=2;i--){
        p->review.cast=bubble_down(p->review.cast, i);
    }


}

void printNames(ReviewNode *movie)
{
    // Prints out names of cast members for this movie
    CastList *p;

    if (movie==NULL||movie->review.cast==NULL) return;

    p=movie->review.cast;
    printf("The cast for this movie are:\n");
    while (p!=NULL){
        printf("Cast Member: %s, Salary: %f\n",p->name,p->salary);
        p=p->next;
    }
}

float movie_earning(MovieReview movie){
    float total_salary=0.0;
    CastList *p = movie.cast;
    while(p!=NULL){
        total_salary=total_salary+p->salary;
        p=p->next;
    }
    return (movie.BO_total-total_salary);
}

float average_earning(ReviewNode *head, char cast_name[MAX_STR_LEN]){
    float total_earning=0.0;;
    int count=0;
    CastList *p;
    ReviewNode *Review_idx = head;

    while (Review_idx!=NULL){
        p=Review_idx->review.cast;
        while(p!=NULL){
            if (strcmp(p->name, cast_name)==0){
                count++;
                total_earning=total_earning+movie_earning(Review_idx->review);
            }
            p=p->next;
        }
        Review_idx=Review_idx->next;

    }
    return (total_earning/count);
}

void whosTheStar(ReviewNode *head)
{
  /*
   *  This function goes through the movie database and determines who is
   * the cast members whose movies have the greatest average earnings.
   *
   * Earnings are defined as the box office total minus the salaries of all
   * cast members involved with the movie.
   *
   *  You're free to implement this function however you like, use any of
   * the code you wrote for other parts of the assignment, and write any
   * helper functions that you need. But:
   *
   *  You can not import extra libraries (no additional #include), and
   * all the implementation here should be your own. 
   *
   *  The function simply prints out:
   *
   *  Name of cast member
   *  Average movie earnings (as a floating point number)
   *
   *  For the cast member whose movies make the greatest average earnings
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    if(head == NULL){
        return;
    }

    CastList *cast_1=NULL;
    char cast_1_name[MAX_STR_LEN];

    float cast1_earning;
    ReviewNode *Review_idx = head;
    CastList *p = Review_idx->review.cast;
    ReviewNode *before_idx=Review_idx;

    while(Review_idx!=NULL){
        if(p == NULL){
            p = Review_idx->review.cast;
            before_idx=Review_idx;
            Review_idx=Review_idx->next;
        }
        else{
            break;
        }
    }
    if(p == NULL){
        return;
    }
    Review_idx=before_idx;

    char h_cast_name[MAX_STR_LEN];
    strcpy(h_cast_name, p->name);
    float h_cast_earning;
    h_cast_earning=average_earning(head, h_cast_name);


    while(Review_idx!=NULL){
        p=Review_idx->review.cast;
        while(p!=NULL){
            cast_1=p;
            strcpy(cast_1_name, cast_1->name);
            cast1_earning=average_earning(head, cast_1_name);
            if (cast1_earning>h_cast_earning) {
                strcpy(h_cast_name, cast_1_name);
                h_cast_earning = cast1_earning;
            }
            p=p->next;
        }
        Review_idx=Review_idx->next;

    }
    printf("%s\n", h_cast_name);
    printf("%f\n", h_cast_earning);
}
