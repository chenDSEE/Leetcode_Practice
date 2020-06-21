/* Memoization */
class Solution {
public:
    int fib(int N) {
        record.emplace_back(0);
        record.emplace_back(1);
        return fib_recusion(N);
    }
    
private:
    vector<int> record;

    int fib_recusion(int N) {
        if (record.size() - 1 < N) {
            record.emplace_back(fib_recusion(N - 1) + fib_recusion(N - 2));
        }

        return record[N];
    }
};

/* Dynamic Programming */
class Solution {
public:
    int fib(int N) {
        if (N <= 1)
            return N;

        int f1 = 0, f2 = 1, f3 = 0;
        for (int cnt = 2; cnt <= N; cnt++) {
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
            // b = a + b; a = b - a;
        }

        return f3;
    }
};