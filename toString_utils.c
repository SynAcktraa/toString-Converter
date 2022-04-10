
int power(int base, int p){ 
   int result = 1;
   if(p){ 
      for(int i = p; i > 0; i--){ 
         result *= base;
      }
      return result;
   }
   else{
      return result;
   }
}


int isDigit(int ch){
   if(ch >= 48 && ch <= 57)
      return 1;
   return 0;
}


int Strlen(char *str){
   int cnt = 0;
   while(*str != '\0'){ 
         cnt++; 
         str++; 
   }
   return cnt;
}

int AtoI(const char* str){ 
   int res = 0;
   char *ptr = (char*)str;

   while (*ptr != '\0') {
      if (isDigit(*ptr)) {
         res *= 10; 
         res += *ptr - 48;

      }
      ptr++;
   }
   return res;
}


void reverse(char*str){
   
   int len = 0;
   char*ptr = str;
   while(*ptr != '\0'){
      len++;
      ptr++;
   }
   int i = 0, j = len-1;
   while(i < j){
      char temp  = *(str+i);
      *(str+i) = *(str+j);
      *(str+j) = temp;
      ++i;
      --j;
   }
}


void ItoA(int dec, char*dest){
   int i = 0;
   if(dec == 0){dest[i++] = 48;}
   else{
   while(dec){
         dest[i++] = (dec%10) + 48;
         dec /= 10;
      }
   *(dest+i) = '\0';
   reverse(dest);
   }
}


int octToDec(int n){
    int dec = 0, oct = n, count = 0;

    while(oct){ 
        count++; 
        oct = oct/10; 
    }

    oct = n; 
    for(int i = 0; i <= count; i++){
        dec += (oct % 10) * power(8, i); 
        oct = oct/10; 
    }

    return dec;
}

int hexToDec(char* h){ 

    int dec = 0, bitshift = 0, cnt = 0;
    char* ptr = h; 

    while(*ptr != '\0'){ 
        cnt++; 
        ptr++; 
    }

    while(cnt >= 0){ 
        --cnt;
        if((*(h+cnt) >=97 && *(h+cnt) <=102)) 
            dec += (*(h+cnt)-87)*power(16, bitshift); 
        else if((*(h+cnt) >=65 && *(h+cnt) <=70)) 
            dec += (*(h+cnt)-55)*power(16, bitshift); 
        else if((*(h+cnt) >=48 && *(h+cnt) <=57)) 
            dec += (*(h+cnt)-48)*power(16, bitshift);; 
        bitshift++; 
    }

    return dec;
}


int binToDec(char* binary){ 
    
    int i = 0, j, k;
    int dec = 0;
    while(*(binary+i) != '\0'){
        ++i;
    }

    for(j = i-1, k = 0; j >= 0; --j, ++k)
        dec += (*(binary+k)-48)*power(2,j); 

    return dec;
}
