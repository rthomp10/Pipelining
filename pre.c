#include <stdio.h>
int main()
{
   const int NUMSTATES = 10;
   const int STATELENGTH = 20;
   char state [NUMSTATES][STATELENGTH]; //inputed abbreviation of states
   int population [NUMSTATES]; //inputted population of respective state
   
   //input
   for(int i = 0; i < NUMSTATES; i++)
   {
	   scanf( "%s %d", state[i], &population[i] ); 
   }
   printf("\n");
   
   //output
   for(int i = 0; i < NUMSTATES; i++)
   {
	   //skips non-inputted states
	   if( population[i] == 0 )
	   {
		   i = NUMSTATES;
	   }
	   //prints out current states above 10 million
	   else if( population[i] > 10)
	   {
		   printf("%s",state[i]);
		   printf("\n");
	   }
   }
   return 0;
   
   /*
   cd /Users/rthompson1000/Desktop/OperatingSystems/project1
   gcc pre.c
   ./a.out
   
   */
}
