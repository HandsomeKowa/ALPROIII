#include <iostream>
#include <cmath>
#include <ctime>
#include <list>
//#define MAX 434657
#define MAX 3

using namespace std;

bool confirma(int n)
{
    int x = n%1;
    if (x == 0)
    {
        cout << "Raiz: " << x << endl;
        return true;
    }
    else
        {
            cout << "Nao e perfeito" << endl;
            return false;
        }
}

bool soma (int a, int b)
{
    if (confirma((int)sqrt (a+b)))
    {
        cout << "confirmou" << endl;
        return true;
    }
    else
        return false;
}

bool sub (double a, double b)
{
    if (confirma((int)sqrt (a+b)))
        return true;
    else
        return false;
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
    list <int> listx;
    list <int> listy;
    list <int> listz;

    listx.clear();
    listy.clear();
    listz.clear();

  for (int x = MAX; x >= 1; x-- )
    {
        const clock_t begin_time = clock();
        for (int y = x-1; y >= 1; y-- )
        {
           //if (y == 420968) cout << "y " << y << endl;
            for (int z = y-1; z >= 1; z-- )
            {
                //cout << x << endl << y << endl << z << endl;
                // cout << "z " << z << endl;
                if (soma(x,y) == true)
                {
//                    cout << "feito" << endl;
                    if (sub(x,y))
                    {
//                        cout << "feito" << endl;
                        if (soma(y,z))
                        {
 //                           cout << "feito" << endl;
                            if (sub(y,z))
                            {
 //                               cout << "feito" << endl;
                                if (soma(x,z))
                                {
  //                                  cout << "feito" << endl;
                                    if (sub(x,z))
                                    {
                                        //cout <<"cheguei na ultima verificacao: "<< x <<", " << y << ", " << z << endl;
                                        /*listx.push_back(x);
                                        listy.push_back(y);
                                        listz.push_back(z);*/
                                        cin.get();
                                        //break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << "Tempo: " << float( clock () - begin_time ) /  CLOCKS_PER_SEC << endl;
        cout << "X: "; print(listx);
        cout << "Y: "; print(listy);
        cout << "Z: "; print(listz);

    }
}




