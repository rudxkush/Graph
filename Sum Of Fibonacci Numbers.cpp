int Solution::fibsum(int A) {
    // Step 1: Generate all Fibonacci numbers <= A
    vector<int> fib;
    fib.push_back(1);
    fib.push_back(2);
    
    while (fib.back() <= A) {
        int n = fib.size();
        fib.push_back(fib[n-1] + fib[n-2]);
    }
    
    // Step 2: Greedily subtract largest fib <= A
    int count = 0;
    int i = fib.size() - 1;
    while (A > 0) {
        if (fib[i] <= A) {
            A -= fib[i];
            count++;
        }
        i--;
    }
    
    return count;
}
