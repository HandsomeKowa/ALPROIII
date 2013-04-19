#include <iostream>
#include <cmath>
#include <list>
#include <ctime>

#define MAX 2000000

using namespace std;

bool confirma(double n)
{
    if (n - (int)n == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void print(const list<int>& s)
{
	list<int>::const_iterator i;
	for( i = s.begin(); i != s.end(); ++i)
		cout << *i << " ";
	cout << endl;
}

int main ()
{
    cout << "Comecando a busca pelos quadrados perfeitos:" << endl;
    const clock_t begin_time = clock();

    int qx = 0;
    int qy = 0;
    int qz = 0;

    list <int> listx;
    list <int> listy;
    list <int> listz;

    listx.clear();
    listy.clear();
    listz.clear();


    for (int x = MAX; x > 0; x--)
    {
        qx++;
        for (int y = x-1; y >0; y--)
        {
            if (confirma(sqrt(x-y)) == 1)
            {
                qy++;
                if (confirma(sqrt(x+y)) == 1)
                {

                    for (int z = y-1; z > 0; z--)
                    {
                        qz++;
                        if (confirma(sqrt(x+z)) == 1)
                        {
                            if (confirma(sqrt(x-z)) == 1)
                            {

                                if (confirma(sqrt(y+z)) == 1)
                                {
                                    if (confirma(sqrt(y-z)) == 1)
                                    {
                                        listx.push_back(x);
                                        listy.push_back(y);
                                        listz.push_back(z);

                                        cout << "Tempo: " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;

                                        print(listx);
                                        print(listy);
                                        print(listz);

                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (x%10000 == 0)
             cout << "x: " << qx << ", y: " << qy << ", z: " << qz << endl;
        qx = qy = qz = 0;
    }

    print(listx);
    print(listy);
    print(listz);

    cout << "Tempo: " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;

}
