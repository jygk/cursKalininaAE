#include <locale>
#include <iostream>
#include <iomanip>
#include <math.h>
#include "fun.h"
#include <string>

const float phi = (sqrt(5) + 1) / 2;
const long double del = 0.00000000000001;
const long double del2 = 0.0000000001;
using namespace std;
long double DecToFeb(int n)
{
    long double result = 1.00;
    int i = 1;
    while (i < n)
    {
        if (i == 1)
        {
            result = 10.01000000000;
            i++;
        }
        else
        {
            if (int(floor(result)) % 2 == 1)
                result = unbalance(result);
            result += 1;
            result = balance(result);
            i++;

        }
    }
    return result;

}
int FebToDec(long double res)
{

    long double result = res, nn = 0;
    string r = to_string(res);
    int i = 0, n = 0, p;
    p = r.find(',', 0);
    while (r[i] != NULL)
    {
        if (r[i] == '1')
            nn = nn + pow(phi, p - i - 1);
        i++;
    }
    n = int(round(nn));
    return n;

}
long double balance(long double  res)
{
    string r;
    r = to_string(res);
    int p, k;
    r = "000" + r;
    while (1)
    {
        k = 0;
        p = r.find("011", 0);
        if (p != -1)
        {
            r.replace(p, 3, "100");
            k = 1;
        }
        p = r.find("01,1", 0);
        if (p != -1)
        {
            r.replace(p, 4, "10,0");
            k = 1;
        }
        p = r.find("0,11", 0);
        if (p != -1)
        {
            r.replace(p, 4, "1,00");
            k = 1;
        }
        if (k == 0)
            break;
    }
    k = 0;
    int count = 0;
    while ((r[k] == '0') && (r[k + 1] != NULL))
    {
        count++;
        k++;
    }
    r.erase(0, count);
    res = stold(r);
    res += del;
    return res;
}

