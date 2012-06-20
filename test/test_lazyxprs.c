#include <xprs.h>
#include <stdlib.h>
#include <stdio.h>

/**************************************************************************************\
* Name:        loadlp.c                                              Dash 20/03/2000   *
* Purpose:     Load an LP problem directly into Optimizer and modify it by adding an   *
*              extra constraint.                                                       *
* Description: The problem                                                             *
*                               Maximise                                               *
*                                   2x + y                                             *
*                               subject to                                             *
*                                   c1:  x + 4y <= 24                                  *
*                                   c2:       y <=  5                                  *
*                                   c3: 3x +  y <= 20                                  *
*                                   c4:  x +  y <=  9                                  *
*                               and                                                    *
*                                   0 <= x,y <= +infinity                              *
*              and the extra constraint                                                *
*                                   c5: 6x + y <= 20                                   *
*              are first stored in the user's data structures. The LP is then loaded   *
*              into Optimizer, using loadprob, and solved using the primal simplex     *
*              algorithm. Next, the extra constraint is added to the problem matrix,   *
*              using addrows, and the revised problem solved using the dual algorithm. *
*              In each case, the problem matrix is output to a file, the objective     *
*              function value displayed on screen, and the problem statistics are      *
*              are stored in a log file. By default, a binary solution file is also    *
*              created                                                                 *
* Input:       None                                                                    *
* Output:      Lp.mat, Revised.mat, loadlp.log, Lp.sol                                 *
\**************************************************************************************/

#include <stdio.h>
#include "xprs.h"                       /* Optimizer header file */

XPRSprob probg;

void XPRS_CC optimizermsg(XPRSprob prob, void* data, const char *sMsg,int nLen,int nMsgLvl);
void errormsg(const char *sSubName,int nLineNo,int nErrorCode);

int main()
{
   int nReturn;                            /* Return value of Optimizer subroutine */
   int nOptimizerVersion;                  /* Optimizer version number */
   char sProblem1[]  = "lp";               /* First problem name */
   char sProblem2[]  = "revised";          /* Second problem name */
   double dObjValue;                       /* Objective value */
   /* Store the problem */

   /* Row data */
   int nRow          = 4;                  /* Number of rows */
   char sRowType[]   = {'L','L','L','L'};  /* Row types */
   double dRHS[]     = {24,5,20,9};        /* RHS values */
   double *dRange    = NULL;               /* Range values - none in this example */
   char sRowName[]   = "c1\0c2\0c3\0c4";   /* Row names */

   /* Column data */
   int nCol          = 2;                  /* Number of columns */
   double dObj[]     = {2,1};              /* Objective function coefficients */
   double dLowerBd[] = {0,0};              /* Lower bounds on the columns */
   double dUpperBd[] = {XPRS_PLUSINFINITY,XPRS_PLUSINFINITY};    /* Upper bounds - note macro for infinity */
   char sColName[]   = "x\0y";             /* Column names */

   /* Matrix data */
   int nColStart[]   = {0,3,7};            /* Start positions of the columns in dMatElem
                                              - note there are nCol+1 entries, the last
                                              indicating where the next column would
                                              start if there was one */
   int *nColElem     = NULL;               /* Number of elements in each column - not
                                              needed thanks to the last (optional) entry
                                              in nColStart */
   int nRowInd[]     = {0,2,3,  0,1,2,3};  /* Row indices for the matrix elements */
   double dMatElem[] = {1,3,1,  4,1,1,1};  /* Matrix elements - arranged by column */

   /* Store extra constraint */
   int nNewRow           = 1;              /* Number of new rows */
   int nNewElem          = 2;              /* Number of elements in the new row */
   char sNewRowType[1]   = {'L'};          /* New row type */
   char sNewRowName[]    = "c5";           /* New row name */
   double dNewRHS[1]     = {20};           /* New RHS value */
   double dNewRowElem[2] = {6,1};          /* New row elements */
   int nNewRowStart[2]    = {0,2};         /* Start positions of the rows in
                                              dNewRowElem */
   int nNewColInd[2]     = {0,1};          /* Column indices for the new row elements */

   char banner[256];
   int istudent;

   /* Initialise Optimizer */
   nReturn=XPRSinit(NULL);
   if (nReturn != 0 && nReturn != 32) {
      XPRSgetlicerrmsg(banner, sizeof(banner));
      puts(banner);
      return(1);
   }
   istudent = (nReturn == 32); /* Check for student license */

   /* Output Banner */
   banner[0]=0;
   XPRSgetbanner(banner); puts(banner);

   nReturn=XPRScreateprob(&probg);
   if (nReturn != 0 && nReturn != 32) errormsg("XPRScreateprob",__LINE__,nReturn);

   /* Tell Optimizer to call optimizermsg whenever a message is output */
   nReturn=XPRSsetcbmessage(probg,optimizermsg,NULL);

   /* Get and display the Optimizer version number */
   if ((nReturn=XPRSgetintcontrol(probg,XPRS_VERSION,&nOptimizerVersion))) errormsg("XPRSgetintcontrol",__LINE__,nReturn);
   printf("Xpress Optimiser Subroutine Library Release %.2f\n\n",
      (float)nOptimizerVersion/100);

   /*** Load and solve the problem ***/

   /* Load the matrix into Optimizer */
   if ((nReturn=XPRSloadlp(probg,sProblem1,nCol,nRow,sRowType,dRHS,dRange,dObj,nColStart,nColElem,
      nRowInd,dMatElem,dLowerBd,dUpperBd))) errormsg("XPRSloadlp",__LINE__,nReturn);

   /* Add row names */
   if ((nReturn=XPRSaddnames(probg,1,sRowName,0,nRow-1))) errormsg("XPRSaddnames",__LINE__,nReturn);

   /* Add column names */
   if ((nReturn=XPRSaddnames(probg,2,sColName,0,nCol-1))) errormsg("XPRSaddnames",__LINE__,nReturn);

   /* Output the matrix */
   if ( ! istudent ) {
     if ((nReturn=XPRSwriteprob(probg,sProblem1,""))) errormsg("XPRSwriteprob",__LINE__,nReturn);
     printf("Matrix file %s.mat has been created.\n",sProblem1);
   }

   /* Solve the LP problem */
   if ((nReturn=XPRSmaxim(probg,""))) errormsg("XPRSmaxim",__LINE__,nReturn);

   /* Get and display the value of the objective function */
   if ((nReturn=XPRSgetdblattrib(probg,XPRS_LPOBJVAL,&dObjValue))) errormsg("XPRSgetdblattrib",__LINE__,nReturn);
   printf("The optimal objective value is %g.\n\n",dObjValue);

   /*** Add the extra constraint and solve again ***/

   /* Add new row */
   if ((nReturn=XPRSaddrows(probg,nNewRow,nNewElem,sNewRowType,dNewRHS,NULL,nNewRowStart,nNewColInd,
      dNewRowElem))) errormsg("XPRSaddrows",__LINE__,nReturn);

   /* Add new row name */
   if ((nReturn=XPRSaddnames(probg,1,sNewRowName,nRow,nRow))) errormsg("XPRSaddnames",__LINE__,nReturn);

   /* Output the revised matrix */
   if ( ! istudent ) {
     if ((nReturn=XPRSwriteprob(probg,sProblem2,""))) errormsg("XPRSwriteprob",__LINE__,nReturn);
     printf("Matrix file %s.mat has been created.\n",sProblem2);
   }

   /* Solve with dual - since the revised problem inherits dual feasibility
      from the original */
   if ((nReturn=XPRSmaxim(probg,"d"))) errormsg("XPRSmaxim",__LINE__,nReturn);

   /* Get and display the value of the objective function */
   if ((nReturn=XPRSgetdblattrib(probg,XPRS_LPOBJVAL,&dObjValue))) errormsg("XPRSgetdblattrib",__LINE__,nReturn);
   printf("The revised optimal objective value is %g.\n\n",dObjValue);

   /* Free memory, close files */
   if ((nReturn=XPRSdestroyprob(probg))) errormsg("XPRSdestroyprob",__LINE__,nReturn);
   if ((nReturn=XPRSfree())) errormsg("XPRSfree",__LINE__,nReturn);

   printf("xpress: solved a problem sucessfully.\n");

   return 0;
}


