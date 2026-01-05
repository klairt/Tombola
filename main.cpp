#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    //consegna
    /*Il programma dovrà avere le seguenti funzionalità:
    1. generare le cartelle per almeno 2 giocatori
    2. estrarre i numeri della tombola a intervalli regolari
    3. mostrare il tabellone aggiornato
    4. controllare e mostrare la presenza dei numeri estratti nelle cartelle
    5. segnalare il vincitore che ha fatto "tombola" (estratti tutti i numeri della propria cartella)*/

    cout<<"Benvenuti a tombola!\n";

    //dichiarazione
    int giocatori,num;

    /*STEP 1: generare le cartelle per almeno 2 giocatori
     - Chiedere il numero di cartelle da generare
     - Generare le cartelle:
        1.Le cartelle sono formate da 3 righe di 5 numeri ciascuna
        2.In ogni riga non possono essere presenti numeri appartenenti alla stessa decina
        3.Non possono esserci numeri ripetuti nella stessa cartella.
        4.La visualizzazione della cartella deve rispettare l'incolonnamento delle decine (eccezione: il numero 90 si incolonna nell'ottava decina)*/

    do{
        cout<<"Inserire il numero di giocatori (minimo 2): ";
        cin>>giocatori;

    }while(giocatori<2); //ciclo che permette di avere almeno 2 giocatori
    cout<<"\nOttimo! Ci sono "<<giocatori<<" giocatori. Buon divertimento!\n\n";


    srand(time(NULL));

    for(int p=0;p<giocatori;p++)
    {

        cout<<"Cartello giocatore "<<p+1<<": \n\n";
       int colonne[9][3];
       int usati[90];

       for(int j=0; j<3; j++)
       {

       for(int i=0; i<9; i++)
        {
           num=(rand()%9+1)+i*10;

               while(usati[num]==1)
               {
                   num=(rand()%9+1)+i*10;
               }
               colonne[i][j]=num;
               usati[num]=1;

        }
       }

    for(int j=0; j<3; j++)
    {
            int x;
            int usato[9]={0,0,0,0,0,0,0,0,0};
            for(int k=0; k<5; k++)
            {
                x=rand()%9;
                while(usato[x]==1)
                {
                    x=rand()%9;
                }
                usato[x]=1;
            }
            for(int i=0; i<9; i++)
            {
                if(usato[i]==1)
                {
                    if(i<1)
                    {
                        cout<<colonne[i][j]<<" ";
                    }else
                    {
                        cout<<colonne[i][j]<<"  ";
                    }

                }else
                {
                    if(i>=1)
                    {
                        cout<<"    ";
                    }else
                    {
                        cout<<"  ";
                    }
                }
            }

        cout<<endl;
            for(int j=0;j<34;j++)
            {
                cout<<"-";
            }
        cout<<endl;
    }


    cout<<"\n\n\n\n";
    }




    //GENERA TABELLA

    cout<<"Tabellone tombola:\n";
   int tabella[90];

   for(int i=1;i<=90;i++)
   {
       tabella[i-1]=i;
       if(i<=10&&i>=1)
       {
           cout<<i<<"  ";
       }else
       {
           cout<<i<<" ";
       }

       if(i%10==0)
       {   cout<<endl;
           for(int j=0;j<30;j++)
           {
               cout<<"-";
           }
           cout<<endl;
       }
   }


          return 0;

}