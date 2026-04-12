class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        vector<double> angle;
        sort(sides.begin(), sides.end());

        double a = sides[0];
        double b = sides[1];
        double c = sides[2];

        if (a + b <= c)
            return angle;

        double cosA = (b*b + c*c - a*a) / (2.0 * b * c);
        cosA = min(1.0, max(-1.0, cosA));
        double A = acos(cosA);

        double cosB = (a*a + c*c - b*b) / (2.0 * a * c);
        cosB = min(1.0, max(-1.0, cosB));
        double B = acos(cosB);

        double cosC = (a*a + b*b - c*c) / (2.0 * a * b);
        cosC = min(1.0, max(-1.0, cosC));
        double C = acos(cosC);

        A = A * 180.0 / M_PI;
        B = B * 180.0 / M_PI;
        C = C * 180.0 / M_PI;

        angle.push_back(A);
        angle.push_back(B);
        angle.push_back(C);

        return angle;
    }
};