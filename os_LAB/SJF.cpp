#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int bt[20], at[10], n, i, j, temp, st[10], ft[10], wt[10], ta[10];
    int totwt = 0, totta = 0;
    double awt, ata;
    string pn[10], t;
    cout << "Enter the number of process:";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "Enter process name, arrival time & burst time:";
        cin >> pn[i] >> at[i] >> bt[i];
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (bt[i] < bt[j])
            {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                t = pn[i];
                pn[i] = pn[j];
                pn[j] = t;
            }
        }
    for (i = 0; i < n; i++)
    {
        if (i == 0)
            st[i] = at[i];
        else
            st[i] = ft[i - 1];
        wt[i] = st[i] - at[i];
        ft[i] = st[i] + bt[i];
        ta[i] = ft[i] - at[i];
        totwt += wt[i];
        totta += ta[i];
    }
    awt = (double)totwt / n;
    ata = (double)totta / n;
    cout << "\nProcessname\tarrivaltime\tbursttime\twaitingtime\tturnaroundtime";
    for (i = 0; i < n; i++)
    {
        cout << "\n" << pn[i] << "\t\t" << at[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << ta[i];
    }
    cout << "\nAverage waiting time: " << awt;
    cout << "\nAverage turnaroundtime: " << ata;
    return 0;
}

