class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiantQ, direQ;

        int position =0;
        for(;position<senate.size();position++){
            char senator = senate[position];
            if(senator == 'R') radiantQ.push(position);
            if(senator == 'D') direQ.push(position);
        }

        while(!radiantQ.empty() && !direQ.empty()){
            // dono ko pop karao
            int rFront = radiantQ.front();
            radiantQ.pop();

            int dFront = direQ.front();
            direQ.pop();

            if(rFront< dFront){
                // R will ban D
                radiantQ.push(position++);
            }

            else{
                //D will ban R
                direQ.push(position++);
            }
        }
        if(!radiantQ.empty()) return "Radiant";
        else{
            return "Dire";
        }
    }
};