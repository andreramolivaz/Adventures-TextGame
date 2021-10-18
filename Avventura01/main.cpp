//
//  main.cpp
//  Avventura01
//
//  Created by André Ramolivaz on 01/01/2020.
//  Copyright © 2020 André Ramolivaz. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>

using namespace std;
fstream leggof,scrivof;
string sol;

struct partita
{
    int azioni;
    string punti;
    int completato;
};
partita databin;
string vet [5]{"SENTI STRANI RUMORI!", "FAI INFRETTA!","STA CROLLANDO TUTTO!", "OCCHIO AL TEMPO!", "SBRIGATI!"};
void acaso()
{
    string s;
    int x;
    x=rand()%5;
    s=vet [x];
    cout<<endl<<s<<endl;
}
void titolo()
{
    system("cls");
    cout<<endl<<"|Q|              |T|       |C| ";
    cout<<endl<<"      |U|    |N|      |I|        |A|        ";
    cout<<endl<<"           |A|                           Project°";
    cout<<endl<<"--------------------------------------------------------------------------";
    cout<<endl<<"Avventura ambientata in un mondo parallelo creato da un computer quantico.";
    cout<<endl<<"--------------------------------------------------------------------------";
    cout<<endl<<endl<<endl;
}
void scrivoinfopartita()
{
    scrivof.open("data.bin",ios::out);
    scrivof.write((char*)&databin, sizeof(partita));
    scrivof.close();
}
void leggoinfopartita()
{
    scrivof.open("data.bin",ios::in);
    scrivof.read((char*)&databin, sizeof(partita));
    scrivof.close();
    
    titolo();
    cout<<endl<<"REPORT:";
    cout<<endl<<"Azioni: "<<databin.azioni<<" |Punti: "<<databin.punti<<" |Completato: "<<databin.completato<<"%";
}

void appunti()
{
    string note;
    string notepresenti;
    
    leggof.open("appuntidata.txt",ios::in);
    if(leggof.is_open())
    {
        while(!leggof.eof())
        {
            leggof.ignore();
            getline(leggof,notepresenti,'*');//!per stringhe
        }
        
    }
    else
        cout<<endl<<"-! Il file è dannegiato.";
    
    leggof.close();
    system("cls");
    cout<<endl<<notepresenti;
    cout<<endl<<"AGGIUNGI NOTE: (utilizza la virgola come spazio1)"<<endl;
    cin>>note;
    scrivof.open("appuntidata.txt",ios::out||ios::app);
    if(scrivof.is_open())
    {
        scrivof<<note;
    }
    scrivof.close();
    
}
void soluzione()
{
    leggof.open("soluzionedata.txt",ios::in);
    if(leggof.is_open())
    {
        while(!leggof.eof())
        {
            leggof.ignore();
            getline(leggof,sol,'*');//!per stringhe
        }
        
    }
    else
        cout<<endl<<"-! Il file è dannegiato.";
    
    leggof.close();
    titolo();
    cout<<endl<<sol;
}

