/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "CustomPrint.h"

CY_ISR_PROTO (SPI_Rx_Handler);

uint8_t DataReceived;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_CT_Start();
    SPI_S_Start();
    isr_SPI_rx_StartEx(SPI_Rx_Handler);
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_CT_PutString("Program running\r\n");
    
    for(;;)
    {
        if (DataReceived == 'l')
        {
             Pin_LED1_Write(1);
        }
        if (DataReceived == 'o')
        {
             Pin_LED1_Write(0);
        }
        
        if (!Pin_SW1_Read())
        {
             UART_CT_PutString("ButtonPressed\r\n");
        }
        if (Pin_SW1_Read())
        {
             UART_CT_PutString("ButtonNOTPressed\r\n");
        }
        CyDelay(1000);
    }
}

CY_ISR (SPI_Rx_Handler)
{
    DataReceived = SPI_S_ReadRxData();
    UART_CT_PutChar(DataReceived);
    
    
}


/* [] END OF FILE */
