#include <REGX52.H>
#include "Delay.h"

sbit RCLK_=P3^5;
sbit SRCLK_=P3^6;
sbit SER_=P3^4;

#define MATRIX_LED_PORT P0
void MatrixLED_Init()
{
	SRCLK_=0;
	RCLK_=0;
}


/**
  * @brief  74HC595写入一个字节
  * @param  要写入的字节 
  * @retval 无
  */

void _74HC595_WriteByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		SER_=Byte&(0x80>>i);//每次取出一位	
		SRCLK_=1;
		SRCLK_=0;
	}
	RCLK_=1;
	RCLK_=0;
	
}
/**
  * @brief  LED点阵屏显示一列数据
  * @param  Column 要选择的列 0~7  0在最左边
  * @param  Data 选择列显示的数据  1为亮 0为灭
  * @retval 无     使用前需将在主函数中将SCRLK（上升沿位移）和RCLK（上升沿锁存）置0；（SRCLK_=0; RCLK_=0;）
  */
void MatrixLED_ShowColumn(unsigned char Column,Data)
{
	_74HC595_WriteByte(Data);
	MATRIX_LED_PORT=~(0x80>>Column);
	Delay(1);
	MATRIX_LED_PORT=0xFF;
}