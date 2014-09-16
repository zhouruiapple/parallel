/******************************************************************************
 * * FILE: omp_mm.c
 * * DESCRIPTION:  
 * *   OpenMp Example - Matrix Multiply - C Version
 * *   Demonstrates a matrix multiply using OpenMP. Threads share row
 * iterations
 * *   according to a predefined chunk size.
 * * AUTHOR: Blaise Barney
 * * LAST REVISED: 06/28/05
 * ******************************************************************************/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define NRA 62                 /* number of rows in matrix A */
#define NCA 15                 /* number of columns in matrix A */
#define NCB 7                  /* number of columns in matrix B */

int main (int argc, char *argv[]) 
{
    int tid, nthreads, i, j, k, chunk;
    double  a[NRA][NCA],           /* matrix A to be multiplied */
                b[NCA][NCB],           /* matrix B to be multiplied */
                    c[NRA][NCB];           /* result matrix C */

    chunk = 10;                    /* set loop iteration chunk size */

    
    double start = omp_get_wtime();

                for (i=0; i<NRA; i++)
                        for (j=0; j<NCA; j++)
                                  a[i][j]= i+j;
                  for (i=0; i<NCA; i++)
                          for (j=0; j<NCB; j++)
                                    b[i][j]= i*j;
                    for (i=0; i<NRA; i++)
                            for (j=0; j<NCB; j++)
                                      c[i][j]= 0;
                      printf("Thread %d starting matrix multiply...\n",tid);
                        for (i=0; i<NRA; i++)    
                                {
                                        printf("Thread=%d did row=%d\n",tid,i);
                                            for(j=0; j<NCB; j++)       
                                                      for (k=0; k<NCA; k++)
                                                                  c[i][j] += a[i][k] * b[k][j];
                                                }

        double end = omp_get_wtime();
 
      /*** Print results ***/
      printf("******************************************************\n");
      printf("Result Matrix:\n");
      for (i=0; i<NRA; i++)
            {
                  for (j=0; j<NCB; j++) 
                          printf("%6.2f   ", c[i][j]);
                    printf("\n"); 
                      }
      printf("******************************************************\n");


    printf("start time = %f\n",start);
    printf("end time = %f\n",end);
    printf("diff time = %f\n",end - start);

      printf ("Done.\n");

}

