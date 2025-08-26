vector<int> steppingNumbers;

void buildSeq(long long number, int A, int B) {
    if (number > B) 
        return;  
    if (number >= A && number <= B) 
        steppingNumbers.push_back(number);
    if (number == 0) 
        return; 

    int lastDigit = number % 10;
    if (lastDigit > 0)
        buildSeq(number * 10 + (lastDigit - 1), A, B);
    if (lastDigit < 9)
        buildSeq(number * 10 + (lastDigit + 1), A, B);
}

vector<int> Solution::stepnum(int A, int B) {
    steppingNumbers.clear();
    for (int i = 0; i <= 9; i++) {
        buildSeq(i, A, B);
    }
    
    sort(steppingNumbers.begin(), steppingNumbers.end());
    return steppingNumbers;
}
