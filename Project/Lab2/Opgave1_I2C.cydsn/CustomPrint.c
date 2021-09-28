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


#include <stdint.h>
#include "project.h"
#include "CustomPrint.h"
#include <stdio.h>
    //prints a sring followed by a interger number 
void PrintStringInt(char str[], uint8_t len, uint8_t num)
{
	char buffer[255], string[255] = { "" }, conchar[8] = { ": %d\r\n" };
	uint8_t i = 0; 
	for (i = 0; i < len; i++)
	{
		string[i] = str[i]; 
	}
	for (i = len; i < len+8; i++)
	{

		string[i] = conchar[i-len];
	}
	snprintf(buffer, sizeof(buffer), string, num);
    
    UART_CT_PutString(buffer);
return;
}

    //prints a string followed by a float type number
void PrintStringFloat(char str[], uint8_t len, float num)
{
	char buffer[255], string[255] = { "" }, conchar[8] = { ": %f\r\n" };
	uint8_t i = 0; 
	for (i = 0; i < len; i++)
	{
		string[i] = str[i]; 
	}
	for (i = len; i < len+8; i++)
	{

		string[i] = conchar[i-len];
	}
	snprintf(buffer, sizeof(buffer), string, num);
    
    UART_CT_PutString(buffer);
    return;   
}

/* [] END OF FILE */
