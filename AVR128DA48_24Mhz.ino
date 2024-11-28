#include <avr/io.h>

// 시스템 클럭을 24MHz로 설정하고 자동 튜닝을 활성화하는 함수
void setupSystemClock() 
{
  CCP = CCP_IOREG_gc;
  CLKCTRL.XOSC32KCTRLA = (1 << CLKCTRL_ENABLE_bp);      // XOSC32K Enable
  RTC.CLKSEL = (0x02 << RTC_CLKSEL_gp);                 // RTC for XOSC32K
  CCP = CCP_IOREG_gc;
  CLKCTRL.OSCHFCTRLA = (0x09 << CLKCTRL_FREQSEL_gp)     // OSCHF = 24Mhz
                     | (0x01 << CLKCTRL_AUTOTUNE_bp);   // AUTOTUNE Enable
  CCP = CCP_IOREG_gc;
  CLKCTRL.MCLKCTRLA = (0 << CLKCTRL_CLKSEL_gp);         // CLK_MAIN = OSCHF = 24Mhz
  CCP = CCP_IOREG_gc;
  CLKCTRL.MCLKCTRLB = (0 << CLKCTRL_PEN_bp);            // CLK_PER = CLK_MAIN = 24Mhz

}

void setup() {
    // 시스템 클럭을 설정하는 함수를 호출합니다.
    setupSystemClock();
    PORTC.DIRSET = (1<<6);

}

void loop() 
{
  // 여기에 메인 코드를 작성하세요.
   PORTC.OUTTGL = (1<<6);
   delay(1000);
}
