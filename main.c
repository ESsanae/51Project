#include <REGX52.H>
#include "Delay.h"
#include "MatrixLED.h"

unsigned char Animation[]={ 0x60,0x10,0x20,0xFF,0xF8,0x27,0x10,0x08,
							0x00,0xC0,0x20,0xFF,0xFA,0x24,0xC0,0x00,
							0x00,0x00,0x30,0x7F,0xFE,0xA0,0x00,0x00,
							0x00,0x00,0x20,0x7F,0xFA,0xA4,0x20,0x40,
							0x00,0x00,0x30,0x7F,0xF8,0x36,0x00,0x00,
							0x00,0x00,0x37,0x78,0xF8,0xB6,0x01,0x00,
							0x00,0x20,0x7F,0xF8,0xB4,0x02,0x01,0x00,
							0x00,0x00,0x19,0x3E,0x7C,0x54,0x03,0x00,
							0x00,0x00,0x01,0x02,0x1C,0x3C,0x7B,0x58,
							0x00,0x00,0x19,0x3E,0x7C,0x54,0x03,0x00,
							0x00,0x20,0x7F,0xF8,0xB4,0x02,0x01,0x00,
							0x00,0x00,0x23,0x7C,0xF8,0xB6,0x01,0x00,
							0x00,0x00,0x01,0x02,0x24,0x78,0xFF,0xB0,};
							
void main()
{   unsigned char i,Offset,count;
	MatrixLED_Init();
	while(1)
	{  	
			for(i=0;i<8;i++)
			{
				MatrixLED_ShowColumn(i,Animation[i+Offset]);

			}
            count++;
			if(count>20)
			{
			    count=0;
			    Offset+=8;
				if(Offset>96)
				{
					Offset=0;
				}
			}
	}
}




