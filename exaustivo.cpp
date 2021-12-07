#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>

using namespace std;

const int size = 8;

int  dx[size+1] = { 0, 2, 1, -1, -2, -2, -1, 1 ,2 };
int  dy[size+1] = { 0, 1, 2, 2, 1, -1, -2, -2, -1 };
int  h[size+1][size+1];
int  n;

void print()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << setw(5) << h[i][j];
        }

        cout << endl;
    }
}

void TryNextMove(int i,int x,int y,bool &s)
{ 
    int u,v,k;
    bool sucesso;
    k = 0;
    sucesso = false;

    do{ 
        k++;
        u = x + dx[k];
        v = y + dy[k];

        if (1<=u  && u<=n && 1<=v && v<=n && h[u][v]==0)
        { 
            h[u][v] = i;
            if (i < n*n)
            { 
                TryNextMove(i+1,u,v,sucesso);
                if (!sucesso)
                h[u][v] = 0;
            }else{
                sucesso = true;
            }
        }

        print();
        cout << endl;
        //this_thread::sleep_for( chrono::milliseconds(800) );
        

    } while (!sucesso && k < size);
    s = sucesso;
}


int main(int argc, const char* argv[])
{ 
    int i,j;
    bool q;

    cout << "Tamanho do tabuleiro (1-8): ";
    cin >> n;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            h[i][j] = 0;
        }
    }

    cout << "Posicao inicial do cavalo (x,y): ";
    cin >> i >> j;
    
    h[i][j] = 1;
    TryNextMove(2,i,j,q);
    
    if (q)
    {
        cout << "\n\n";
        print();
    }else{
        cout << "Caminho nao encontrado" << endl;
    }

 return 0;
}
