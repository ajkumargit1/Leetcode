class Solution {
public:
    long long minimumCost(string a, string b, int flipCost, int swapCost,
                          int crossCost) {

        long long onesInA = 0, onesInB = 0;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b[i])
                continue;
            onesInA += (a[i] == '1');
            onesInB += (b[i] == '1');
        }

        if (onesInA == onesInB) {
            return min(2LL * onesInA * flipCost, 1LL * onesInA * swapCost);
        }

        long long paired = min(onesInA, onesInB);
        long long costPairs =
            min(2LL * paired * flipCost, 1LL * paired * swapCost);

        long long remaining = llabs(onesInA - onesInB);

        long long costRemaining =
            min(1LL * remaining * flipCost,
                1LL * (remaining / 2) * (swapCost + crossCost) +
                    1LL * (remaining % 2) * flipCost);

        return costPairs + costRemaining;
    }
};
