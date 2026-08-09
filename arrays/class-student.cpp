/*


Problem Statement:
Dia, Sam, and Robert are three students in the same class. You're given their marks across N subjects. Calculate each student's total score, and determine their rank (1st, 2nd, 3rd) based on total score — higher total score means better rank.

Parameters:

N :: INTEGER — number of subjects. 1 ≤ N ≤ 100
Dia :: INTEGER ARRAY — Dia's marks per subject. 0 ≤ Dia[i] ≤ 100
Sam :: INTEGER ARRAY — Sam's marks per subject. 0 ≤ Sam[i] ≤ 100
Robert :: INTEGER ARRAY — Robert's marks per subject. 0 ≤ Robert[i] ≤ 100

Test Cases:

Case 1:
Input: N=3, Dia=[80,90,70], Sam=[85,80,75], Robert=[90,85,95]
Totals: Dia=240, Sam=240, Robert=270
Output: Robert=1, Dia=2, Sam=3 (Dia and Sam tied — decide how your solution
handles ties, e.g., both could share rank 2, or ordered by name as tiebreaker)

Case 2:
Input: N=2, Dia=[50,50], Sam=[60,60], Robert=[40,40]
Totals: Dia=100, Sam=120, Robert=80
Output: Sam=1, Dia=2, Robert=3
*/

// Online C++ compiler to run C++ program online

vector<int> findRanks(int N, vector<int>& Dia, vector<int>& Sam, vector<int>& Robert) {
    int sum1=0,sum2=0,sum3=0;
    for(int i=0;i<N;i++){
        sum1+=Dia[i];
    }
    for(int i=0;i<N;i++){
        sum2+=Sam[i];
    }
    for(int i=0;i<N;i++){
        sum3+=Robert[i];
    }
    vector<int> result;
    
    if(sum1>sum2){
        if(sum1>sum3){
            sum1=1;
            if(sum2>sum3){
                sum2=2;
                sum3=3;
            }
            else{
                sum3=2;
                sum2=3;
            }
        }
        else{
            sum3=1;
            sum1=2;
            sum2=3;
        }
    }
    else{
        if(sum2>sum3){
            sum2=1;
            if(sum3>sum1){
                sum3=2;
                sum1=3;
            }
            else{
                sum1=2;
                sum3=3;
            }
        }
        else{
            sum3=1;
            sum2=2;
            sum1=3;
        }
    }
    result.push_back(sum1);
    result.push_back(sum2);
    result.push_back(sum3);
    return result;
}