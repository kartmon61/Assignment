// Overflow Timer 예제 
// 1초 마다 LED on


#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint16_t total_overflow_count;

ISR(TIMER0_OVF_vect){
    total_overflow_count++;
    TCNT0 = 6;
}

int main(void){
    DDRB |=(1<<DDB3); //LED용
    TCCR0 |=(1<<CS02); //프리스케일러로 64를 선택
    TCNT0 = 6; //카운터 초기화 256~250

    TIMSK |= (1<< TOIE0); //타이머/카운터 오버플로우 인터럽트 활성화

    sei(); //전역 인터럽트 활성화

    total_overflow_count = 0;

    while(1){
        if(total_overflow_count == 1000) //1초마다 LED 켜짐
        {
            total_overflow_count = 0;
            PORTB |=(1<<PB3);
            _delay_ms(10);
        }
        else{
            PORTB &= (~(1<<PB3));
        }
    }
}