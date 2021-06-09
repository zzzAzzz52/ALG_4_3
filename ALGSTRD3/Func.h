#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in;
int a = 10000000;
float inf = std::numeric_limits<float>::infinity();
const int l = 100;

class Flights
{
private:
    struct info
    {
        string DepartureCity;
        string ArrivalCity;
        int price = a;
    };

public:
    string Departure(string ans1)
    {
        ans1 = "";
        int i, pos;
        char g;
        char l;
        for (i = 0; i < 10000; i++)
        {
            in >> l;
            if (l == '\n')
            {
                cout << "Enter flight details!";
                exit(1);
            }
            if (l == ' ')
            {

            }
            if (l == ';')
            {
                break;
            }
            else
            {
                pos = in.tellg();
                in.seekg(pos - 1);
                in >> g;
                ans1 += g;
            }
        }
        return ans1;
    }

    string Arrival(string ans2) {
        ans2 = "";
        int i, pos;
        char g;
        char l;
        for (i = 0; i < 10000; i++)
        {
            in >> l;
            if (l == ' ')
            {

            }
            if (l == ';')
            {
                break;
            }
            else
            {
                pos = in.tellg();
                in.seekg(pos - 1);
                in >> g;
                ans2 += g;
            }
        }
        return ans2;
    }

    int Prices(int p) {
        p = 0;
        int i, pos, c;
        char l;
        for (i = 0; i < 10000; i++)
        {
            in >> l;
            if (l == '\n')
            {
                break;
            }
            if (l == ' ')
            {

            }
            else
            {
                pos = in.tellg();
                in.seekg(pos - 1);
                in >> c;
                p += c;
                break;
            }
        }
        return p;
    }

    void start()
    {
        in.open("in.txt");
        info graf[l][l] = {};
        working(graf);
        in.close();
    }

    string start2(string ans1)
    {
        in.open("input.txt");
        ans1 = Departure(ans1);
        cout << ans1;
        return ans1;
    }

    int start3(string ans1, string ans2, int p)
    {
        in.open("input.txt");
        ans1 = Departure(ans1);
        ans2 = Arrival(ans2);
        p = Prices(p);
        cout << p;
        return p;
    }

    void working(info graf[][l])
    {
        string ans1, ans2;
        int p = 0, i = 0, j = 0, count = 0;
        while (!in.eof())   //Filling the first column of the matrix
        {
            ans1 = Departure(ans1);
            ans2 = Arrival(ans2);
            p = Prices(p);
            count += 1;
            for (i = 0; i < count; i++)
            {
                if ((graf[i][j].DepartureCity != ""))
                {
                    if ((graf[i][j].DepartureCity == ans1))
                    {
                        break;
                    }
                }

                if ((graf[i][j].DepartureCity == ""))
                {
                    graf[i][j].DepartureCity = ans1;
                    break;
                }
            }
        }
        in.seekg(0);

        int k = 0;
        for (i = 0; i < count; i++) //Matrix size
        {
            if ((graf[i][j].DepartureCity == ""))
            {
                k = count;
                count = i;
                break;
            }
        }

        i = 0;
        for (j = 0; j < count; j++) //Filling the first row of the matrix
        {
            graf[i][j].ArrivalCity = graf[j][i].DepartureCity;
        }

        for (i = 0; i < count; i++) graf[i][i].ArrivalCity = graf[0][i].ArrivalCity; //Filling the matrix diagonally

        for (j = 0; j < count; j++) //Filling by columns of the matrix of the city of arrival
        {
            for (i = 0; i < count; i++)
            {
                if ((graf[i][j].ArrivalCity == ""))
                {
                    graf[i][j].ArrivalCity = graf[j][j].ArrivalCity;
                }
            }
        }

        for (i = 0; i < count; i++) //Filling in the lines of the matrix of the city of departure
        {
            for (j = 0; j < count; j++)
            {
                if ((graf[i][j].DepartureCity == ""))
                {
                    graf[i][j].DepartureCity = graf[i][i].ArrivalCity;
                }
            }
        }

        while (!in.eof()) //Filling in the matrix with flight prices
        {
            ans1 = Departure(ans1);
            ans2 = Arrival(ans2);
            p = Prices(p);
            j = 0;
            for (i = 0; i < count; i++)
            {
                if ((graf[i][j].DepartureCity == ans1))
                {
                    for (j = 0; j < count; j++)
                        if ((graf[i][j].ArrivalCity == ans2))
                        {
                            graf[i][j].price = p;
                            break;
                        }
                }
            }
        }
        in.seekg(0);

        for (i = 0; i < count; i++) graf[i][i].price = 0; //Filling the matrix diagonally with zeros

        cout << "Price matrix between cities:" << endl;

        for (i = 0; i < count; i++)
        {
            for (j = 0; j < count; j++)
            {
                if (graf[i][j].price >= a)
                {
                    cout << inf << "\t";
                }
                else
                {
                    cout << graf[i][j].price << "\t";
                }
            }cout << endl;
        }

        cout << "\nThe matrix of shortest prices between cities:" << endl;
        for (k = 0; k < count; k++)
            for (i = 0; i < count; i++)
                for (j = 0; j < count; j++)
                    if (graf[i][k].price && graf[k][j].price && i != j)
                        if (graf[i][k].price + graf[k][j].price < graf[i][j].price || graf[i][j].price == 0)
                            graf[i][j].price = graf[i][k].price + graf[k][j].price;

        for (i = 0; i < count; i++)
        {
            for (j = 0; j < count; j++) cout << graf[i][j].price << "\t";
            cout << endl;
        }

        string dep;
        string arr;
        cout << "\nEnter the city of departure: " << endl;
        getline(cin, dep);
        cout << "Enter the city of arrival: " << endl;
        getline(cin, arr);
        while (!in.eof())
        {
            ans1 = Departure(ans1);
            ans2 = Arrival(ans2);
            p = Prices(p);
            for (i = 0; i < count; i++)
            {
                for (j = 0; j < count; j++)
                {
                    if ((graf[i][j].DepartureCity == dep) && (graf[i][j].ArrivalCity == arr))
                    {
                        if ((graf[i][j].price == 0) || (graf[i][j].price > a)) {
                            cout << "\nNo flight from " << dep << " to " << arr << endl;
                            exit(1);
                        }
                        else {
                            cout << "\nThe cheapest flight from " << dep << " to " << arr << " is " << graf[i][j].price << endl;
                            exit(1);
                        }
                    }
                }
            }
        }
    }
};
