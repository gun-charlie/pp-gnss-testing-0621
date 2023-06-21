/*
* author: Ryusuke Iwata
* date  : 2023/06/19
* note  : 
*/

#include "mbed.h"
RawSerial pc(USBTX, USBRX, 9600);
SPI spi(p5, p6, p7);
DigitalOut cs(p8);
char cmd;

int main() {
    spi.frequency(1000000);
    cs = 1;
    while(1){
        pc.printf(">> Hit Any Key for sending\r\n\r\n");
        cmd = pc.getc();
        switch(cmd){
            case 'a':
                for(int j = 0; j < 3; j++){
                    cs = 0;
                    for (int i = 0; i < 2200; i++) {
                        spi.write(0);
                    }
                    cs = 1;
                    wait_ms(2);
                }
                break;
            
            case 'x':
                // sending SERVICE_IDLE Request(SET)
                cs = 0;
                spi.write(0x53);
                spi.write(0x50);
                spi.write(0x49);
                spi.write(0x53);

                spi.write(0x14);  // data length
                spi.write(0x00);  // data length
                spi.write(0x0A);  // ident
                spi.write(0x00);  // from

                //8a75ed7b
                spi.write(0x7b);
                spi.write(0xed);
                spi.write(0x75);
                spi.write(0x8a);
                // 6cd6cfb8
                spi.write(0xb8);
                spi.write(0xcf);
                spi.write(0xd6);
                spi.write(0x6c);
                // 81552300
                spi.write(0x00);
                spi.write(0x23);
                spi.write(0x55);
                spi.write(0x81);
                // 42cc7396
                spi.write(0x96);
                spi.write(0x73);
                spi.write(0xcc);
                spi.write(0x42);

                //service_event: 0x20000000
                spi.write(0x00);
                spi.write(0x00);  
                spi.write(0x00);  
                spi.write(0x20);
                
                spi.write(0x00);
                spi.write(0x00);  
                spi.write(0x00);  
                spi.write(0x00);  

                spi.write(0x53);
                spi.write(0x50);
                spi.write(0x49);
                spi.write(0x45);
                
                cs = 1;

                wait_ms(2);

                // sending SERVICE_IDLE Request(GET)
                cs = 0;
                spi.write(0x53);
                spi.write(0x50);
                spi.write(0x49);
                spi.write(0x53);

                spi.write(0x14);  // data length
                spi.write(0x00);  // data length
                spi.write(0x0A);  // ident
                spi.write(0x00);  // from

                //8a75ed7b
                spi.write(0x7b);
                spi.write(0xed);
                spi.write(0x75);
                spi.write(0x8a);
                // 6cd6cfb8
                spi.write(0xb8);
                spi.write(0xcf);
                spi.write(0xd6);
                spi.write(0x6c);
                // 81552300
                spi.write(0x00);
                spi.write(0x23);
                spi.write(0x55);
                spi.write(0x81);
                // 42cc7396
                spi.write(0x96);
                spi.write(0x73);
                spi.write(0xcc);
                spi.write(0x42);

                //service_event: 0x10000000
                spi.write(0x00);
                spi.write(0x00);  
                spi.write(0x00);  
                spi.write(0x10);
                
                spi.write(0x00);
                spi.write(0x00);  
                spi.write(0x00);  
                spi.write(0x00);  

                spi.write(0x53);
                spi.write(0x50);
                spi.write(0x49);
                spi.write(0x45);
                
                cs = 1;

                break;
        }
    }
}