long double unbalance(long double  res)
{
    string r;
    r = to_string(res);
    r = r + "000";
    int count = 0;
    int p, k;
    while (1)
    {
        k = 0;
        p = r.find(",", 0);
        if ((p > 0) && (r[p - 1] == '0'))
            break;
        p = r.find("100", 0);
        if (p != -1)
        {
            r.replace(p, 3, "011");
            k = 1;
        }
        p = r.find(",", 0);
        if ((p > 0) && (r[p - 1] == '0'))
            break;
        p = r.find("10,0", 0);
        if (p != -1)
        {
            r.replace(p, 4, "01,1");
            k = 1;
        }
        p = r.find(",", 0);
        if ((p > 0) && (r[p - 1] == '0'))
            break;
        p = r.find("1,00", 0);
        if (p != -1)
        {
            r.replace(p, 4, "0,11");
            k = 1;
        }
    }
    res = stold(r);
    res += del;

    return res;
}
long double unbalance2(long double  res)
{
    string r;
    r = to_string(res);
    r = r + "000";
    int count = 0;
    int p, k;
    while (1)
    {
        k = 0;
        p = r.find("100", 0);
        if (p != -1)
        {
            r.replace(p, 3, "011");
            k = 1;
        }
        p = r.find("10,0", 0);
        if (p != -1)
        {
            r.replace(p, 4, "01,1");
            k = 1;
        }
        p = r.find("1,00", 0);
        if (p != -1)
        {
            r.replace(p, 4, "0,11");
            k = 1;
        }
        if (k == 0)
            break;
    }
    res = stold(r);
    res += del;

    return res;
}
long double blc(long double  res)
{
    string r;
    int p, c;
    r = to_string(res);
    r = r + "00";
    while (1)
    {
        p = r.find('2', 0);
        if (p == -1)
            break;
        if (p == 0)
        {
            if (r[p + 2] == '0')
                r.replace(0, 3, "001");
            else
                r.replace(0, 3, "010");
            r = '1' + r;
        }
        else
        {
            if (r[p - 1] == ',')
            {
                if (r[p + 2] == '0')
                    r.replace(p - 2, 4, "1,001");
                else
                    r.replace(p - 2, 4, "1,010");
            }
            if (r[p + 1] == ',')
            {
                if (r[p + 3] == '0')
                    r.replace(p - 1, 4, "10,01");
                else
                    r.replace(p - 1, 4, "10,10");
            }
            if (r[p + 2] == ',')
            {
                if (r[p + 3] == '0')
                    r.replace(p - 1, 4, "100,1");
                else
                    r.replace(p - 1, 4, "1010");
            }
            if ((r[p - 1] != ',') && (r[p + 1] != ',') && (r[p + 2] != ','))
                if (r[p + 2] == '0')
                    r.replace(p - 1, 4, "1001");
                else
                    r.replace(p - 1, 4, "1010");
        }
    }
    res = stold(r);
    res += del2;
    res = balance(res);
    return res;
}
long double blc2(long double  res)
{
    string r;
    int p;
    r = to_string(res);
    while (1)
    {
        p = r.find('2', 0);
        if (p == -1)
            break;
        if (p == 0)
        {
            r.replace(0, 2, "01");
            r = '1' + r;
        }
        else
        {
            if (r[p - 1] == ',')
                r.replace(p - 2, 4, "1,01");
            if (r[p + 1] == ',')
                r.replace(p - 1, 4, "10,1");
            if ((r[p - 1] != ',') && (r[p + 1] != ','))
                r.replace(p - 1, 3, "101");
        }
    }
    res = stold(r);
    res += del2;
    res = balance(res);
    return res;
}
long double sum(long double x, long double  y)
{
    string r;
    long double res;
    int p;
    res = x + y;
    res = blc(res);
    res += del2;
    return res;

}
long double pr(long double x, long double  y)
{
    string r;
    long double res;
    int p;
    res = x * y;
    res = blc2(res);
    res = balance(res);
    res += del2;
    return res;

}
long double razn(long double x, long double  y)
{
    string r1, r2;
    long double res, a, b;
    int iter = 0;
    int p1, p2, n1, n2, old1 = 0, old2 = 0;
    a = unbalance2(x);
    b = unbalance2(y);
    r1 = to_string(a);
    r2 = to_string(b);
    while (1)
    {
        bool go = true;
        p1 = r1.find(',', 0);
        p2 = r2.find(',', 0);
        old1 = 0;
        while (old1 < r1.length())
        {
            n1 = r1.find('1', old1);
            old2 = 0;
            if (n1 == -1)
                break;
            while (old2 < r2.length())
            {
                n2 = r2.find('1', old2);
                if (n2 == -1)
                    break;
                if ((p1 - n1) == (p2 - n2))
                {
                    r1.replace(n1, 1, "0");
                    r2.replace(n2, 1, "0");
                }
                old2 = n2 + 1;
            }
            old1 = n1 + 1;

        }


        if ((stold(r2) < del2) || (iter > 10))
            break;
        while (1)
        {
            int k = 0;
            p1 = r1.find("100", 0);
            if (p1 != -1)
            {
                r1.replace(p1, 3, "011");
                k = 1;
            }
            p1 = r1.find("10,0", 0);
            if (p1 != -1)
            {
                r1.replace(p1, 4, "01,1");
                k = 1;
            }
            p1 = r1.find("1,00", 0);
            if (p1 != -1)
            {
                r1.replace(p1, 4, "0,11");
                k = 1;
            }
            if (k == 0)
                break;
        }
        iter++;

    }
    a = stold(r1);
    a = balance(a);
    return a;
}
int main()
{
    int Vart, a, b;
    long double  x, y, p, s, del;
    setlocale(LC_ALL, "Russian");
    while (1) {

        cout << "Выведенные на экран значения могут иметь погрешность из-за потери данных при переводе между различными типами данных\n";
        cout << "0.      завершение работы программы\n1.	Сложение\n2.	Вычитание\n3.	Умножение\n4.	Деление\n";
        cin >> Vart;
        if (Vart == 0)
        {
            cout << "Завершение работы программы\n";
            break;
        }
        switch (Vart) {
        case 1:
            cout << "Введите число в десятичной системе счисления: \n";
            cin >> a;
            x = DecToFeb(a);
            cout << "В системе счисления золотого сечения счисления: \n";
            cout << setw(5) << setprecision(10) << x << '\n';
            cout << "Введите второе число в десятичной системе счисления:\n";
            cin >> b;
            cout << "В системе счисления золотого сечения счисления: \n";
            y = DecToFeb(b);
            cout << setw(5) << setprecision(10) << y << '\n';
            cout << "Сумма чисел: \n";
            s = sum(x, y);
            cout << setw(5) << setprecision(20) << s << "\n";
            cout << "В десятичной системе счисления: \n";
            cout << setw(5) << setprecision(20) << FebToDec(s) << "\n";
            break;
        case 2: cout << "Введите большее число в десятичной системе счисления: \n";
            cin >> a;
            x = DecToFeb(a);
            cout << "В системе счисления золотого сечения счисления: \n";
            cout << setw(5) << setprecision(10) << x << '\n';
            cout << "Введите меньшее число в десятичной системе счисления:\n";
            cin >> b;
            cout << "В системе счисления золотого сечения счисления: \n";
            y = DecToFeb(b);
            cout << setw(5) << setprecision(10) << y << '\n';
            cout << "Разность чисел: \n";
            if (x > y)
                del = razn(x, y);
            else
                del = razn(y, x);
            cout << setw(5) << setprecision(20) << del << "\n";
            cout << "В десятичной системе счисления: \n";
            cout << setw(5) << setprecision(10) << FebToDec(del) << "\n";
            break;
        case 3: cout << "Введите число в десятичной системе счисления: \n";
            cin >> a;
            x = DecToFeb(a);
            cout << "В системе счисления золотого сечения счисления: \n";
            cout << setw(5) << setprecision(10) << x << '\n';
            cout << "Введите второе число в десятичной системе счисления:\n";
            cin >> b;
            cout << "В системе счисления золотого сечения счисления: \n";
            y = DecToFeb(b);
            cout << setw(5) << setprecision(10) << y << '\n';
            cout << "Произведение чисел: \n";
            p = pr(x, y);
            cout << setw(5) << setprecision(20) << p << "\n";
            cout << "В десятичной системе счисления: \n";
            cout << setw(5) << setprecision(10) << FebToDec(p) << "\n";
            break;
        case 4: cout << "Введите большее число в десятичной системе счисления: \n";
            cin >> a;
            x = DecToFeb(a);
            cout << "В системе счисления золотого сечения счисления: \n";
            cout << setw(5) << setprecision(10) << x << '\n';
            cout << "Введите меньшее число в десятичной системе счисления:\n";
            cin >> b;
            cout << "В системе счисления золотого сечения счисления: \n";
            y = DecToFeb(b);
            cout << setw(5) << setprecision(10) << y << '\n';
            cout << "Частное чисел: \n";
            if (x > y)
                del = x / y;
            else
                del = y / x;
            del = balance(del);
            cout << setw(5) << setprecision(20) << del << "\n";
            cout << "В десятичной системе счисления: \n";
            cout << setw(5) << setprecision(10) << FebToDec(del) << "\n"; 
            break;
        default: cout << "Не существует соответствующей функции. \n";
            break;
        }
    }

}