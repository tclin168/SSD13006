

// I2C1-Parameter Settings-12C Speed Mode: Fast Mode - I2C Clock Speed(HZ):400000

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "fonts.h"
#include "ssd1306.h"
/* USER CODE END Includes */


/* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */

  SSD1306_Init(); //initialise
  /// print some string
  	  char snum[5];

  	  SSD1306_GotoXY(0,0);
  	  SSD1306_Puts("Hello", &Font_11x18, 1);
  	  SSD1306_GotoXY(0,30);
  	  SSD1306_Puts("World", &Font_11x18, 1);
  	  SSD1306_UpdateScreen(); //display
  	  HAL_Delay(1000);

      SSD1306_ScrollRight(0x00,0x07);
      HAL_Delay(1000);
      SSD1306_ScrollLeft(0x00,0x07);
      HAL_Delay(1000);

      SSD1306_Stopscroll();
      SSD1306_Clear();
      SSD1306_GotoXY(40,0);
      SSD1306_Puts("RWU", &Font_11x18, 1);
      SSD1306_UpdateScreen(); //display
      HAL_Delay(2000);

  /* USER CODE END 2 */


  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  for ( int x = 1; x <= 10 ; x++ ) //10000
	  	{
	  		itoa(x, snum, 10);
	  		SSD1306_GotoXY (0, 30);
	  		SSD1306_Puts ("           ", &Font_16x26, 1);
	  		SSD1306_UpdateScreen();
	  		if(x < 10) {
	  			SSD1306_GotoXY (53, 30);  // 1 DIGIT
	  		}
	  		else if (x < 100 ) {
	  			SSD1306_GotoXY (45, 30);  // 2 DIGITS
	  		}
	  		else if (x < 1000 ) {
	  			SSD1306_GotoXY (37, 30);  // 3 DIGITS
	  		}
	  		else {
	  			SSD1306_GotoXY (30, 30);  // 4 DIGIS
	  		}
	  		SSD1306_Puts (snum, &Font_16x26, 1);
	  		SSD1306_UpdateScreen();
	  		HAL_Delay (300);
	  	    }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}