class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int totalgas = 0, totalcost = 0;

        for(int i = 0; i < gas.size(); i++) {
            totalgas += gas[i];
        }

        for(int j = 0; j < cost.size(); j++) {
            totalcost += cost[j];
        }

        if(totalgas < totalcost) {
            return -1;
        }

        int start = 0;
        int currgas = 0;

        for(int i = 0; i < gas.size(); i++) {

            currgas += gas[i] - cost[i];    

            if(currgas < 0) {
                start = i + 1;
                currgas = 0;
            }
        }

        return start;
    }
};