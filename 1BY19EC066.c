#include<reg51.h>

/********************************************* LCD control signals declaration ***************************************************/
 
sbit RS = P0^0;     //
sbit RW = P0^1;  // Read/write line
sbit Enable = P0^2; // Enable line
#define LCD_PORT P2 // define port
 
/********************************************* LCD function prototypes ************************************************/
void send_cmd(unsigned char);
void send_char(unsigned char);
void LCD_init(void);
void delayms(unsigned int);
/********************************************* Main Funciton declaration ***********************************************/
void main()
{

LCD_PORT = 0x00; // Make the port as output port
   
LCD_init();            // LCD initialization
  
// while(1)
 //{
  send_cmd(0x83);     // Force cursor to beginning of 1st line, if the number is 0x83 then force the cursor to 53rd position
  delayms(10);    // Delay of 100millisec
  send_char('1');  // Send data 
  send_char('B');  // Send data 
  send_char('Y');  // Send data 
	send_char('1');  // Send data 
  send_char('9');  // Send data 
  send_char('E');  // Send data 
	send_char('C');  // Send data 
	send_char('0');  // Send data 
	send_char('6');  // Send data 
  send_char('6');  // Send data  
  send_cmd(0xC3);     // Force cursor to beginning of 2nd line
   delayms(10);    // Delay of 100millisec 
  send_char('J');  // Send data 
  send_char('A');  // Send data 
  send_char('S');  // Send data 
  send_char('W');  // Send data 
	send_char('A');  // Send data
	send_char('N');  // Send data
	send_char('T');  // Send data
	send_char('H');  // Send data
	send_char(' ');  // Send data
	send_char('S');  // Send data                   
 //}
}
 
 
/********************************************* LCD Initialization Function declaration ********************************/
 
void LCD_init()
{
 send_cmd(0x38);      // configuring LCD as 2 line 5x7 matrix
 send_cmd(0x0E);      // Display on, Cursor blinking
 send_cmd(0x01);      // Clear Display Screen
 send_cmd(0x06);      // Increment Cursor (Right side)
}
 
void send_char(unsigned char character)
{
 LCD_PORT = character;
 RS = 1;    // Select Data Register
 RW = 0;    // write operation
 Enable = 1;      // High to Low pulse provided on the enable pin with nearly 1ms(>450ns)
 delayms(1);   // 1 millisec delay
 Enable = 0;
 delayms(10);   // 100 millisec delay
}
 
 
/*********************************************LCD Command Sending Function declaration********************************/
 
void send_cmd(unsigned char Command)
{
 LCD_PORT = Command;
 RS = 0;      // Select Command Register
 RW = 0;    // write operation
 Enable = 1;      // High to Low pulse provided on the enable pin with nearly 1ms(>450ns)
 delayms(1);   // 1 millisec delay
 Enable = 0;
}
 

 
/******************************************* delayms Function declaration***********************************************/
void delayms(unsigned int val)
{
 unsigned int i,j;
   
 for(i=0;i<=val;i++)
 {
  for(j=0;j<=2;j++)  ;
  //_nop_();   // no operation produce 1us time delay
 }
  
}