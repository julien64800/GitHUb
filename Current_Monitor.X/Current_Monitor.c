/*
 * File:   Current_Monitor.c
 * Author: julien
 *
 * Created on April 2, 2017, 10:03 AM
 */

// PIC18F87J11 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1L

// CONFIG1H
#pragma config OSC = HS         // Oscillator Selection bits (HS oscillator)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Two-Speed Start-up disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 3         // Brown-out Voltage bits (Minimum setting)

// CONFIG2H
#pragma config WDT = OFF         // Watchdog Timer (WDT enabled)
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3L
#pragma config MODE = MC        // Processor Data Memory Mode Select bits (Microcontroller mode)
#pragma config ADDRBW = ADDR20BIT// Address Bus Width Select bits (20-bit Address Bus)
#pragma config DATABW = DATA16BIT// Data Bus Width Select bit (16-bit External Bus mode)
#pragma config WAIT = OFF       // External Bus Data Wait Enable bit (Wait selections are unavailable for table reads and table writes)

// CONFIG3H
#pragma config CCP2MX = PORTC   // CCP2 MUX bit (ECCP2 input/output is multiplexed with RC1)
#pragma config ECCPMX = PORTE   // ECCP MUX bit (ECCP1/3 (P1B/P1C/P3B/P3C) are multiplexed onto RE6, RE5, RE4 and RE3 respectively)
#pragma config LPT1OSC = OFF    // Low-Power Timer1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RG5 input pin disabled)

// CONFIG4L
#pragma config STVREN = OFF      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = ON         // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled)
#pragma config BBSIZ = BB2K     // Boot Block Size Select bits (1K word (2 Kbytes) Boot Block size)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit Block 0 (Block 0 (000800, 001000 or 002000-003FFFh) not code-protected)
#pragma config CP1 = OFF        // Code Protection bit Block 1 (Block 1 (004000-007FFFh) not code-protected)
#pragma config CP2 = OFF        // Code Protection bit Block 2 (Block 2 (008000-00BFFFh) not code-protected)
#pragma config CP3 = OFF        // Code Protection bit Block 3 (Block 3 (00C000-00FFFFh) not code-protected)
#pragma config CP4 = OFF        // Code Protection bit Block 4 (Block 4 (010000-013FFFh) not code-protected)
#pragma config CP5 = OFF        // Code Protection bit Block 5 (Block 5 (014000-017FFFh) not code-protected)
#pragma config CP6 = OFF        // Code Protection bit Block 6 (Block 6 (01BFFF-018000h) not code-protected)
#pragma config CP7 = OFF        // Code Protection bit Block 7 (Block 7 (01C000-01FFFFh) not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot Block (000000-0007FFh) not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit Block 0 (Block 0 (000800, 001000 or 002000-003FFFh) not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit Block 1 (Block 1 (004000-007FFFh) not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit Block 2 (Block 2 (008000-00BFFFh) not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit Block 3 (Block 3 (00C000-00FFFFh) not write-protected)
#pragma config WRT4 = OFF       // Write Protection bit Block 4 (Block 4 (010000-013FFFh) not write-protected)
#pragma config WRT5 = OFF       // Write Protection bit Block 5 (Block 5 (014000-017FFFh) not write-protected)
#pragma config WRT6 = OFF       // Write Protection bit Block 6 (Block 6 (01BFFF-018000h) not write-protected)
#pragma config WRT7 = OFF       // Write Protection bit Block 7 (Block 7 (01C000-01FFFFh) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block (000000-007FFF, 000FFF or 001FFFh) not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit Block 0 (Block 0 (000800, 001000 or 002000-003FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit Block 1 (Block 1 (004000-007FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit Block 2 (Block 2 (008000-00BFFFh) not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit Block 3 (Block 3 (00C000-00FFFFh) not protected from table reads executed in other blocks)
#pragma config EBTR4 = OFF      // Table Read Protection bit Block 4 (Block 4 (010000-013FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR5 = OFF      // Table Read Protection bit Block 5 (Block 5 (014000-017FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR6 = OFF      // Table Read Protection bit Block 6 (Block 6 (018000-01BFFFh) not protected from table reads executed in other blocks)
#pragma config EBTR7 = OFF      // Table Read Protection bit Block 7 (Block 7 (01C000-01FFFFh) not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot Block (000000-007FFF, 000FFF or 001FFFh) not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.



// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#define _XTAL_FREQ 10000000 
#define Play_Back_ON PORTBbits.RB0



uint8_t Voltage_Drop =0,Current=0,Resistor=0;

int Sample [50];
char text[2]="\r ";
uint8_t b[3];
uint8_t EEPROM_W=0;
uint8_t Sample_Number=0;
uint8_t  EEPROM_address =0;
int a=0;
int x=0;
uint8_t result_EEPROM=0;
uint8_t EEPROM_read [50];
int Sample_for_Average [50];
int Average=0;
char Keyboard=0;

