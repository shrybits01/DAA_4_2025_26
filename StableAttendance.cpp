//Exp-3 Stable Attendance Window
//A stable attendance window is a continuous period where the number of "Present" and "Absent" records are equal.
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of attendance records: ";
    cin >> n;
    
    unordered_map<int, int> mp;
    int sum = 0;
    int max_length = 0;
    
    //edge case if sum becomes 0.
    mp[0] = -1;
    
    for (int i = 0; i < n; i++) {
        char attendance;
        cout << "Enter the attendance record (P/A) for day: " << endl;
        cin >> attendance;
        
        //if attendance is P then increment sum by 1.
        if (attendance == 'P') {
            sum += 1;
        } else {  //if attendance == 'A'
            sum -= 1;
        }

        if (mp.find(sum) != mp.end()) {
            int length = i - mp[sum];
            max_length = max(max_length, length);
        } else {
            
            mp[sum] = i;
        }
    }
    
    cout << "Maximum length for stable attendance window: " << max_length << endl;
    
    return 0;
}
