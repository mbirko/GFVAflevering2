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
#include <stdint.h>
#include <stdbool.h>
#include "CustomPrint.h"

// Global variables
uint8_t DataToSend;
uint8_t DataReceived;

// Interrupt service rutines prototypes 
CY_ISR_PROTO (UART_Rx_CT_Handeler);

CY_ISR_PROTO (SPI_Rx_Handler);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_CT_Start();
    
    isr_UART_CT_StartEx(UART_Rx_CT_Handeler);
    
    SPI_M_Start();
    isr_SPI_rx_StartEx(SPI_Rx_Handler);
    
    UART_CT_PutString("Program running\r\n");
    //bool btn_isOn = false;
    
    for(;;)
    {
        
        /*DataToReceive = SPI_M_ReadRxData();
        
        if (DataToReceive == 1)
        {
             UART_CT_PutString("Slave SW1 is HIGH\r\n");
        }
        if (DataToReceive == 0)
        {
             UART_CT_PutString("Slave SW1 is LOW\r\n");
        }*/
        
        /*
        // Check buttonstate on slave
        if (!btn_isOn && (DataToReceive))// & (1<<0)))
        {
            UART_CT_PutString("ButtonState: HIGH\r\n");
            btn_isOn = true;
        }
        if (btn_isOn && !(DataToReceive))// & (1<<0)))
        {
            UART_CT_PutString("ButtonState: LOW\r\n");
            btn_isOn = false;
        }
        */
    }
}

// Interrupt services rutines 
CY_ISR (UART_Rx_CT_Handeler)
{
    uint8_t numberOfBytes = UART_CT_GetRxBufferSize();
    
    for (uint8_t i = 0; i < numberOfBytes; i++)
    {
        char c = UART_CT_GetChar();
        
        UART_CT_PutChar(c);
        UART_CT_PutString("\r\n");
        
        DataToSend = c; 
        SPI_M_WriteTxData(DataToSend);
       
    }
} // end of uart handler

CY_ISR (SPI_Rx_Handler)
{
    DataReceived = SPI_M_ReadRxData();
    UART_CT_PutChar(DataReceived);
    
    
}


/* [] END OF FILE */
