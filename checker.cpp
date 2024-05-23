#include "testlib.h"
#include <iostream>
#include <climits>

using namespace std;

void kadaneOnColumn(int column[], int n, int& numOfDays, int& maxSum) {
    int maxSumTemp = column[0];
    int currentSum = column[0];
    int startIndex = 0;
    int bestStart = 0;
    int bestEnd = 0;

    for (int i = 1; i < n; i++) {
        if (currentSum + column[i] > column[i]) {
            currentSum += column[i];
        } else {
            currentSum = column[i];
            startIndex = i;
        }
        
        if (currentSum > maxSumTemp) {
            maxSumTemp = currentSum;
            bestStart = startIndex;
            bestEnd = i;
        }
    }
    numOfDays = bestEnd - bestStart + 1;
    maxSum = maxSumTemp;
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int n = inf.readInt();
    int m = inf.readInt();

    int matrix[n][m];
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = inf.readInt();
        }
    }

    int maxSumOverall = INT_MIN;
    int maxDaysOverall = 0;
    for (int j = 0; j < m; ++j) {
        int column[n];
        for (int i = 0; i < n; ++i) {
            column[i] = matrix[i][j];
        }

        int numOfDays, maxSum;
        kadaneOnColumn(column, n, numOfDays, maxSum);

        if (maxSum > maxSumOverall) {
            maxSumOverall = maxSum;
            maxDaysOverall = numOfDays;
        }
    }

    int contestantDays = ouf.readInt();
    int contestantMaxSum = ouf.readInt();

    if (contestantDays != maxDaysOverall || contestantMaxSum != maxSumOverall) {
        quitf(_wa, "Wrong answer. Expected days: %d, max sum: %d. Found days: %d, max sum: %d.",
              maxDaysOverall, maxSumOverall, contestantDays, contestantMaxSum);
    }

    quitf(_ok, "OK");
}

