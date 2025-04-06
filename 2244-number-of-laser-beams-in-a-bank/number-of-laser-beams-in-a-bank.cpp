class Solution {
public:

    // int countDevices(string& binary){
    //     int c=0;
    //     for(auto b: binary){
    //         c += b-'0';
    //     }
    //     return c;
    // }

    // int numberOfBeams(vector<string>& bank) {
    //     vector<int> devices;

    //     for(auto row: bank){
    //         devices.push_back(countDevices(row));
    //     }
    //     int beams=0;
    //     for(int i=0 ;i<devices.size();++i){
    //         int j= i+1;
    //         while(j< devices.size()){
    //             beams+= devices[i] * devices[j];
    //             if(devices[j]== 0){
    //                 j++;
    //             }
    //             else{
    //                 break;
    //             }
    //         }
    //     }
    //     return beams;
    // }
    int countDevices(string& binary){
        int c=0;

        for(int i=0; i<binary.size(); i++){
            c+= binary[i] - '0';
        }
        return c ;
    }

    int numberOfBeams(vector<string>& bank){

        //count the security devices in each row

        int count= 0;
        vector<int>devices;
        for(auto row: bank){
            
            int count = countDevices(row);
            devices.push_back(count);
        }

        //finding out the number of beams present
        for(int i=0; i<devices.size();i++){

            int j= i+1;

            while(j<devices.size()){
                
                count+= devices[i]*devices[j];
                if(devices[j]== 0 ){
                    j++;
                }
                else{
                    break;
                }
            }
        }

        return count;
    }
};