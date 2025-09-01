int daysPerMonth[13];

void setupLeapYear(int yr) {
    if (yr % 400 == 0) {
        daysPerMonth[2] = 29;
    } else if (yr % 100 == 0) {
        daysPerMonth[2] = 28;  
    } else if (yr % 4 == 0) {
        daysPerMonth[2] = 29;
    } else {
        daysPerMonth[2] = 28;
    }
}

void initializeMonths() {
    daysPerMonth[1] = 31;
    daysPerMonth[2] = 28;
    daysPerMonth[3] = 31;
    daysPerMonth[4] = 30;
    daysPerMonth[5] = 31;
    daysPerMonth[6] = 30;
    daysPerMonth[7] = 31;
    daysPerMonth[8] = 31;
    daysPerMonth[9] = 30;
    daysPerMonth[10] = 31;
    daysPerMonth[11] = 30;
    daysPerMonth[12] = 31;
}

int countLuckyDates(int day1, int mon1, int year1, int day2, int mon2, int year2) {
    initializeMonths();
    int totalCount = 0;
    
    while (1) {
        int concatenatedNum = day1;
        concatenatedNum = concatenatedNum * 100 + mon1;
        concatenatedNum = concatenatedNum * 10000 + year1;
        
        if (concatenatedNum % 4 == 0 || concatenatedNum % 7 == 0) {
            totalCount++;
        }
        
        if (day1 == day2 && mon1 == mon2 && year1 == year2) {
            break;
        }
        
        setupLeapYear(year1);
        day1++;
        
        if (day1 > daysPerMonth[mon1]) {
            day1 = 1;
            mon1++;
            if (mon1 > 12) {
                mon1 = 1;
                year1++;
            }
        }
    }
    
    return totalCount;
}

int main() {
    char inputLine[50];
    int startDay, startMonth, startYear, endDay, endMonth, endYear;
    
    fgets(inputLine, sizeof(inputLine), stdin);
    
    sscanf(inputLine, "%d-%d-%d %d-%d-%d", 
           &startDay, &startMonth, &startYear, 
           &endDay, &endMonth, &endYear);
    
    int result = countLuckyDates(startDay, startMonth, startYear, 
                                endDay, endMonth, endYear);
    
    printf("%d\n", result);
    
    return 0;
}
