/**********************************************************************/
/*                                                                    */
/*   Program Name:  Convert - Convert block numbers to other specs    */
/*   Author:        Alex Feng                                         */
/*   Installation:  Pensacola Christian College, Pensacola Florida    */
/*   Date Modified: April 10, 2021                                    */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* This program converts block numbers to corresponding cylinder,     */
/* number, track number, and sector number.                           */
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
/*                        Function Prototypes                         */
/**********************************************************************/
void convert_block(int block_number, int *p_cylinder_number,
                   int *p_track_number, int *p_sector_number);
   /* Calculates cylinder, track, and sector number                   */

/**********************************************************************/
/*                          Main Function                             */
/**********************************************************************/
int main()
{
   int block_number    = 1,    /* Block number on the disk            */
       cylinder_number = 0,    /* Cylinder number on the disk         */
       sector_number   = 0,    /* Sector number on the disk           */
       track_number    = 0;    /* Track number on the disk            */

   /* Print program heading                                           */
   printf(  "Block       Cylinder       Track       Sector");
   printf("\n-----       --------       -----       ------");

   /* Loop printing cylinder, track, and sector number                */
   while(block_number <= 360)
   {
      convert_block(block_number, &cylinder_number, &track_number,
                   &sector_number);  
      printf(  "\n %3d           %2d            %d            %d ",
         block_number, cylinder_number, track_number, sector_number);  
      block_number++;
   }
   return 0;
}

/**********************************************************************/
/*           Calculates cylinder, track, and sector number            */
/**********************************************************************/
void convert_block(int block_number, int *p_cylinder_number,
                   int *p_track_number, int *p_sector_number)
{
   *p_cylinder_number = (block_number - 1) / 9;
   
   if (((block_number - 1) % 9) < 4.5)
      *p_track_number = 0;
   else
      *p_track_number = 1;
   
   if (((block_number - 1) % 9) * 2 <= 8)
      *p_sector_number = ((block_number - 1) % 9) * 2;
   else
      *p_sector_number = (((block_number - 1) % 9) * 2) - 9;
   
   return;
}