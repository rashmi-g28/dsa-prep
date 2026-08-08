/*


Today you decided to go to the gym. You currently have E energy. There are N exercises in the gym. Each of these exercises drains Ai amount of energy from your body. You feel tired if your energy reaches 0 or below. Calculate the minimum number of exercises you have to perform such that you become tired. Every unique exercise can only be performed at most 2 times (as others also have to use the machines). If performing all the exercises does not make you feel tired, return -1.

Parameters:

E :: INTEGER — Energy. 1 ≤ E ≤ 10^5
N :: INTEGER — number of exercises. 1 ≤ N ≤ 10^5
A :: INTEGER ARRAY — A[i] = energy drained by ith exercise. 1 ≤ A[i] ≤ 10^5

Test Cases:

Case 1:
Input: E=6, N=2, A=[1,2]
Output: 4
Explanation: Do exercise 1 twice, exercise 2 twice → total 4 exercises → energy drained = 1+1+2+2=6 ≥ E.

Case 2:
Input: E=10, N=2, A=[1,2]
Output: -1
Explanation: Max possible drain with 2 reps each = 1+1+2+2=6 < 10. Never gets tired.

Case 3:
Input: E=2, N=3, A=[1,5,2]
Output: 1
Explanation: Using exercise 3 once (drains 2) already reaches E=2. Minimum exercises = 1.
*/

int minExercises(int E, int N, vector<int>& A) {
    int n=A.size(),count=0,sum=0;
    sort(A.begin(),A.end());
    for(int i=n-1;i>=0;i--){
        int chk=1;
        sum+=A[i];
        count++;
        while(sum<E && chk<2){
            sum+=A[i];
            count++;
            chk++;
        }
        if(sum>=E){
            return count;
        }
    }
    return -1;  
}