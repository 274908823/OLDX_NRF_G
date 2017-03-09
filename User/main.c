#include "head.h"

int main(void)
{		ErrorStatus HSEStartUpStatus;
		//RCC reset
		RCC_DeInit();
		//�����ⲿʱ�� ��ִ�г�ʼ��
		RCC_HSEConfig(RCC_HSE_ON); 
		//�ȴ��ⲿʱ��׼����
		HSEStartUpStatus = RCC_WaitForHSEStartUp();
		//����ʧ�� ������ȴ�
		while(HSEStartUpStatus == ERROR);
		//�����ڲ�����ʱ��
		RCC_HCLKConfig(RCC_SYSCLK_Div1);
		RCC_PCLK1Config(RCC_HCLK_Div1);
		RCC_PCLK2Config(RCC_HCLK_Div1);
		//�ⲿʱ��Ϊ8M ���ﱶƵ��72M
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);
		RCC_PLLCmd(ENABLE); 
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		while(RCC_GetSYSCLKSource() != 0x08);
		//----------------------------- CLOSE HSI ---------------------------
		RCC_HSICmd(DISABLE);//�ر���`
		
		delay_init(72);
		LED_GPIO_Config();
		KEY_SEL_Config();
		KEY_GPIO_Config();
		Spi1_Init();		
		Nrf24l01_Init(MODEL_TX2,40);// α˫��  ������
		Nrf24l01_Check();
		delay_ms(2000);
		usart1_config();
		
		while(1){
	  RED_KEY();
    RED_KEY_SEL();
		static u8 cnt[3];	
		if(cnt[0]++>5){cnt[0]=0;	
		RC_Send_Task();	
		}
		
		
		if(cnt[1]++>2){cnt[1]=0;	
	  Nrf_Check_Event();
		
//		if(key[3])//���ִ���ģʽ
	//  {
//		UART2_ReportMotion(BLE_DEBUG[0],BLE_DEBUG[1] , BLE_DEBUG[2], 
//				 BLE_DEBUG[3], BLE_DEBUG[4], BLE_DEBUG[5],
//				 BLE_DEBUG[6], BLE_DEBUG[7], BLE_DEBUG[8]);
//		UART2_ReportIMU( BLE_DEBUG[9], BLE_DEBUG[10], BLE_DEBUG[11]
//		, BLE_DEBUG[12], BLE_DEBUG[13], BLE_DEBUG[14], BLE_DEBUG[15]);
//		}
 //   else		
		
		}
		if(cnt[2]++>1){cnt[2]=0;	
		GOL_LINK_TASK();
		}
		delay_ms(5);
			
		}
}
/*********************************************END OF FILE**********************/

