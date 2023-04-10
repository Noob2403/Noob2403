#define keypad5x5_h 

#define HANG_A input(PIN_B0)
#define HANG_B input(PIN_B1) 
#define HANG_C input(PIN_B2) 
#define HANG_D input(PIN_B3) 
#define HANG_E input(PIN_B4) 

#define COT_1 PIN_C0
#define COT_2 PIN_C1
#define COT_3 PIN_C2
#define COT_4 PIN_C3
#define COT_5 PIN_C4

void _KhoiTaoBanPhim (void) ;
int1 _CoPhimNhaHayChua (void) ;
void _QuetCot(char TenCot) ;
char _QuetPhimNhan (void) ;

void _KhoiTaoBanPhim (void) {
   output_bit(COT_1,1) ;
   output_bit(COT_2,1) ;
   output_bit(COT_3,1) ;
   output_bit(COT_4,1) ;
   output_bit(COT_5,1) ;
}

int1 _CoPhimNhaHayChua (void) {
   output_bit(COT_1,0) ;
   output_bit(COT_2,0) ;
   output_bit(COT_3,0) ;
   output_bit(COT_4,0) ;
   output_bit(COT_5,0) ;
   
   if(HANG_A == 0) return 1 ;
   if(HANG_B == 0) return 1 ;
   if(HANG_C == 0) return 1 ;
   if(HANG_D == 0) return 1 ;
   if(HANG_E == 0) return 1 ;
   
   return 0;
   
}

void _QuetCot (char TenCot) {
   output_bit(COT_1,1) ;
   output_bit(COT_2,1) ;
   output_bit(COT_3,1) ;
   output_bit(COT_4,1) ;
   output_bit(COT_5,1) ;
   
   switch(TenCot) {
      case 1 : {
         output_bit(COT_1,0) ;
         break ;
      }
      case 2 : {
         output_bit(COT_2,0) ;
         break ;
      }
      case 3 : {
         output_bit(COT_3,0) ;
         break ;
      }
      case 4 : {
         output_bit(COT_4,0) ;
         break ;
      }
      case 5 : {
         output_bit(COT_5,0) ;
         break ;
      }
   }
}

char _QuetPhimNhan(void) {
   char TenCot ; 
   char MaPhim[5][5] = {
      {'S','C','T','O','A'},
      {'7','8','9','/','R'},
      {'4','5','6','X','^'},
      {'1','2','3','-','D'},
      {'F','0','=','+','A'}
   } ;
   
   if(_CoPhimNhaHayChua() == 1) {
      delay_ms(10) ;
      if(_CoPhimNhaHayChua() == 1) {
         for(TenCot=0 ; TenCot <=4;TenCot++) {
            _QuetCot(TenCot+1) ;
            if(HANG_A == 0) return MaPhim[0][TenCot] ;
            if(HANG_B == 0) return MaPhim[1][TenCot] ;
            if(HANG_C == 0) return MaPhim[2][TenCot] ;
            if(HANG_D == 0) return MaPhim[3][TenCot] ;
            if(HANG_E == 0) return MaPhim[4][TenCot] ;
         }
      
      }
   
   }
   else {
      return 'a' ;
   }

}
