#include "led.h"
#include "delay.h"
void LED_GPIO_Config(void)
{		
	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

	/*ѡ��Ҫ���Ƶ�GPIOC����*/															   
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_0	;

	/*��������ģʽΪͨ���������*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

	/*������������Ϊ50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

	/*���ÿ⺯������ʼ��GPIOB*/
  	GPIO_Init(GPIOB, &GPIO_InitStructure);		 
	

	/* �ر�����led��	*/
	GPIO_SetBits(GPIOB, GPIO_Pin_0 | GPIO_Pin_1);	 
	delay_ms(200);
	GPIO_ResetBits(GPIOB, GPIO_Pin_0 | GPIO_Pin_1);	 
	delay_ms(200);
	GPIO_SetBits(GPIOB, GPIO_Pin_0 | GPIO_Pin_1);	 
	delay_ms(200);
	GPIO_ResetBits(GPIOB, GPIO_Pin_0 | GPIO_Pin_1);	 
}

void LED_STATE(u8 sel,u8 on)
{
switch(sel)
{
case RX_LED:
if(!on)
GPIO_ResetBits(GPIOB,GPIO_Pin_0);
else
GPIO_SetBits(GPIOB,GPIO_Pin_0);
break;
case TX_LED:
if(!on)
GPIO_ResetBits(GPIOB,GPIO_Pin_1);
else
GPIO_SetBits(GPIOB,GPIO_Pin_1);
break;
}
}


void KEY_GPIO_Config(void)
{		
	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
   GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);  
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 ;

  GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	/*ѡ��Ҫ���Ƶ�GPIOC����*/															   
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4|GPIO_Pin_5 | GPIO_Pin_6|GPIO_Pin_7 | GPIO_Pin_8|GPIO_Pin_9	;

	/*��������ģʽΪͨ���������*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;   

	/*������������Ϊ50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

	/*���ÿ⺯������ʼ��GPIOB*/
  	GPIO_Init(GPIOB, &GPIO_InitStructure);		 
	
	
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE); 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

	/*ѡ��Ҫ���Ƶ�GPIOC����*/															   
  	GPIO_InitStructure.GPIO_Pin = GPIO_Mode_IN_FLOATING	;

	/*��������ģʽΪͨ���������*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;   

	/*������������Ϊ50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

	/*���ÿ⺯������ʼ��GPIOB*/
  	GPIO_Init(GPIOA, &GPIO_InitStructure);		 
}
u8 key[8];
void RED_KEY(void)
{
key[7]=!GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9);
key[6]=!GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8);
key[5]=!GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7);
key[4]=!GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6);



	
key[3]=!GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5);
key[2]=!GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4);	
key[1]=!GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_3);	//--<
key[0]=!GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_15);	
}

u8 key_sel[4];
void RED_KEY_SEL(void)
{
key_sel[3]=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12);
key_sel[2]=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13);
key_sel[1]=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14);
key_sel[0]=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_15);

}
void KEY_SEL_Config(void)
{		
/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE); 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

	/*ѡ��Ҫ���Ƶ�GPIOC����*/															   
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13|GPIO_Pin_14 | GPIO_Pin_15	;

	/*��������ģʽΪͨ���������*/
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;   

	/*������������Ϊ50MHz */   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

	/*���ÿ⺯������ʼ��GPIOB*/
  	GPIO_Init(GPIOB, &GPIO_InitStructure);	
	
}