#include <main.h>
#include <keypad5x5.h>
#include <lcd.h>
#include <math.h>

float _CharToNumber (Char Key)
{  return(Key - '0');
}
float entering_value = 0 ;
float first_value = 0 ;
char flat ;
void _ReturnStart (void) ;
void main()
{
    char Key = 'a' ;
    lcd_init() ; //khoi tao lcd
    lcd_putc('\f') ;//xoa trang man hinh lcd put char
    
    _KhoiTaoBanPhim() ;
    
    lcd_gotoxy(1,1) ;
    printf(lcd_putc,"Calculator") ;
    lcd_gotoxy(1,2) ;
    printf(lcd_putc,Key) ;
    delay_ms(1000) ;
    lcd_putc('\f') ;
    float entering_value = 0 ;
    float first_value = 0 ;
    lcd_gotoxy(1, 1);
    
    while(TRUE)
    {
       Key = _QuetPhimNhan();
       if(Key != 'a')
       {
          if(Key == 'F')
          {
             _ReturnStart();
         }
      }
      if (Key >= '0' && Key <= '9')
      {
         lcd_putc(Key);
         entering_value = entering_value*10 + _CharToNumber(Key);
      }
      if(Key == '+' || Key == '-' || Key == 'x' || Key == '/' || Key == '^' || Key == 'D')
      {
         lcd_putc(Key);
         first_value = entering_value;
         entering_value = 0;
         flat = Key;
         float can_bac_2 = Key;
         
      }
      if(Key == '=')
      {
         lcd_putc(Key);
         lcd_gotoxy(1, 2);
         if(entering_value == 0)
         {
            printf(lcd_putc,"Nhap Lai");
         }
         switch(flat)
         {
             case '+':
               printf(lcd_putc,"%.0f", first_value + entering_value);
             break;
             case '-':
               printf(lcd_putc,"%.0f", first_value - entering_value);
             break;
             case 'x':
               printf(lcd_putc,"%.0f", first_value * entering_value);
             break;
             case '/':
                if(entering_value == 0)
                {
                   printf(lcd_putc,"Error");
                
               }
               else
               
               {
                   float tru;
                   tru = first_value / entering_value;
                   printf(lcd_putc,"%.3f",tru);
               }
            break;
            case '^':
               if(entering_value == 0)
               {
                  printf(lcd_putc,"1");
               }
               else
               {
                  printf(lcd_putc,"%.3f", pow(first_value, entering_value));
               }
            break;
            case 'D':
                printf(lcd_putc,"%.3f", sqrt(can_bac_2));
            break;
            
            default:
                printf(lcd_putc,"Nhap Lai");
            break;
            
                
             
         }
      }
      while(Key != 'a')
      {
         Key = _QuetPhimNhan();
      }
   
      
   }
               

   
}
void _ReturnStart()
{
   lcd_putc('\f');
   lcd_gotoxy(1, 1);
   entering_value = 0;
   first_value = 0;
   flat = 'a';
   
}
