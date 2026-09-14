class Solution {
  public:
    int minSteps(int d) {
        // code here
        int sum=0;
        int i=0;
        while(sum<d){
            ++i;
            sum+=i;
        }
        while((sum-d)%2!=0){
            i++;
            sum += i;
        }
        return i;
    }
};