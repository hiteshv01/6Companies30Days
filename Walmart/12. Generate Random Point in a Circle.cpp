class Solution {
public:
    double r,x,y ;
    Solution(double radius, double x_center, double y_center) {
        
        r = radius ;
        x  = x_center ;
        y =  y_center ;
    }
    
    vector<double> randPoint() {
        vector<double> v ;
        double length ;
        double theta ;
        
        double random  =  (double) rand() / RAND_MAX ;
        theta = random * 2 * 3.14159 ;
        
         double random2 =  (double) rand() / RAND_MAX ;
         length = sqrt(random2) * r ;
        
        double x_r = x + length*cos(theta) ;
        double y_r = y + length * sin(theta) ;
        
        v.push_back(x_r) ;
        v.push_back(y_r) ;
        
        return v ;
        
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */