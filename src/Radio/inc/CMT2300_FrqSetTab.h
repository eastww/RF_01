
#ifndef __CMT2300_FREQSETTAB_H__
#define __CMT2300_FREQSETTAB_H__
#include "stm32f0xx.h"
#define CMT2300_BANK_SIZE (0x60 + 0x01)


const uint8_t g_cmt2300FrequencyBank_SetTab[][8] = {

//426MHZ  
//    0x41,
//    0x9F,
//    0x4F,
//    0x19,
//    0x41,
//    0x89,
//    0x9D,
//    0x18,
//430MHZ
    0x41,
    0x3D,
    0x28,
    0x13,
    0x42,
    0x27,
    0x76,
    0x12,
    //433.92MHZ
    0x42,
    0x71,
    0xCE,
    0x1C,
    0x42,
    0x5B,
    0x1C,
    0x1C,
    //868MHZ
    0x42,
    0xCF,
    0xA7,
    0x8C,
    0x42,
    0xC4,
    0x4E,
    0x1C,
    //915MHZ
    0x46,
    0x6D,
    0x80,
    0x86,
    0x46,
    0x62,
    0x27,
    0x16,
    //920MHZ
    0x46,
    0xCF,
    0xA7,
    0x8C,
    0x46,
    0xC4,
    0x4E,
    0x1C,
};

/* [Data Rate Bank] */
const uint8_t g_cmt2300DataRate_SetTab[][24] = {
 
//0.6kbps 
  0x0C,
  0x06,
  0x00,
  0xDD,
  0xD0,
  0xBD,
  0x0C,
  0x05,
  0x9F,
  0x26,
  0x29,
  0x29,
  0xC0,
  0x45,
  0xA9,
  0x53,
  0x00,
  0x00,
  0xB4,
  0x00,
  0x00,
  0x01,
  0x00,
  0x00,  
//1.2Kbps 
  0x19,
  0x0C,
  0x00,
  0xBB,
  0xE0,
  0x9B,
  0x19,
  0x05,
  0x9F,
  0x39,
  0x29,
  0x29,
  0xC0,
  0xA2,
  0x54,
  0x53,
  0x00,
  0x00,
  0xB4,
  0x00,
  0x00,
  0x01,
  0x00,
  0x00, 
//2.4Kbps 
  0x32,
  0x18,
  0x00,
  0x99,
  0xE0,
  0x69,
  0x14,
  0x05,
  0x9F,
  0x39,
  0x29,
  0x29,
  0xC0,
  0x51,
  0x2A,
  0x53,
  0x00,
  0x00,
  0xB4,
  0x00,
  0x00,
  0x01,
  0x00,
  0x00, 
//4.8Kbps
  0x65,
  0x30,
  0x00,
  0x66,
  0xE0,
  0x36,
  0x19,
  0x05,
  0x9F,
  0x38,
  0x29,
  0x29,
  0xC0,
  0x28,
  0x15,
  0x53,
  0x08,
  0x00,
  0xB4,
  0x00,
  0x00,
  0x01,
  0x00,
  0x00,  
//10Kbps
  0xD3,
  0x64,
  0x10,
  0x33,
  0xE9,
  0x35,
  0x1F,
  0x05,
  0x9F,
  0x4B,
  0x29,
  0x29,
  0xC0,
  0x28,
  0x0A,
  0x53,
  0x08,
  0x00,
  0xB4,
  0x00,
  0x00,
  0x01,
  0x00,
  0x00,  
    //50Kbps
  0x1F,
  0xF8,
  0x11,
  0x10,
  0x62,
  0x12,
  0x0F,
  0x05,
  0x9F,
  0x6C,
  0x29,
  0x29,
  0xC0,
  0x08,
  0x02,
  0x53,
  0x18,
  0x00,
  0xB4,
  0x00,
  0x00,
  0x01,
  0x00,
  0x00,

    //100Kbps
  0x3F,
  0xF0,
  0x63,
  0x10,
  0x63,
  0x12,
  0x0F,
  0x05,
  0x9F,
  0x6C,
  0x29,
  0x29,
  0xC0,
  0x04,
  0x01,
  0x53,
  0x20,
  0x00,
  0xB4,
  0x00,
  0x00,
  0x01,
  0x00,
  0x00,
 //200Kbps  
  0x53,
  0xCC,
  0x77,
  0x10,
  0x64,
  0x12,
  0x07,
  0x05,
  0x9F,
  0x7D,
  0x29,
  0x29,
  0xC0,
  0x83,
  0x00,
  0x53,
  0x28,
  0x00,
  0xB4,
  0x00,
  0x00,
  0x01,
  0x00,
  0x00,
  

};
const uint8_t g_cmt2300DataRate_SetTab2[][9] = {
 
//0.6kbps  
  0xF0,
  0x50,
  0x26,
  0x03,
  0x10,
  0x0D,
  0xF0,
  0x00,
  0x3F,
 
//1.2Kbps  
  0xF0,
  0x50,
  0x0A,
  0x05,
  0x00,
  0x42,
  0xB0,
  0x00,
  0x3F,

  
//2.4Kbps    
  0xF0,
  0x50,
  0x0A,
  0x05,
  0x00,
  0x42,
  0xB0,
  0x00,
  0x3F,
  
//4.8Kbps 
  
  0xF0,
  0x50,
  0x4D,
  0x06,
  0x00,
  0x20,
  0xB0,
  0x00,
  0x3F,
 
//10Kbps
  0xF0,
  0x50,
  0xC0,
  0x0F,
  0x00,
  0x0F,
  0x70,
  0x00,
  0x3F,   
//50Kbps
  0xF0,
  0x50,
  0xC0,
  0x0F,
  0x00,
  0x02,
  0x30,
  0x00,
  0x3F,
  
//100Kbps
/*0x04*/ 0x70,
/*0x55*/ 0x50,
/*0x56*/ 0x81,
/*0x57*/ 0x1F,
/*0x58*/ 0x00,
/*0x59*/ 0x00,
/*0x5a*/ 0x30,
/*0x5b*/ 0x00,
/*0x5e*/ 0x7F,

//200Kbps
/*0x04*/ 0x30,
/*0x55*/ 0x70,
/*0x56*/ 0x81,
/*0x57*/ 0x1F,
/*0x58*/ 0x00,
/*0x59*/ 0x00,
/*0x5a*/ 0x30,
/*0x5b*/ 0x00,
/*0x5e*/ 0xFF,


};

