#include "mbed.h"

//------------------------------------
// Terminal configuration
// 9600 bauds, 8-bit data, no parity
// /dev/ttyACM0
//------------------------------------

Serial pc(SERIAL_TX, SERIAL_RX);

DigitalOut message(LED3);
DigitalOut sortie(LED2);

volatile int c = 0; // Initialized to the NULL

  
void onintReceived()
{
    c = pc.getc();
}

int main()
{
    pc.printf("Bonjour Utilisateur!\n");
    wait(1);
    pc.printf("Infos : taper 1 pour activer la led.\n");
    
    while(1) {
         
        sortie = 1;
        wait(0.0000001);
                            
        pc.printf("Attente instruction :\r\n");  
        c = pc.getc();
        pc.printf("instruction reçus.\r\n");
        wait(0.001);
        
        if (c == '1')
        {
            pc.printf("Activation de la led rouge...\n");
            wait(0.000001);
            message = 1;
            wait(5);
            message = 0;
            pc.printf("clignotement de la led...\n");
            wait(0.000001);
            message = 1;
            wait(1);
            message = 0;
            wait(1);
            message = 1;
            wait(1);
            message = 0;
            wait(1);
            message = 1;
            wait(1);
            message = 0;
            wait(1);
            message = 1;
            wait(1);
            message = 0;
            wait(1);
            message = 1;
            wait(1);
            message = 0;
            wait(1);
            message = 1;
            wait(1);
            message = 0;
            wait(1);
            message = 1;
            wait(1);
            message = 0;
            wait(1);
            message = 1;
            wait(1);
            message = 0;
            pc.printf("Fin d'activation\r\n");
                    
       }
    }
}
