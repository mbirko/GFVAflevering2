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
    #include <stdbool.h>
    #include "project.h"
    #include "CustomPrint.h"



    bool getTemp(int16_t *temp, uint8_t slaveAddress)
    {
        uint8_t status;
        status = I2C_M_MasterSendStart(slaveAddress, 1); 
        if (status == I2C_M_MSTR_NO_ERROR)
        {
            uint8_t bH = I2C_M_MasterReadByte(I2C_M_ACK_DATA);
            uint8_t bL = I2C_M_MasterReadByte(I2C_M_NAK_DATA);
            
            I2C_M_MasterSendStop();
            
            if (bH)
                bH = 0xff;
            
            *temp = ((bH << 8) + bL);
            return true;
        }
        else
        {
            PrintStringInt("Fejl: ", 9, status);
            I2C_M_MasterSendStop();
            return false;
        }
    }
    
    float convertToCeltius(int16_t temp)
    {
        return ((float)temp / 2);
    }
    

/* [] END OF FILE */
