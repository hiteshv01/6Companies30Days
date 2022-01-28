class Solution {
public:
    bool winnerOfGame(string colors) {
       int n = colors.size()  ;
      int ascore = 0 ;
      int bscore =0 ;
      for(int i=1;i<=n-2 ; i++)
      {
        if(colors[i] =='A' and colors[i] ==colors[i+1] and colors[i] ==colors[i-1])
            ascore ++ ;
        else if(colors[i] =='B' and colors[i] ==colors[i+1] and colors[i] ==colors[i-1])
            bscore ++ ;
      }
     
      return (ascore > bscore) ;
    }
};