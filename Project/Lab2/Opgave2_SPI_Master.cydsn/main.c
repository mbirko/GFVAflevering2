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
uint8_t DataToReceive;

// Interrupt service rutines prototypes 
CY_ISR_PROTO (UART_Rx_CT_Handeler);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_CT_Start();
    
    isr_UART_CT_StartEx(UART_Rx_CT_Handeler);
    
    SPI_M_Start();
    
    UART_CT_PutString("Program running\r\n");
    //bool btn_isOn = false;
    
    for(;;)
    {
        
        //DataToReceive = SPI_M_ReadRxData();
        
        
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
        /*
        // takes actions based on input. 
        switch (c)
        {
            case 't' :             
            {
                UART_CT_PutString("test!\r\n");
            }
            break;
            case 'i' :             
            {
                UART_CT_PutString("testing print int!\r\n");
                PrintStringFloat("int", 3, 7);
            }
            break;
            case 'f' :             
            {   
                UART_CT_PutString("test print float!\r\n");
                PrintStringFloat("float", 5, 3.6);
            }
            break;
            case 'l' :             
            {   
                UART_CT_PutString("Toggle LED\r\n");
                // old ^= (1<<0);
                PrintStringInt("DataToSend: ", 12, DataToSend);
            }
            break;
            case 'c' :             
            {   
                UART_CT_PutString("Check ReceiveData\r\n");
                PrintStringInt("DataToReceive: ", 15, DataToReceive);
            }
            break;
            default:
            {
                UART_CT_PutChar(c);
                UART_CT_PutString("\r\n");
            }
            break;
        }*/
    }
} // end of uart handler

/* [] END OF FILE */
