/*

   MODULE DESCRIPTION:  

   AUTHOR:  Marco Ing. Dau		 																									

   ****************************************************************************************************************************************************
   * SVN-keywords: fields managed by SVN - DO NOT MODIFY 
   *
   *	USER who run commit:    $Author: Administrator $																										
   *	REVISION NUMBER:        $Revision: 363 $																											
   *	LAST DATE REVISION:     $Date: 2016-06-16 17:34:11 +0200 (Thu, 16 Jun 2016) $															
   *	LOCATION FILE:          $HeadURL: file:///C:/Users/mdau/Documents/SVN/Repository/Firmware/15101-emphil/work/krTimer.c $			
   *																																						
   ****************************************************************************************************************************************************

 */


#define	_TIMER_C

#include "../Include/Driver/msPlatform.h"


// ----------------------------------------------------------------------------
// SECTION - SYSTEM INCLUDE
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// SECTION - PROJECT INCLUDE
#include "krTimerGlo.h"


// ----------------------------------------------------------------------------

//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SECTION - CONSTANT DEFINITION

// SECTION END
//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SECTION - VARIABLE DEFINITION

// SECTION END
//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SECTION - ARRAY DEFINITION

// SECTION END
//	++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//	****************************************************************************
// SECTION - CONTROL FUNCTION DEFINITION

// SECTION END
//	****************************************************************************

//	****************************************************************************
// SECTION - EVENT FUNCTION DEFINITION

// SECTION END
//	****************************************************************************


//	****************************************************************************
// SECTION - LIBRTARY FUNCTION DEFINITION

// SECTION END
//	****************************************************************************

//	****************************************************************************
//	****************************************************************************
void InitTimer (void)
{
   unsigned char i;
   
   for(i=0;i<TMR_NUMBER;i++)
   {
      Timer[i] = 0;
   }
   // TmrSecond init
   TmrSecond    = 1000;
   
  
}

//	****************************************************************************
//	****************************************************************************
void UpdateTimer (void)
{
   unsigned char i;

   for(i=0;i<TMR_NUMBER;i++)
   {
      if(Timer[i] > (_TICK_DEC_TIMER-1))
      {
         Timer[i] -= _TICK_DEC_TIMER;  
      }
   }

   // check TmrSecond variable
   if (TmrSecond == 0)
   {
      // update TmrError
      TmrError++;
   }
   else
   {
      // update TmrSecond
      TmrSecond -= _TICK_DEC_TIMER;
   }

   
}

//	****************************************************************************
//	****************************************************************************
unsigned char ControlloTimer0 (unsigned char i)
{
   if (Timer[i] == 0)
   {
      return i;
   }
   else
   {
      return 0xFF;
   }

}
