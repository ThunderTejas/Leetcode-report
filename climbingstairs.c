int climbStairs(int n){
        int a = 0 , b = 1 , c;
           for(int i = 0 ; i<= n ; i++){
                c = a+b;
                b = a;
                a = c;
            }
        return c;
}

   
