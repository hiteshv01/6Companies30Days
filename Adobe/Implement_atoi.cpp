class Solution {
public:
    int myAtoi(string str) 
    {
        long long  i =0 ;
        int sign = 1;  
        long long result = 0;
      
      // count all the spaces ih the string  in the i variable 
        while(str[i] == ' ')
        {
          i++ ;
        }
      
      // if not a digit 
        if(isdigit(str[i]) == false) 
        {
            if(str[i] == '-') {
              sign = -1 ;
              i++;
            }
            else 
              if(str[i] == '+')
                i++;
        }
      // if it is a digit then traverse the string untill the next non digit char 
    
        while(isdigit(str[i]) == true)
        {
            result = (result*10) + (str[i]-'0');
          
          // cheack for the result is it in the integer range or not ?
            if(result > INT_MAX  ||  result < INT_MIN) 
             {
               return (sign == -1) ? INT_MIN : INT_MAX;
             }
          
        
            i++;
        }
        int num = result * sign  ;
      
        return num ;  
    }
};
