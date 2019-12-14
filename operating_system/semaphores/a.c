char flag;
char judge[3];

int main(void){
    init();
    char data1[2] = {'0','1'};
    char data2[2] = {'0','1'};
    int i;
    DDRA=0xFF;

    while(1){
        PORTA=0xFF;

        flag=blu_USART_Receive();
        judge=pi_USART_Receive();
        if(judge[0] == '1'){
            PORTA=0x01;
            _delay_ms(1000);
            flag = judge[2]+judge[3];
            blu_USART_Transmit(flag);
        }
        else if(judge[0] == '2'){
            PORTA=0x02;
            for(i=0;i<2;i++){
                PORTA=0x0F;
                _delay_ms(1000);
                PORTA=0x00;
                _delay_ms(1000);
            }
            _delay_ms(1000);
        }
    }
}