/**********************************************************************************\
* Name:         optimizermsg                                                           *
* Purpose:      Display Optimizer error messages and warnings.                         *
* Arguments:    const char *sMsg       Message string                                  *
*               int nLen               Message length                                  *
*               int nMsgLvl            Message type                                    *
* Return Value: None                                                                   *
\**********************************************************************************/
void XPRS_CC optimizermsg(XPRSprob prob, void* data, const char *sMsg,int nLen,int nMsgLvl)
{
   switch (nMsgLvl) {

      /* Print Optimizer error messages and warnings */
      case 4:       /* error */
      case 3:       /* warning */
         printf("%*s\n",nLen,sMsg);
         break;

      /* Ignore other messages */
      case 2:       /* dialogue */
      case 1:       /* information */
         break;
      /* Exit and flush buffers */
      default:
         fflush(NULL);
         break;
    }
}


/**************************************************************************************\
* Name:         errormsg                                                               *
* Purpose:      Display error information about failed subroutines.                    *
* Arguments:    const char *sSubName   Subroutine name                                 *
*               int nLineNo            Line number                                     *
*               int nErrCode           Error code                                      *
* Return Value: None                                                                   *
\**************************************************************************************/
void errormsg(const char *sSubName,int nLineNo,int nErrCode)
{
   int nErrNo;   /* Optimizer error number */

   /* Print error message */
   printf("The subroutine %s has failed on line %d\n",sSubName,nLineNo);

   /* Append the error code, if it exists */
   if (nErrCode!=-1) printf("with error code %d.\n\n",nErrCode);

   /* Append Optimizer error number, if available */
   if (nErrCode==32) {
      XPRSgetintattrib(probg,XPRS_ERRORCODE,&nErrNo);
      printf("The Optimizer error number is: %d.\n\n",nErrNo);
   }

   /* Free memory, close files and exit */
   XPRSdestroyprob(probg);
   XPRSfree();
   exit(nErrCode);
}
