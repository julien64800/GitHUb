
#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "Config.h"

#define _XTAL_FREQ 10000000 




uint8_t Voltage_Drop =0,Current=0,Resistor=0;

uint8_t Sample [50]; //Array to stores value from ADRESH
uint8_t b[3];
int a=0;
int x=0;
uint8_t result_EEPROM=0;
uint8_t EEPROM_read [50];
uint8_t Sample_for_Average [50];
uint8_t Average=0;
uint8_t Keyboard=0;

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
        
        for (uint8_t  x=0,y=0;x<=50,y<=50;x++,y++)
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
         asm("CLRF PCLATH");//Clear program counter (instruction pointer)
         asm ("GOTO 0"); //Jump at memory location 0  
        }
        
        if(Keyboard=='S') 
        {
        Send_to_UART();    
        Analog_Capture_OFF();
        for(int x=0;x<=50;x++)
        {
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
}             
}
    
   
void Initialize_UART()
{
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
	
	//MEMCONbits.EBDIS=1; // make port d digital	Can't be used in MCU mode
	ADCON0=0b00000001; 
	ADCON1=0b00000000; 	
	ADCON2=0b00000000;
 
}


void Analog_Capture_ON ()
{
    
    for(int x=0;x<=50;x++)
    {  
    ADCON0bits.GO_DONE=1; // start conversion
    while(ADCON0bits.GO_DONE==1); // wait, for conversion to end
    Sample[x]=ADRESH;
    Initialize_Analog; // Need to reinitialize ADC after each Sample see data sheet p275
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