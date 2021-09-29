/*******************************************************************************
* File Name: SPI_M_PM.c
* Version 2.50
*
* Description:
*  This file contains the setup, control and status commands to support
*  component operations in low power mode.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPI_M_PVT.h"

static SPI_M_BACKUP_STRUCT SPI_M_backup =
{
    SPI_M_DISABLED,
    SPI_M_BITCTR_INIT,
};


/*******************************************************************************
* Function Name: SPI_M_SaveConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SPI_M_SaveConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPI_M_RestoreConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SPI_M_RestoreConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPI_M_Sleep
********************************************************************************
*
* Summary:
*  Prepare SPIM Component goes to sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPI_M_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPI_M_Sleep(void) 
{
    /* Save components enable state */
    SPI_M_backup.enableState = ((uint8) SPI_M_IS_ENABLED);

    SPI_M_Stop();
}


/*******************************************************************************
* Function Name: SPI_M_Wakeup
********************************************************************************
*
* Summary:
*  Prepare SPIM Component to wake up.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPI_M_backup - used when non-retention registers are restored.
*  SPI_M_txBufferWrite - modified every function call - resets to
*  zero.
*  SPI_M_txBufferRead - modified every function call - resets to
*  zero.
*  SPI_M_rxBufferWrite - modified every function call - resets to
*  zero.
*  SPI_M_rxBufferRead - modified every function call - resets to
*  zero.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPI_M_Wakeup(void) 
{
    #if(SPI_M_RX_SOFTWARE_BUF_ENABLED)
        SPI_M_rxBufferFull  = 0u;
        SPI_M_rxBufferRead  = 0u;
        SPI_M_rxBufferWrite = 0u;
    #endif /* (SPI_M_RX_SOFTWARE_BUF_ENABLED) */

    #if(SPI_M_TX_SOFTWARE_BUF_ENABLED)
        SPI_M_txBufferFull  = 0u;
        SPI_M_txBufferRead  = 0u;
        SPI_M_txBufferWrite = 0u;
    #endif /* (SPI_M_TX_SOFTWARE_BUF_ENABLED) */

    /* Clear any data from the RX and TX FIFO */
    SPI_M_ClearFIFO();

    /* Restore components block enable state */
    if(0u != SPI_M_backup.enableState)
    {
        SPI_M_Enable();
    }
}


/* [] END OF FILE */