void gioca()
{
    bool var=false,var2=false;
    char s;
    string x;
label0:;
    databin.azioni=0;
    databin.completato=0;
    databin.punti="";
    scrivoinfopartita();
    titolo();
    cout<<endl<<"<< Di salti quantici in quest'ultimo anno ne ho fatti parecchi, ma stavolta avevo una strana sensazione. Era come se una voce dentro di me, mi spingesse a non farlo, ma purtroppo non potevo ritirarmi. Sono il collaudatore ufficiale del Quantica Project e quindi devo seguire il protocollo. Sono colui che si immerge nei mondi paralleli ricreati dal Quantum Device allo scopo di testare in pratica gli effetti derivanti dal salto quantico. Non so cosa sia andato storto, ma so che ci troviamo in una Quasar Facility alternativa, in un mondo parallelo ricreato da un computer quantico. Il problema non è stato entrare, ma e' quello di uscire. >>."<<endl;
    
    cout<<endl<<"<< Nick! Nick! >>,";
    cout<<endl<<"<< Come??? Cosa??? Ah, sì, dimmi Alice >>,";
    cout<<endl<<"<< A cosa stai pensando Nick? >>,";
    cout<<endl<<"<< No, a niente. Cos'e' accaduto? Come possiamo ritornare nel nostro mondo? >>,";
    cout<<endl<<"<< Dobbiamo cercare di capirlo alla svelta Nick e dobbiamo scappare prima che imploda tutto. Come anche voi sapete, l'oscurita' presto distruggera' la materia. >>,";
    cout<<endl<<"<< E cosa dobbiamo fare Carlos? >>,";
    cout<<endl<<"<< La Facility del mondo parallelo non e' l'esatta copia della Quasar Facility del nostro mondo? >>,";
    cout<<endl<<"<< Si Carlos, continua... >>,";
    cout<<endl<<"<< Bene. Io andrò in armeria a prendere delle armi, non mi piace stare in questo posto disarmato, tu Alice vai al centro di controllo, la Control Room, per scoprire cos'è accaduto di preciso, tu Nick invece continua con il tuo piano da collaudatore. Stai tranquillo, penseremo a tutto io e Alice >>."<<endl;
    cout<<endl<<"Sei a Quantica, una struttura ricreata in un mondo parallelo da una macchina chiamata Quantum Device. E' un dispositivo in grado di ricreare un mondo parallelo a dimensioni reali partendo da un progetto in 3D sviluppato all'interno di un computer. Il dispositivo ricrea inoltre una porta virtuale chiamata Access Gate, che permette di varcare la soglia ed accedere al mondo ricreato dalla macchina. Lavori per conto della Quasar Inc, una potente corporazione, che gestisce il Quantica Project per conto del governo degli Stati Uniti. Il tuo compito è quello di testare la struttura parallela e gli eventuali effetti che potrebbero derivarne sulla materia. Qualcosa tuttavia questa volta e' andata per il verso sbagliato. Siete stati inghiottiti nel mondo parallelo dal computer in modo del tutto automatico e misterioso.";
label1:;
    cout<<endl<<endl<<"Ti trovi all'ingresso di Quantica, Carlos il capo della sicurezza è andato nella Stanza delle Armi, la Weapons Storage, mentre Alice al centro di controllo.Qui puoi vedere UNA GRANDE PORTA, delle scale che vanno al PIANO SUPERIORE, delle SCALE che vanno VERSO IL BASSO, UN ASCENSORE, una FINESTRA e un lungo CORRIDOIO.";
    acaso();
    cout<<endl<<"COSA DESIDERI ANALIZZARE?";
    cout<<endl<<"- 1)una grande porta";
    cout<<endl<<"- 2)piano superiore";
    cout<<endl<<"- 3)scale verso il basso";
    cout<<endl<<"- 4)ascensore";
    cout<<endl<<"- 5)finestra";
    cout<<endl<<"- 6)corridoio"<<endl;
    cout<<endl<<"- 0)torna al menu"<<endl;
    cin>>s;
    switch (s){
        case '1':
            databin.azioni++;
            system("cls");
            cout<<endl<<"GRANDE PORTA";
            cout<<endl<<"Una porta scorrevole in acciaio. Permette di accedere all'area B della struttura. Deve essere sbloccata elettronicamente dalla CONTROL ROOM."<<endl;
            acaso();
            cin>>x;
            system("cls");
            scrivoinfopartita();
            goto label1;
            break;
        case '2':
            databin.azioni++;
            system("cls");
            cout<<endl<<"SCALE";
            cout<<endl<<"Le scale continuano...";
            acaso();
            cout<<endl<<"Sali(Sa) o Scendi(Sc)?"<<endl;
            cin>>x;
            if(x=="Sa")
            {
                databin.azioni++;
            label3:;
                system("cls");
                cout<<endl<<"CORRIDOIO PRIMO PIANO";
                cout<<endl<<"A Ovest vedi l'Armeria, a Est un Bagno.Le scale continuano..."<<endl;
                acaso();
                cout<<endl<<"Est(E), Ovest(O), Sali (S)?"<<endl;
                cin>>x;
                if(x=="E")
                {
                    databin.azioni++;
                    system("cls");
                    cout<<endl<<"REST ROOM";
                    cout<<endl<<"E' il bagno di Quantica dell'Area A. Vedi una presa di corrente ma non funziona"<<endl;
                    acaso();
                    cin>>x;
                    goto label3;
                }
                if(x=="O")
                {
                    databin.azioni++;
                    system("cls");
                    cout<<endl<<"WEAPONS STORAGE";
                    cout<<endl<<"Vedi Carlos in Armeria. << Nick, hai parlato con Regina? Forse ha bisogno del tuo aiuto. Per ora qui la situazione e' sotto controllo. >>."<<endl;
                    acaso();
                    cin>>x;
                    scrivoinfopartita();
                    goto label3;
                }
                system("cls");
            }
            if(x=="S")
            {
                databin.azioni++;
                system("cls");
                cout<<endl<<"GENERATORE";
                cout<<endl<<"Vedi un generatore malridotto, lo prendi e ne usufruisci. "<<endl;
                acaso();
                databin.completato=20;
                scrivoinfopartita();
                var=true;
                cin>>x;
                
            }
            if(x=="Sc")
            {
                databin.azioni++;
                system("cls");
                cout<<endl<<"BOTOLA";
                cout<<endl<<"Vedi una botola, ma è bloccata. "<<endl;
                acaso();
                databin.completato=10;
                scrivoinfopartita();
            }
            
            goto label1;
            
            break;
        case '3':
            databin.azioni++;
            if(var2==false){
                system("cls");
                cout<<endl<<"BOTOLA";
                cout<<endl<<"Vedi una botola, ma è bloccata.Ti serve la chiave."<<endl;
                acaso();
                cin>>x;
                goto label1;
            }
            if(var2==true)
            {
                system("cls");
                cout<<endl<<"BOTOLA";
                cout<<endl<<"Congratulazioni, scappi e ti metti in salvo!."<<endl<<"HAI VINTO"<<endl;
                cin>>x;
                databin.completato=100;
                scrivoinfopartita();
                goto label4;
                
            }
            break;
        case '4':
            databin.azioni++;
            system("cls");
            cout<<endl<<"ASCENSORE";
            cout<<endl<<"Porta ai piani superiori e a quello inferiore, ma è fuori servizio. Manca la corrente."<<endl;
            acaso();
            cin>>x;
            goto label1;
            break;
        case '5':
            databin.azioni++;
            system("cls");
            cout<<endl<<"FINESTRA";
            cout<<endl<<"Una normale finestra. Guardando fuori dalla struttura l'unica cosa che noti e' il buio. Un'oscurità che divora tutto quanto, luce compresa. Quel buio inoltre ti fa capire che il Quantum Device non e' in grado di ricreare anche gli ambienti esterni se questi non vengono prima ricreati nel computer. In un certo senso e' come se la struttura si trovasse all'interno di un buco nero, dove l'intero edificio molto presto sara' completamente distrutto dall'oscurità, che eliminera' ogni traccia di materia. E' quello che accade tutte le volte che ricreate un mondo parallelo. E' fortemente instabile e all'arrivo dell'oscurità implodera' tutto e probabilmente sara' inghiottito in una dimensione dove non c'e' ne spazio, ne tempo, ne luce, ne materia. Questa e' quantomeno l'ipotesi piu' plausibile, anche se e' presto per dirlo, perche' siete ancora agli esordi di questa nuova tecnologia.";
            acaso();
            cin>>x;
            goto label1;
            break;
        case '6':
            databin.azioni++;
            if(var==false)
            {
                system("cls");
                cout<<endl<<"CORRIDOIO";
                cout<<endl<<"Un lungo corridorio che porta dritto alla Control Room.";
                cout<<endl<<"Vedi Alice.";
                cout<<endl<<"<< Nick, per fortuna sei qui. Ho bisogno del tuo aiuto. Manca la corrente del generatore E, puoi andare ad attivarlo? E' importante che sia attivo perche' ci permette di comunicare con il mondo reale e di attivare l'Access Gate. Se non e' attivo non abbiamo nessuna speranza di tornare nel nostro mondo. >>"<<endl;
                acaso();
                cin>>x;
                system("cls");
                cout<<endl<<"CORRIDOIO";
                cout<<endl<<"<< Nick, a che punto sei con il generatore? Lo hai attivato? >>"<<endl;
                acaso();
                cin>>x;
                system("cls");
                cout<<endl<<"CORRIDOIO";
                cout<<endl<<"<< Nick, torna quando hai attivato il generatore, per ora non c'e' altro. >>"<<endl;
                acaso();
                goto label1;
            }
            else{
                system("cls");
                cout<<endl<<"CORRIDOIO";
                cout<<endl<<"Un lungo corridorio che porta dritto alla Control Room.";
                cout<<endl<<"Vedi Alice.";
                cout<<endl<<"<< Nick, per fortuna sei qui, sei riuscito a attivare il generatore!! Grazie a questo possiamo aprire un passaggio nascosto.  >>"<<endl;
                acaso();
                cin>>x;
                system("cls");
                cout<<endl<<"PASSAGGIO NASCOSTO";
                cout<<endl<<"Per terra trovi una chiave una corda.(Puoi prenderne solo una)In fondo al passaggio trovi Carlos che chiede aiuto perché caduto in una caditoia di 20 metri."<<endl;
                cout<<endl<<"Lo aiuti?(Si No)"<<endl;
                cin>>x;
                if(x=="Si")
                {
                    system("cls");
                    cout<<endl<<"AIUTI CARLOS";
                    cout<<endl<<"Aiutandolo cadi anche tu e rimani in trappola"<<endl;
                    cout<<endl<<"GAME OVER";
                    databin.punti="max";
                    scrivoinfopartita();
                    cin>>x;
                    goto label4;
                    
                }
                else{
                    system("cls");
                    cout<<endl<<"PRENDI LA CHIAVE";
                    var2=true;
                    cout<<endl<<"carlos:<<Vai alla botola e scappa qua sta crollando tutto!"<<endl;
                    acaso();
                    cin>>x;
                    databin.completato=75;
                    scrivoinfopartita();
                    goto label1;
                }
                
            }
            break;
        case 'R':
            goto label0;
            break;
        case 'I':
            leggoinfopartita();
            cin>>x;
            goto label1;
            break;
        case 'A':
            appunti();
            break;
            
    }
label4:;
    leggoinfopartita();
}

