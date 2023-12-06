class Solution {
public:
    int totalMoney(int n) {
        int x=1,sum=0;
        for(int i=0;i<n;i++){
            if(i%7==0){
                x=i/7+1;
            }
            sum+=x;
            x++;
        }
        return sum;
    }
};
