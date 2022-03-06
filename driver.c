/**********************************************************************/
/*                                                                    */
/*   Program Name:  Driver - Simulates round robin scheduler          */
/*   Author:        Alex Feng                                         */
/*   Installation:  Pensacola Christian College, Pensacola Florida    */
/*   Date Modified: April 9, 2021                                     */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* I pledge this assignment is my own first time work.                */
/* I pledge I did not copy or try to copy work from the Internet.     */
/* I pledge I did not copy or try to copy work from any student.      */
/* I pledge I did not copy or try to copy work from any where else.   */
/* I pledge the only person I asked for help from was my teacher.     */
/* I pledge I did not attempt to help any student on this assignment. */
/* I understand if I violate this pledge I will receive a 0 grade.    */
/*                                                                    */
/*                                                                    */
/*                      Signed: _____________________________________ */
/*                                           (signature)              */
/*                                                                    */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* This program simulates round robin scheduler on how process are    */
/* scheduled based on a number of quantum and a priority number,      */
/* how processes terminate after their work is finished, and how      */
/* existing process are vying for the CPU                             */
/*                                                                    */
/**********************************************************************/

#include <stdio.h>

/**********************************************************************/
/*                        Symbolic Constants                          */
/**************************************** *****************************/
#define SECTORS_PER_TRACK    9   /* Number of sectors per track       */
#define TRACKS_PER_CYLINDER  2   /* Number of tracks per cylinder     */
#define CYLINDER_PER_DISK    40  /* Number of cylinders per disk      */
#define BYTES_PER_SECTOR     512 /* Bytes value of each sector        */

/**********************************************************************/
/*                        Program Structures                          */
/**********************************************************************/
struct message
{        
   int operation_code;  /* the disk operation to be performed         */
   int request_number;  /* a unique request number                    */
   int block_number;    /* the block number to be read or written     */
   int block_size;      /* the block size in bytes                    */
   unsigned long int *p_data_address; 
                        /* points to the data block in memory         */
};
struct message fs_message[20];


/**********************************************************************/
/*                        Function Prototypes                         */
/**********************************************************************/
int send_message();

/**********************************************************************/
/*                          Main Function                             */
/**********************************************************************/
int main()
{   
   send_message(fs_message);
   return 0;
}