/* [Tx Bank] */
const uint8_t g_cmt2300TxPower_Tab[][4] = {

     //-15dBm
    /*0x03*/ 0x1C,
    /*0x5C*/ 0x02,
    /*0x5D*/ 0x01,
    /*0x5E*/ 0xFF,
    
    //-10dBm
    /*0x03*/ 0x1C,
    /*0x5C*/ 0x04,
    /*0x5D*/ 0x01,
    /*0x5E*/ 0xFF, 
  
    //-5dBm
    /*0x03*/ 0x1C,
    /*0x5C*/ 0x07,
    /*0x5D*/ 0x01,
    /*0x5E*/ 0xFF, 
    
   
    //0dBm
    /*0x03*/ 0x1C,
    /*0x5C*/ 0x0D,
    /*0x5D*/ 0x01,
    /*0x5E*/ 0xFF,
    
    //5dBm
    /*0x03*/ 0x1C,
    /*0x5C*/ 0x1A,
    /*0x5D*/ 0x02,
    /*0x5E*/ 0xFF, 
   
    
    //+10dBm
    /*0x03*/ 0x1C,
    /*0x5C*/ 0x2E,
    /*0x5D*/ 0x05,
    /*0x5E*/ 0xFF,
    
    //+15dBm
    /*0x03*/ 0x1C,
    /*0x5C*/ 0x56,
    /*0x5D*/ 0x0B,
    /*0x5E*/ 0xFF,
    
    
    //+20dBm
    /*0x03*/ 0x1C,
    /*0x5C*/ 0xFF,
    /*0x5D*/ 0xFF,
    /*0x5E*/ 0xFF,
};

#endif
