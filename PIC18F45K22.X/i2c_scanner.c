/* Do This First 
 * 1) Download Library picuno.c & picuno.h from https://github.com/kingdiaw/picuno.git
 * 2) Save both picuno.c & picuno.h in Folder PIC18F45K22.X
 * 3) Add picuno.h under Header Files
 * 4) Add picuno.c under Source Files
 * 5) Change to #include "picuno.h"
*/
#include "../../picuno/picuno.h" //<-- Modify Here

char buf[32];

void setup(){
Serial_begin(9600);  
i2c_init(100000);
Serial_println("\nI2C Scanner");
}
void loop(){
  byte error, address;
  int nDevices;
  
Serial_println("Scanning...");
  nDevices = 0;
  for(address = 1; address < 127; address++ )
  {
      i2c_out(address,0x00);
      error = b_i2c_error_flag();
      
      if(error == 0){
          sprintf(buf,"I2C device found at address 0x%.2X!",address);
          Serial_println(buf);
          nDevices++;
      }      
  }
  if (nDevices == 0)
    Serial_println("No I2C devices found\n");
  else
    Serial_println("done\n");
 
  delay(5000);           // wait 5 seconds for next scan  
}