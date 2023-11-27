#define _GLIBCXX_HOSTED 1 // Had to add because of MacOS M1 problems (i'm assuming?)
// #include <bits/stdc++.h> // Compilation time is not counted. So why bother writing all the imports?
#include "../stdc++.h"

using namespace std;

int main(){
    //
    // IO Speed optimizations
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //

    int numCases;
    cin >> numCases;

    while (numCases--){
        int numPoints;
        cin >> numPoints;

        vector<pair<double, double>> points;

        double x, y;
        while(numPoints--){
            cin >> x >> y;
            points.push_back(make_pair(x, y));
        }

        // sort by decreasing x coordinate
        sort(points.begin(), points.end(), greater<pair<double, double>>());

        pair<double, double> prev =  points[0];
        double highest = 0;

        double result = 0;

        for (pair<double, double> p : points){
            // cout << p.first << " " << p.second << endl;
            if (p.second > highest){
                double xDiff = prev.first - p.first;
                double yDiff = p.second - prev.second;

                double percentage = (p.second - highest) / (p.second - prev.second);
                
                // cout<< percentage << endl;
                highest = p.second;
                result += sqrt(xDiff * xDiff + yDiff * yDiff) * percentage;
            }
            prev = p;
        }

        cout << fixed << setprecision(2) << result << endl;

    }
    
    return 0;
}