void istruzioni()
{
    titolo();
    cout<<endl<<"- DURANTE LO SVOLGIMENTO DELLA PARTITA";
    cout<<endl<<"- Puoi ricominciare la partita inserendo il comando 'R'.";
    cout<<endl<<"- Puoi visualizzare lo stato della partita inserendo il comando 'I'.";
    cout<<endl<<"- Creare o Aggiornare i tuoi appunti inserendo il comando 'A'. ";
    cout<<endl<<"- Puoi continuare la partita inserendo il comando 'C'o qualsiasi altro comando.";
    
    cout<<endl<<endl<<endl<<"NOTA: Puoi visualizzare i tuoi appunti nel file denominato 'appuntidata.txt'";
    
    
}
int main()
{
    srand(time(NULL));
    int scelta;
    do
    {
        cout << "------------------------------------------------" << endl;
        cout << "-              QUANTICA Project°               -" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "- 1) Nuova partita                             -" << endl;
        cout << "- 2) Info partita precedente                   -" << endl;
        cout << "- 3) Appunti                                   -" << endl;
        cout << "- 4) Istruzioni                                -" << endl;
        cout << "- 5) Soluzione                                 -" << endl;
        cout << "- 0) Esci                                      -" << endl;
        cout << "------------------------------------------------" << endl;
        cout << endl << "- Scegli: ";
        cin >> scelta;
        
        switch (scelta)
        {
                
            case 1:
                gioca();
                break;
            case 2:
                leggoinfopartita();
                break;
            case 3:
                appunti();
                
                break;
            case 4:
                istruzioni();
                break;
            case 5:
                soluzione();
                break;
            case 0:
                cout<<endl<<"-!Uscita eseguita con sucesso.";
                break;
                
        }
        cout << endl;
        cout << "------------------------------------------------" << endl;
        cout << "- 1) Continua                                  -" << endl;
        cout << "- 0) Esci                                      -" << endl;
        cout << "------------------------------------------------" << endl;
        cout << endl << "- Scegli l'opzione desiderata: ";
        cin>>scelta;
        system("cls");
        
    } while(scelta!=0);
    
    cout << endl;
    cout << "------------------------------------------------" << endl;
    cout << "-               QUANTICA Project°              -" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "-  Grazie per aver utilizzato questo software  -" << endl;
    cout << "-                                              -" << endl;
    cout << "-  Edited by: Ramolivaz André                  -" << endl;
    cout << "------------------------------------------------" << endl;
    return 0;
}


