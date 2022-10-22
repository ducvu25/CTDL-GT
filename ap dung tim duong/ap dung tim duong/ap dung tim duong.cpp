#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;
struct Point {
    double x;
    double y;
};
float** inputList(char* s, int& n, int& m, Point* &A, int& start, int* &end, int& nEnd) {
    int x, y;
    ifstream cin(s);
    cin >> n >> m;
    A = new Point[n];
    for (int i = 0; i < n; i++) {
        double x, y;
        int z;
        cin >> x >> y >> z;
        A[z].x = x;
        A[z].y = y;
    }
    float** a = new float* [n];
    for (int i = 0; i < n; i++)
        a[i] = new float[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = 0;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        cin >> a[x][y];
    }
    cin >> start >> nEnd;
    end = new int[nEnd];
    for (int i = 0; i < nEnd; i++)
        cin >> end[i];
    return a;
}
int nE(int** a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i][j] != 0 || a[j][i] != 0)
                count++;
    return count;
}
void out(float** a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << fixed << setprecision(2) << a[i][j] << " ";
        cout << endl;
    }
}
void init(int* check, int n) {
    for (int i = 0; i < n; i++)
        check[i] = 0;
}
int LineXMin(int start, int x, float** a, int n, ofstream& cout) {
    // tao value
    float* value = new float[n];
    int* dad = new int[n];
    float min;
    int index;
    for (int i = 1; i < n; i++) {
        value[i] = a[start][i];
        if (value[i] != 0)
            dad[i] = 0;
    }
    value[start] = -1;

    while (1) {
        // tim min
        min = -1;
        index = -1;
        for (int i = 0; i < n; i++)
            if (value[i] > 0 && (value[i] < min || min == -1)) {
                min = value[i];
                index = i;
            }
        if (index == x || index == -1)
            break;
        value[index] = -1;
        // sau khi tim dc min
        for (int i = 0; i < n; i++)
            if (value[i] != -1 && a[index][i] != 0)
                if (value[i] > min + a[index][i] || value[i] == 0) {
                    dad[i] = index;
                    value[i] = min + a[index][i];
                }
    }
    if (index == x) {
        int line[100];
        int i = 0;
        while (1) {
            line[i++] = index;
            if (index == 0)
                break;
            index = dad[index];
        }
        i--;
        for (; i > 0; i--)
            cout << line[i] << " -> ";
        cout << x << endl;
        cout << "Length = " << min << endl;
        return 1;
    }
    else
        cout << "Unable to go " << x << endl;
    return 0;
}
void LineXMax(int start, int x, float** a, int n, int DadMAX[2][100], int* nDad, float &lengthMax, int* check) {
    DadMAX[1][nDad[1]] = start;
    nDad[1]++;
    check[start] = 1;
    if (start == x) {
        int sum = 0;
        for (int i = 0; i < nDad[1] - 1; i++)
            sum += a[DadMAX[1][i]][DadMAX[1][i+1]];
        if (lengthMax < sum) {
            lengthMax = sum;
            nDad[0] = nDad[1];
            for (int i = 0; i < nDad[1]; i++)
                DadMAX[0][i] = DadMAX[1][i];
        }
        return;
    }
    for (int i = 0; i < n; i++)
        if (a[start][i] != 0 && check[i] == 0 && check[x] == 0) {
            LineXMax(i, x, a, n, DadMAX, nDad, lengthMax, check);
            check[i] = 0;
            nDad[1]--;
        }
}
int main() {
    int n, m, start, nEnd;
    int* end;
    Point* A;
    char input[100]; //= "./input.txt";
    cout << "Enter link file: ";
    cin >> input;
    float** a = inputList(input, n, m, A, start, end, nEnd);
    ofstream cout("./a3-sample.txt");
    cout << "The graph: " << n << " vertices and " << m << " edges\n";
    for (int i = 0; i < nEnd; i++) {
        cout << "\nStart: " << start << ", goal vertice: " << end[i] << endl;
        cout << "The Euclidean distance: "
            << fixed << setprecision(2) << sqrt(pow(A[start].x - A[end[i]].x, 2)
                + pow(A[start].y - A[end[i]].y, 2)) << endl;
        cout << "Line min:\n";
        int d = LineXMin(start, end[i], a, n, cout);
        
        cout << "Line max:\n";
        if (d == 1) {
            int DadMAX[2][100];
            int nDad[2]; nDad[1] = 0;
            float lengthMax = -1;
            int* check = new int[n];
            for (int t = 0; t < n; t++)
                check[t] = 0;
            LineXMax(start, end[i], a, n, DadMAX, nDad, lengthMax, check);
            for (int ii = 0; ii < nDad[0] - 1; ii++)
                cout << DadMAX[0][ii] << " -> ";
            cout << end[i] << endl;
            cout << "Length = " << fixed << setprecision(2) << lengthMax << endl;
        }else
           cout << "Unable to go " << end[i] << endl;
    }
    cout.close();
    return 0;
}
