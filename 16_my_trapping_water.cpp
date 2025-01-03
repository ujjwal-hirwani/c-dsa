// USP
#include <iostream>
using namespace std;
int find_trapped_water(int builds[], int pos, int size);
int main()
{
    int a[] = {4, 2, 0, 6, 3, 2, 5};
    int n = sizeof(a) / sizeof(int);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += find_trapped_water(a, i, n);
    }
    cout << sum << endl;
    return 0;
}
int find_trapped_water(int builds[], int pos, int size)
{
    int l_max = builds[pos];
    int r_max = builds[pos];
    for (int i = pos - 1; i >= 0; i--)
    {
        if (builds[i] > l_max)
            l_max = builds[i];
    }
    for (int i = pos + 1; i < size; i++)
    {
        if (builds[i] > r_max)
            r_max = builds[i];
    }
    int height = min(l_max, r_max);
    cout << "l max: " << l_max << " r max: " << r_max << " height: " << height - builds[pos] << endl;
    return height - builds[pos];
}
// // USP
// #include <iostream>
// using namespace std;

// int main()
// { //                0  1  2  3  4  5  6  7  8  9  10 11 12 13
//     int builds[] = {4, 2, 0, 6, 3, 2, 5}, size = 7, peak[9];
//     int count = 0;
//     for (int i = 0; i < size; i++)
//     {
//         if (i == 0 && builds[i] > builds[i + 1])
//         {
//             peak[count] = 0;
//             count++;
//         }
//         else if (i == size - 1 && builds[i] > builds[i - 1])
//         {
//             peak[count] = size - 1;
//             count++;
//         }
//         else if ((builds[i] > builds[i + 1]) && (builds[i] > builds[i - 1]))
//         {
//             peak[count] = i;
//             count++;
//         }
//     }
//     for (int i = 1; i < count - 1; i++)
//     {
//         if (builds[peak[i]] < builds[peak[i - 1]] && builds[peak[i]] < builds[peak[i + 1]])
//         {
//             for (int j = i; j < count - 1; j++)
//             {
//                 peak[j] = peak[j + 1];
//             }
//             count--;
//         }
//     }
//     cout << "The peaks are: " << endl;
//     for (int i = 0; i < count; i++)
//     {
//         cout << peak[i] << endl;
//     }
//     int total = 0;
//     for (int i = 0; i < count - 1; i++)
//     {
//         int height = min(builds[peak[i]], builds[peak[i + 1]]), sum = 0;
//         for (int j = peak[i] + 1; j < peak[i + 1]; j++)
//         {
//             if (height - builds[j] >= 0)
//             {
//                 sum += (height - builds[j]);
//             }
//         }
//         total += sum;
//     }
//     cout << "Total water trapped: " << total << endl;
//     return 0;
// }