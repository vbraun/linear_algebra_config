#include <stdio.h>

#include "linalg_f77blas.h"

int call_f77blas(const double* mat, const int pitch, double* out);

int main(const int argc, const char** argv)
{
   double matrix[9], oACML[9], oCLAPACK[9];
   matrix[0] = 8.3;
   matrix[1] = 13;
   matrix[2] = 2301.2;
   matrix[3] = 0.213689;
   matrix[4] = 3.141592654;
   matrix[5] = 0;
   matrix[6] = 49;
   matrix[7] = 8.24;
   matrix[8] = -9.8;
   call_f77blas(matrix, 3, oCLAPACK);
   for (int i=0; i<9; ++i)
     printf("%d\n", oCLAPACK[i]);
   return 0;
}

int call_f77blas(const double* mat, const int pitch, double* out)
{
   int i,j;

   double eq[9];
   double u[9];
   double vt[9];

   for(i=0;i<3;i++)
   for(j=0;j<3;j++)
         eq[i*3+j] = mat[i*pitch+j];

   integer sizeX=3, sizeY=3, lda=3, ldu=3, ldvt=3, k=3, p=pitch;
   doublereal alpha=1.0, beta=0.0;

   dgemm_("N","N",&sizeX,&sizeY,&k,&alpha,u,&ldu,vt,&ldvt,&beta,out,&p);

   return 0;
}
