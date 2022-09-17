// 2409. Count Days Spent Together

Approach 
count the number of days from 00 to the given date and then return the overlapping days

common days can be found between max(both arrivals) and min(both leaves)
  
 // code
  
  class Solution {
    int months[13] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int convert(string &date)
    {
        int mon = (date[0]-'0')*10 + (date[1]-'0');
        int day = (date[3]-'0')*10 + (date[4]-'0');
        int days = 0;
        for(int i = 1; i < mon; i++)
        {
            days += months[i];
        }
        days += day;
        return days;
    }
public:
    int countDaysTogether(string aA, string lA, string aB, string lB) {
        // date to number of days conversion
        int arrivalA = convert(aA);
        int leaveA = convert(lA);
        int arrivalB = convert(aB);
        int leaveB = convert(lB);
        
        int arrival = max(arrivalA, arrivalB);
        int leave = min(leaveA, leaveB);
        
        if(arrival > leave)
            return 0;
        return leave-arrival+1;
    }
};
