#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
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

    cout<<"Benvenuti a tombola!\n\n\n";
    
    sleep(2);

    //dichiarazione
    int giocatori,num;
    
	//GENERA TABELLA

   cout<<"Tabellone tombola:\n\n";
   int tabella[90]; //array tabella di 90 celle

   for(int i=1;i<=90;i++)
   {
       tabella[i-1]=i; //ogni cella dell'array sarà riempita in modo crescente da 1 a 90
       if(i<=10&&i>=1)
       {
           //se i numeri sono compresi fra 1-10, si lasciano 2 spazi per incolonnarli bene, altrimenti solo un spazio
           cout<<i<<"  ";
       }else
       {
           cout<<i<<" ";
       }

       if(i%10==0) //ad ogni 10 numeri, si va a capo
       {   cout<<endl;
           for(int j=0;j<30;j++)
           {
               cout<<"-";
           }
           cout<<endl;
       }
   }

   cout<<endl<<endl;
   
  	
   sleep(2);

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

    for(int p=0;p<giocatori;p++) //ciclo che genera una cartella per ogni giocatore
    {

        cout<<"Cartella giocatore "<<p+1<<": \n\n";
       int colonne[9][3]; //tabella della cartella
       int usati[90]; //array d'appoggio

       //STRUTTURA CARTELLA
       for(int j=0; j<3; j++) //ciclo che si ripete per il numero di righe
       {

       for(int i=0; i<9; i++) //ciclo che si ripete per il numero di colonne
        {
           num=(rand()%9+1)+i*10; //Genera un numero pseudocasuale da 1-9, aggiungendoli poi i moltiplicato per 10 (0,10,20,30...) cosicché siano in fila

               while(usati[num-1]==1) //Se l'array usati nella posizione della variabile num è stata già riempita con 1, vuol dire che è già stata usata. Dunque, entra nel ciclo finché non genera un numero nuovo
               {
                   num=(rand()%9+1)+i*10;
               }
               colonne[i][j]=num; //la tabella colonne sarà riempita con la variabile num sulla riga i nella colonna j
               usati[num-1]=1; //Array usati sarà riempito con 1 nella posizione num-1. Simile al concetto di mettere 'True' un booleano 'False'

        }
       }
    //STAMPA CARTELLA
    for(int j=0; j<3; j++) //ciclo che si ripete per il numero di righe
    {
            //SCELTA DEI NUMERI DA PRENDERE (5 PER OGNI RIGA)
            int x; //variabile d'appoggio
            int stampa[9]={0,0,0,0,0,0,0,0,0}; //array d'appoggio
            for(int k=0; k<5; k++) //ciclo che riempie variabile stampa
            {
                x=rand()%9; //variabile genera una posizione casuale da 0-8
                while(stampa[x]==1) //Stesso ragionamento di prima. Se array stampa alla posizione x è stato impostato a 1, vuol dire che è già stato utilizzato e non uscirà dal ciclo fino a quando non genera una posizione nuova
                {
                    x=rand()%9;
                }
                stampa[x]=1;//Si imposta stampa[x] a 1, per dire che è già stato usato
            }
            //STAMPA DEI NUMERI PRESI
            for(int i=0; i<9; i++)
            {
                if(stampa[i]==1)
                {   //se array stampa nella posizione i è stato impostato ad 1, vuol dire che è stato scelto quel numero, e dunque si stampa quello
                    if(i==0) //per avere una cartella incolonnata bene, se si tratta del primo numero della colonna (da 1-9), si lascia solo uno spazio dopo averlo inserito, altrimenti due (perché tutti gli altri numeri hanno sia decine che unità)
                    {
                        cout<<colonne[i][j]<<" ";
                    }else
                    {
                        cout<<colonne[i][j]<<"  ";
                    }

                }else
                {
                    if(i>0)//per avere una cartella incolonnata bene, se si tratta del primo numero della colonna (da 1-9), si lascia solo due spazi, altrimenti quattro
                    {
                        cout<<"    ";
                    }else
                    {
                        cout<<"  ";
                    }
                }
            }

        cout<<endl; //dopo ogni riga, si genera una linea che li separa l'uno dall'altro
            for(int j=0;j<34;j++)
            {
                cout<<"-";
            }
        cout<<endl;
    }

	for(int l=0;l<90;l++) //RESET USATI
	{
		usati[l]=0;
	}
    cout<<"\n\n\n\n";
    }




    //GENERA TABELLA

   /*cout<<"Tabellone tombola:\n\n";
   int tabella[90]; //array tabella di 90 celle

   for(int i=1;i<=90;i++)
   {
       tabella[i-1]=i; //ogni cella dell'array sarà riempita in modo crescente da 1 a 90
       if(i<=10&&i>=1)
       {
           //se i numeri sono compresi fra 1-10, si lasciano 2 spazi per incolonnarli bene, altrimenti solo un spazio
           cout<<i<<"  ";
       }else
       {
           cout<<i<<" ";
       }

       if(i%10==0) //ad ogni 10 numeri, si va a capo
       {   cout<<endl;
           for(int j=0;j<30;j++)
           {
               cout<<"-";
           }
           cout<<endl;
       }
   }

   cout<<endl<<endl;
   
  	
   sleep(2);*/

   //ESTRAZIONE NUMERI
   int utilizzato[90]={0};
   for(int i=0;i<90;i++)
   {	
       
       int estratto=rand()%90+1;
       while(utilizzato[estratto]==1) //con questo ciclo, verrano sempre estratti numeri diversi
       {
           estratto=rand()%90+1;
       }
       utilizzato[estratto]=1;
       cout<<"Il numero estratto è "<<estratto<<" !\n\n\n";

       cout << "Tabellone tombola:\n\n";
       for (int k=1; k<=90; k++) {
           if (utilizzato[k]==1) //se il numero è già stato estratto, si colore di lilla
           {
               
               cout<<"\33[38;5;111m"; // inizia colore lilla
               if (k<=10)
               {
                   cout<<k<<"  ";
               } else
               {
                   cout<<k<<" ";
               }
               cout<<"\33[0m"; // reset colore

           } else {
               if (k<=10)
               {
                   cout<<k<<"  ";
               } else
               {
                   cout<<k<<" ";
               }
           }

           if (k % 10 == 0)
           {
               cout<<endl;
               for (int j = 0; j < 30; j++)
               {
                   cout<<"-";
               }
               cout<<endl;
           }
       }
      
       cout<<endl<<endl;

 
	
       sleep(2); //i numeri vengono generati a intervalli regolari, come richiesto
    
       cout<<"\e[25A";
       cout<<"\e[0K";
      
      
   }



          return 0;

}
