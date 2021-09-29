/*******************************************************************************
* File Name: Clock_SPI.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Clock_SPI_H)
#define CY_CLOCK_Clock_SPI_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void Clock_SPI_Start(void) ;
void Clock_SPI_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void Clock_SPI_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void Clock_SPI_StandbyPower(uint8 state) ;
void Clock_SPI_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 Clock_SPI_GetDividerRegister(void) ;
void Clock_SPI_SetModeRegister(uint8 modeBitMask) ;
void Clock_SPI_ClearModeRegister(uint8 modeBitMask) ;
uint8 Clock_SPI_GetModeRegister(void) ;
void Clock_SPI_SetSourceRegister(uint8 clkSource) ;
uint8 Clock_SPI_GetSourceRegister(void) ;
#if defined(Clock_SPI__CFG3)
void Clock_SPI_SetPhaseRegister(uint8 clkPhase) ;
uint8 Clock_SPI_GetPhaseRegister(void) ;
#endif /* defined(Clock_SPI__CFG3) */

#define Clock_SPI_Enable()                       Clock_SPI_Start()
#define Clock_SPI_Disable()                      Clock_SPI_Stop()
#define Clock_SPI_SetDivider(clkDivider)         Clock_SPI_SetDividerRegister(clkDivider, 1u)
#define Clock_SPI_SetDividerValue(clkDivider)    Clock_SPI_SetDividerRegister((clkDivider) - 1u, 1u)
#define Clock_SPI_SetMode(clkMode)               Clock_SPI_SetModeRegister(clkMode)
#define Clock_SPI_SetSource(clkSource)           Clock_SPI_SetSourceRegister(clkSource)
#if defined(Clock_SPI__CFG3)
#define Clock_SPI_SetPhase(clkPhase)             Clock_SPI_SetPhaseRegister(clkPhase)
#define Clock_SPI_SetPhaseValue(clkPhase)        Clock_SPI_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(Clock_SPI__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define Clock_SPI_CLKEN              (* (reg8 *) Clock_SPI__PM_ACT_CFG)
#define Clock_SPI_CLKEN_PTR          ((reg8 *) Clock_SPI__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define Clock_SPI_CLKSTBY            (* (reg8 *) Clock_SPI__PM_STBY_CFG)
#define Clock_SPI_CLKSTBY_PTR        ((reg8 *) Clock_SPI__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define Clock_SPI_DIV_LSB            (* (reg8 *) Clock_SPI__CFG0)
#define Clock_SPI_DIV_LSB_PTR        ((reg8 *) Clock_SPI__CFG0)
#define Clock_SPI_DIV_PTR            ((reg16 *) Clock_SPI__CFG0)

/* Clock MSB divider configuration register. */
#define Clock_SPI_DIV_MSB            (* (reg8 *) Clock_SPI__CFG1)
#define Clock_SPI_DIV_MSB_PTR        ((reg8 *) Clock_SPI__CFG1)

/* Mode and source configuration register */
#define Clock_SPI_MOD_SRC            (* (reg8 *) Clock_SPI__CFG2)
#define Clock_SPI_MOD_SRC_PTR        ((reg8 *) Clock_SPI__CFG2)

#if defined(Clock_SPI__CFG3)
/* Analog clock phase configuration register */
#define Clock_SPI_PHASE              (* (reg8 *) Clock_SPI__CFG3)
#define Clock_SPI_PHASE_PTR          ((reg8 *) Clock_SPI__CFG3)
#endif /* defined(Clock_SPI__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define Clock_SPI_CLKEN_MASK         Clock_SPI__PM_ACT_MSK
#define Clock_SPI_CLKSTBY_MASK       Clock_SPI__PM_STBY_MSK

/* CFG2 field masks */
#define Clock_SPI_SRC_SEL_MSK        Clock_SPI__CFG2_SRC_SEL_MASK
#define Clock_SPI_MODE_MASK          (~(Clock_SPI_SRC_SEL_MSK))

#if defined(Clock_SPI__CFG3)
/* CFG3 phase mask */
#define Clock_SPI_PHASE_MASK         Clock_SPI__CFG3_PHASE_DLY_MASK
#endif /* defined(Clock_SPI__CFG3) */

#endif /* CY_CLOCK_Clock_SPI_H */


/* [] END OF FILE */