void Initialize_Analog(void);
void Analog_Capture_ON(void); //Subroutine in charge of reading analog input
void Analog_Capture_OFF(void);// Turn OFF analog input before calling Play_Back
void Initialize_UART(void);//
void Read_UART_Input (); // Read keyboard
void Send_to_UART ();
void EEPROM_Write(uint8_t,uint8_t[]);
void EEPROM_Read(uint8_t); 
void Half_Hour_Tick ();
void EEPROM_test (); //Test Write and Read function 
void Average_Function ();//Calculate Average off 50 last points.


void main( void )
{
         RCONbits.RI=0; 
        TRISD=0x00;
        TRISA=0xFF;
        Initialize_UART(); 
        sprintf(b,"Acquisition in progress please wait: \n");
        Send_to_UART();
        Initialize_Analog();
        Analog_Capture_ON ();
        
        for (int x=0,y=0;x<=50,y<=50;x++,y++)
        { 
        EEPROM_Write(x,Sample[y]); 
        }


while(1)
{
        sprintf(b,"Acquisition completed press S to read or R to reset: \n");
        Send_to_UART();       
        Read_UART_Input();
        if(Keyboard=='R')
        {
         RCONbits.RI=1;   
        }

        if(Keyboard=='S') 
        {
        sprintf(b,"Please wait...... \n");
        Send_to_UART();    
        Analog_Capture_OFF();
       
        
        for(int x=0;x<=50;x++){
        
        EEPROM_Read(x);
        
        int i =0;
        i++;
        sprintf(b,"Sampling number %d: %d mA :\n",x,result_EEPROM);
        
        Send_to_UART();
        }
        
        
            
        int i =0;
        i++;
        sprintf(b,"Average of last 50 Samples: %d mA \n",Average);
        
        Send_to_UART();   
 
        

        }
//        else 
//        {
//        TXSTA1bits.TXEN=0;
//        Analog_Capture_ON();
//        }
        
}

               

}
    
   


void Initialize_UART(){


    TRISCbits.RC7=1;
    TRISCbits.RC6=0;
 
   
//FOSC 10MHz Baud rate 9600
    
    TXSTA1bits.SYNC=0;
    TXSTA1bits.BRGH=0;
    BAUDCON1bits.BRG16=0;
    SPBRG1=15;
    RCSTA1bits.SPEN=1;
    TXSTA1bits.TXEN=1;

 
}

void Read_UART_Input ()
{
    
   RCSTA1bits.CREN=1; //Enable reception
   while(PIR1bits.RC1IF==0);
   Keyboard=RCREG1;
    
    
    
    
    
}





void Send_to_UART ()
{
    
    int i=0;

while (b[i]!='\0')
{
 
    TXREG1=(b[i++]);
    __delay_us(50); //Can't test TXIF immediately after write see AN774 page
    while(PIR1bits.TX1IF==0);
        
}
    
}


void Initialize_Analog(void)
{
    
    //RA0 pot on dev board 10k 
    TRISA=0xff; // port A input
	TRISD=0x00; // port D output
	PORTD=0x00; // port lights off
	PORTA=0x00;
	
	MEMCONbits.EBDIS=1; // make port d digital	
	ADCON0=0b00000001; 
	ADCON1=0b00000000; 	
	ADCON2=0b00000000;
	
		
    
}


void Analog_Capture_ON ()
{
    
    for(int x=0;x<=50;x++)
    {  
    ADCON0bits.GO_DONE=1; // starts conversion
    while(ADCON0bits.GO_DONE==1); // wait, for convertion to end
    Sample[x]=ADRESH;
    Initialize_Analog;
    __delay_ms(500);
    if(x==50)
    {
        x=51;
    }
    }  
    
}

void Analog_Capture_OFF ()
{
    ADCON0bits.ADON=0; //Analog module OFF
    
    
    
}





void EEPROM_Write (uint8_t address,uint8_t value [])
{

    
   
    
    EECON1bits.WREN=1;
    EEADR=address ;
    EEDATA=value;
    EECON1bits.EEPGD=0;// access EEPROM data memory
    EECON1bits.CFGS=0;
    INTCONbits.GIE=0;
    //Required sequence from data sheet
   
    EECON2=0x55;
    EECON2=0xAA;
    EECON1bits.WR=1;
    
    //*************************************
    INTCONbits.GIE=1;
    while(EECON1bits.WR==1);
    EECON1bits.WREN = 0;
  
}


void EEPROM_Read(uint8_t address)
{
    
    
   
    //EEADRH=EEPROM_address & 0x300;
    
    EEADR=address;
    EECON1bits.EEPGD=0;
    EECON1bits.CFGS=0;
    EECON1bits.RD=1;
    result_EEPROM=EEDATA;
    Sample_for_Average[x++]=result_EEPROM; //Store Sample in Array for Average
    Average_Function();
   
}

void Half_Hour_Tick ()
{
    
    
    for(int x=0;x<=5;x++)
    {
    
    __delay_ms(1000);
    
    }
    
    
}



void EEPROM_test()
{
    
    
    for (int x=0;x<50;x++)
    {
        
        Sample[x]=x;
        
        
        
    }
   
}


void Average_Function ()
{
    
    for(int x=1;x<=50;x++)
    {
    Average +=Sample_for_Average[x];
    
    }
    Average=Average/50;
}