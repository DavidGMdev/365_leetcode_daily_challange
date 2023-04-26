class Solution {
public:
    int addDigits(int num) {
        // at most 3 iterations to go
        while(to_string(num).size() > 1){
            int spare = 0;
            for ( auto & i : to_string(num)) spare += i - '0';
            num = spare;
        }
        return num;
    }
};