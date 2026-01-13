#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <string>
using namespace std;

int main()
{
    //consegna
    /*Il programma dovrà avere le seguenti funzionalità:
    1. generare le cartelle per almeno 2 giocatori.
    2. estrarre i numeri della tombola a intervalli regolari.
    3. mostrare il tabellone aggiornato.
    4. controllare e mostrare la presenza dei numeri estratti nelle cartelle.
    5. segnalare il vincitore che ha fatto "tombola" (estratti tutti i numeri della propria cartella)*/
	
	 cout<<"\33[1m";
	cout<<"\33[38;5;217m";
    cout<<"Benvenuti a tombola!\n\n\n";
	 cout<<"\33[0m";
	  cout<<"\33[22m";
	
    int giocatori,num;

    do{
        cout<<"Inserire il numero di giocatori (minimo 2, massimo 10!): ";
        cin>>giocatori;
    }while(giocatori<2||giocatori>10); //ciclo che permette di avere almeno 2 giocatori e non più di 10

    cout<<"\nOttimo! Ci sono "<<giocatori<<" giocatori.\n\n";
	
	sleep(2);
    string nomi[10];
    for(int p=0; p<giocatori; p++)
    {
        cout<<"Inserisci il nome del giocatore "<<p+1<<": ";
        cin>>nomi[p];
    }

    cout<<"\nBuon divertimento!\n\n";

    srand(time(NULL));

    // SALVIAMO LE CARTELLE - 3 array separati per ogni riga
    int riga1[10][9];  // Salva la prima riga della cartella di ogni giocatore
    int riga2[10][9];  // Salva la seconda riga della cartella di ogni giocatore
    int riga3[10][9];  //Salva la terza riga della cartella di ogni giocatore
    int visibili1[10][9];  // Numeri visibili nella riga 1 per ogni giocatore. Massimo di giocatori è 10
    int visibili2[10][9];  // Numeri visibili nella riga 2 per ogni giocatore. Massimo di giocatori è 10
    int visibili3[10][9];  // Numeri visibili nella riga 3 per ogni giocatore. Massimo di giocatori è 10

    // GENERAZIONE CARTELLE
    for(int p=0; p<giocatori; p++)
    {
        cout<<"Cartella di "<<nomi[p]<<": \n\n";
        int usati[90];

        for(int a=0; a<90; a++)
        { //con questo ciclo, tutti i valori nell'array vengono posti a zero.
            usati[a]=0;
        }

        // Genera numeri per la prima riga
        for(int i=0; i<9; i++)
        {
            num=(rand()%9+1)+i*10; //Genera un numero pseudocasuale da 1-9, aggiungendoli poi i moltiplicato per 10 (0,10,20,30...) cosicché siano in fila

            while(usati[num-1]==1)  //Se l'array usati nella posizione della variabile num è stata già riempita con 1, vuol dire che è già stata usato. Dunque, entra nel ciclo finché non genera un numero nuovo
            {
                num=(rand()%9+1)+i*10;
            }

            riga1[p][i]=num; //la variabile riga1 sarà riempita con la variabile num sulla posizione di p alla riga i
            usati[num-1]=1; //Array usati sarà riempito con 1 nella posizione num-1. Simile al concetto di mettere 'True' un booleano 'False'
        }

        // Genera numeri per riga 2 -> STESSO RAGIONAMENTO DI RIGA SOPRA
        for(int i=0; i<9; i++)
        {
            num=(rand()%9+1)+i*10;

            while(usati[num-1]==1)
            {
                num=(rand()%9+1)+i*10;
            }

            riga2[p][i]=num;
            usati[num-1]=1;
        }

        // Genera numeri per riga 3
        for(int i=0; i<9; i++)
        {
            num=(rand()%9+1)+i*10;

            while(usati[num-1]==1)
            {
                num=(rand()%9+1)+i*10;
            }

            riga3[p][i]=num;
            usati[num-1]=1;
        }

        //SCELTA DEI NUMERI DA PRENDERE (5 PER OGNI RIGA)
        int stampa[9]={0,0,0,0,0,0,0,0,0}; //array d'appoggio
        for(int k=0; k<5; k++)
        {
            int x=rand()%9; //variabile genera una posizione casuale da 0-8
            while(stampa[x]==1)  //Stesso ragionamento di prima. Se array stampa alla posizione x è stato impostato a 1, vuol dire che è già stato utilizzato e non uscirà dal ciclo fino a quando non genera una posizione nuova
            {
                x=rand()%9;
            }
            stampa[x]=1; //Si imposta stampa[x] a 1, per dire che è già stato usato
        }

        //Sposto i numeri scelti nella variabile visibili, per la riga 1
        for(int i=0; i<9; i++)
        {
            visibili1[p][i]=stampa[i]; //questo array serve per quando devo eventualmente colorare il numero estartto
        }

        // SCELTA NUMERI PER LA SECONDA RIGA
        for(int i=0; i<9; i++)
        { //resetto variabile stampa
            stampa[i]=0;
        }

        for(int k=0; k<5; k++)
        {
            int x=rand()%9;
            while(stampa[x]==1)
            {
                x=rand()%9;
            }
            stampa[x]=1;
        }

        //Sposto i numeri scelti nella variabile visibili, per la riga 2
        for(int i=0; i<9; i++)
        {
            visibili2[p][i]=stampa[i]; //questo array serve per quando devo eventualmente colorare il numero estartto
        }

        //SCELTA NUMERI PER TERZA RIGA
        for(int i=0; i<9; i++)
        {
            stampa[i]=0;
        }

        for(int k=0; k<5; k++)
        {
            int x=rand()%9;
            while(stampa[x]==1)
            {
                x=rand()%9;
            }
            stampa[x]=1;
        }

        //Sposto i numeri scelti nella variabile visibili, per la riga 3
        for(int i=0; i<9; i++)
        {
            visibili3[p][i]=stampa[i]; //questo array serve per quando devo eventualmente colorare il numero estartto
        }

        // STAMPA CARTELLA INIZIALE (Riga 1)
        for(int i=0; i<9; i++)
        {
            if(visibili1[p][i]==1)
            {
                if(i==0)
                    cout<<riga1[p][i]<<" ";
                else
                    cout<<riga1[p][i]<<"  ";
            }else
            {
                if(i>0) //per avere una cartella incolonnata bene, se si tratta del primo numero della colonna (da 1-9), si lascia solo due spazi, altrimenti quattro
                    cout<<"    ";
                else
                    cout<<"  ";
            }
        }

        cout<<endl; //dopo ogni riga, si genera una linea che li separa l'uno dall'altro
        for(int l=0;l<34;l++)
        {
            cout<<"-";
        }
        cout<<endl;

        // STAMPA CARTELLA INIZIALE Riga 2
        for(int i=0; i<9; i++)
        {
            if(visibili2[p][i]==1)
            {
                if(i==0)
                    cout<<riga2[p][i]<<" ";
                else
                    cout<<riga2[p][i]<<"  ";
            }else
            {
                if(i>0)
                    cout<<"    ";
                else
                    cout<<"  ";
            }
        }

        cout<<endl; //dopo ogni riga, si genera una linea che li separa l'uno dall'altro
        for(int l=0;l<34;l++)
        {
            cout<<"-";
        }
        cout<<endl;

        // Riga 3
        for(int i=0; i<9; i++)
        {
            if(visibili3[p][i]==1)
            {
                if(i==0)
                    cout<<riga3[p][i]<<" ";
                else
                    cout<<riga3[p][i]<<"  ";
            }else
            {
                if(i>0)
                    cout<<"    ";
                else
                    cout<<"  ";
            }
        }

        cout<<endl; //dopo ogni riga, si genera una linea che li separa l'uno dall'altro
        for(int l=0;l<34;l++)
        {
            cout<<"-";
        }
        cout<<endl;
        cout<<"\n\n";
    }

    sleep(5);
    
    
	cout<<"\33[H"; //muove il cursore nella posizione 0,0
	cout<<"\33[J"; //cancella tutto lo schermo per poi fare l'estrazione

    // ESTRAZIONE NUMERI
    int utilizzato[90];

    for(int u=0; u<90; u++)
    {   //metto tutto l'array a valore 0
        utilizzato[u]=0;
    }

    int vincitore = 0; // 0 significa che non c'è ancora vincitore

    for(int i=0;i<90 && vincitore==0;i++) 
    {
        int estratto=rand()%90+1;
        while(utilizzato[estratto-1]==1)
        {
            estratto=rand()%90+1;
        }
        utilizzato[estratto-1]=1;

        cout<<"Il numero estratto è "<<estratto<<" !\n\n\n";

        // STAMPA TABELLONE
        cout << "Tabellone tombola:\n\n";
        for (int k=1; k<=90; k++) {
            if (utilizzato[k-1]==1)
            {
                cout<<"\33[38;5;111m";
                if (k<=10)
                    cout<<k<<"  ";
                else
                    cout<<k<<" ";
                cout<<"\33[0m";
            } else {
                if (k<=10)
                    cout<<k<<"  ";
                else
                    cout<<k<<" ";
            }

            if (k % 10 == 0)
            {
                cout<<endl;
                for (int j = 0; j < 30; j++)
                    cout<<"-";
                cout<<endl;
            }
        }
        cout<<endl<<endl;

        // RISTAMPA CARTELLE CON COLORI
        for(int p=0; p<giocatori; p++)
        {
            cout<<"Cartella di "<<nomi[p]<<": \n\n";

            // Stampa riga 1
            for(int i=0; i<9; i++)
            {
                if(visibili1[p][i]==1)
                {
                    if(utilizzato[riga1[p][i]-1]==1)
                        cout<<"\33[38;5;120m";

                    if(i==0)
                        cout<<riga1[p][i]<<" ";
                    else
                        cout<<riga1[p][i]<<"  ";

                    if(utilizzato[riga1[p][i]-1]==1)
                        cout<<"\33[0m";
                }else
                {
                    if(i>0)
                        cout<<"    ";
                    else
                        cout<<"  ";
                }
            }
            cout<<endl;
            for(int l=0;l<34;l++) cout<<"-";
            cout<<endl;

            // Stampa riga 2
            for(int i=0; i<9; i++)
            {
                if(visibili2[p][i]==1)
                {
                    if(utilizzato[riga2[p][i]-1]==1)
                        cout<<"\33[38;5;120m";

                    if(i==0)
                        cout<<riga2[p][i]<<" ";
                    else
                        cout<<riga2[p][i]<<"  ";

                    if(utilizzato[riga2[p][i]-1]==1)
                        cout<<"\33[0m";
                }else
                {
                    if(i>0)
                        cout<<"    ";
                    else
                        cout<<"  ";
                }
            }
            cout<<endl;
            for(int l=0;l<34;l++) cout<<"-";
            cout<<endl;

            // Stampa riga 3
            for(int i=0; i<9; i++)
            {
                if(visibili3[p][i]==1)
                {
                    if(utilizzato[riga3[p][i]-1]==1)
                        cout<<"\33[38;5;120m";

                    if(i==0)
                        cout<<riga3[p][i]<<" ";
                    else
                        cout<<riga3[p][i]<<"  ";

                    if(utilizzato[riga3[p][i]-1]==1)
                        cout<<"\33[0m";
                }else
                {
                    if(i>0)
                        cout<<"    ";
                    else
                        cout<<"  ";
                }
            }
            cout<<endl;
            for(int l=0;l<34;l++) cout<<"-";
            cout<<endl;

            cout<<"\n";
        }
        cout<<endl;

        // CONTROLLO TOMBOLA - verifica se qualcuno ha vinto
        for(int p=0; p<giocatori; p++)
        {
            int numeriCompletati = 0;

            // Conta quanti numeri sono stati estratti per questo giocatore
            for(int i=0; i<9; i++)
            {
                if(visibili1[p][i]==1 && utilizzato[riga1[p][i]-1]==1)
                { //visibili1[p][i]==1 controlla se Il numero in quella posizione è visibile nella cartella (cioè fa parte dei 5 numeri scelti per quella riga)
                  //utilizzato[riga1[p][i]-1]==1 controlla quale numero è statoestratto
                    numeriCompletati++;
                }
                if(visibili2[p][i]==1 && utilizzato[riga2[p][i]-1]==1)
                {
                    numeriCompletati++;
                }
                if(visibili3[p][i]==1 && utilizzato[riga3[p][i]-1]==1)
                {
                    numeriCompletati++;
                }
            }

            // Se ha estratto tutti i 15 numeri, il giocatore vince
            if(numeriCompletati == 15)
            {
                vincitore = p; // salva l'indice del giocatore vincitore
                break; // il ciclo si ferma se c'è un vincitore
            }
        }

        if(vincitore == 0) // se non c'è vincitore, continua con l'estrazione
        {
            //sleep(2);
            
            cout<<"\e[J"; //cancella tutto lo schermo
			cout<<"\e[H"; //muove il cursore nella posizione 0,0
        }
    }
    
    sleep(2);

    //if(vincitore != 0)
    //{
       
        
        cout<<"\33[J"; //cancella tutto lo schermo
        cout<<"\33[H"; //muove il cursore nella posizione 0,0

        // Stampa il messaggio centrato
       
        cout<<"*** TOMBOLA! ***\n\n";
       
        cout<<"Congratulazioni "<<nomi[vincitore]<<", hai vinto! :)\n\n";
    //}
    
    

    return 0;
}
