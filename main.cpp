#include <iostream>
using namespace std;

struct str
{
    int duom;
    str *next;
    str *atgal;
};
str *temp;
str *temp2;
str *head;
str *last; /// naujas sukuriamas
str *saugo;
int kiekis;

void kurti()
{
    int sk;

    cout << "Elementu kiekis: ";
    cin >> kiekis;

    for(int i=1; i<=kiekis; i++)
    {
        last = new str;
        cout << "Iveskite " << i << "-a elementa: ";
        cin >> sk;
        last -> duom = sk;
        last -> next = NULL;
        if(i==1)
        {
            head = last;
            head -> atgal = NULL;
        }
        else
        {
            temp -> next = last;
            saugo = temp;

        }
        temp = last;
        temp -> atgal = saugo;

    }
}

void pirma()
{

    last = new str;
    last -> atgal = NULL;
    last -> next = head;
    head -> atgal = last;
    head = last;




    cout<<"Iveskite skaiciu kuri norite prideti:"<<endl;
    cin>>head -> duom;
    kiekis++;
    cout<<"ELEMENTAS PRIDETAS"<<endl;
}

void paskutine()
{
    temp = head;
    while(temp -> next != NULL)
    {

        temp = temp -> next;
    }
    last = new str;
    temp -> next = last;
    last -> atgal = temp;
    last -> next = NULL;
    cout<<"Iveskite skaiciu kuri norite prideti:"<<endl;
    cin>>last -> duom;
    kiekis++;
    cout<<"ELEMENTAS PRIDETAS"<<endl;
}

void nurodyta()
{
    temp = head;
    int ikel=0;
    cout<<"I kuria vieta?"<<endl;
    cin >> ikel;


    if(ikel == 1)
    {
     pirma();
    }

    if( ikel < kiekis) /// Jei 1, tai naudoti iskviesti funkcija
    {

        last = new str;

        for(int i=2; i<=ikel; i++)
        {
            if(i == ikel)
            {
                cout<<"Iveskite skaiciu kuri norite prideti:"<<endl;
                cin>>last -> duom;
                last -> next = temp -> next;
                last -> atgal = temp;
                temp -> next = last;
                last = last -> next;
                temp = temp -> next;
                last -> atgal = temp;
                cout<<"ELEMENTAS PRIDETAS"<<endl;
                kiekis++;
            }
            temp = temp -> next;
        }

    }


}



void poskaiciaus()
{
    temp = head;
    int ikel;
    cout<<"Po kuriuo skaiciumi noretumete ikelti skaiciu?"<<endl;
    cin >> ikel;
    while(temp -> duom != ikel)
    {
        temp = temp -> next;
    }
    last = new str;


    cout<<"Iveskite skaiciu kuri norite prideti:"<<endl;
    cin>>last -> duom;
    last -> next = temp -> next;
    last -> atgal = temp;
    temp -> next = last;
    last = last -> next;
    temp = temp -> next;
    last -> atgal = temp;
    cout<<"ELEMENTAS PRIDETAS"<<endl;
    kiekis++;
}

void istrinti()
{
    if(kiekis == 1)
    {
        delete head;
        cout<<"Elementu nera"<<endl;
        kiekis--;
    }
    else
    {
        temp = head;
        head = head -> next;
        head ->atgal = NULL;


        kiekis--;
        delete temp;
        cout<<"PIRMAS ELEMENTAS ISTRINTAS"<<endl;
    }

}

void trintipagalelementa()
{
    temp = head;
    //temp2 = head;

    int ikel;
    cout<<"Kuria vieta noretume istrinti?"<<endl;
    cin >> ikel;
    if(ikel == 1)
    {
        cout<<"Naudokite kita funkcija"<<endl;
    }
    else
    {

        while(temp -> duom != ikel-1)
        {
            temp = temp -> next;
            cout<<"ikelt"<<temp ->duom <<endl;
        }
        saugo = temp ->next;
        temp -> next = temp -> next -> next;
        temp = temp -> next;
        temp -> atgal = temp -> atgal -> atgal;
        delete saugo;
        kiekis--;

        cout<<"ELEMENTAS ISTRINTAS"<<endl;

    }

}

void spausdinti()
{
    temp = head;
    if(kiekis == 0)
    {
        cout<<"SARASAS TUSCIAS"<<endl;
    }
    else
    {
        for(int i=1; i<=kiekis; i++)
        {

            cout <<"->"<< temp -> duom << endl;
            temp = temp -> next;
        }
    }

    /*while(temp -> next != NULL)
    {
      cout <<"->"<< temp -> duom << endl;
            temp = temp -> next;
    }
    cout <<"->"<< temp -> duom << endl;
            temp = temp -> next; */



}

void atbulinis()
{
    temp = head;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    while(temp -> atgal != NULL)
    {
        cout<< temp -> duom <<endl;
        temp = temp -> atgal;

    }
    cout<< temp -> duom <<endl;

}

int main()
{
    int kuris, kartui=0;
    char pabaiga = 'n';
    while(pabaiga == 'n')
    {

        if(kartui == 0)
        {
            cout<<"Sukuriamas tiesinis sarasas"<<endl;
            kuris = 1;
        }
        if(kartui > 0)
        {
            cout<<"---------------------------------------"<<endl;
            cout<<"Kuri veiksma pirma noretumete vykdyti?"<<endl;
            cout<<"2- iterpti elementa i saraso pradzia"<<endl;
            cout<<"3- iterpti elementa i saraso pabaiga"<<endl;
            cout<<"4- iterpti elementa i numeriu nurodyta pozicija"<<endl;
            cout<<"5- iterpti elementa po tam tikro skaiciaus"<<endl;
            cout<<"6- isspausdinti tiesini sarasa"<<endl;
            cout<<"7- istrinti elemnta is saraso pradzios"<<endl;
            cout<<"8- istrinti elemnta pagal vieta ?"<<endl;
            cout<<"9- atspausdinti is kitos puses"<<endl;
            cout<<"---------------------------------------"<<endl;
            cin >> kuris;
        }



        switch(kuris)
        {

        case 1:
            cout<<"-----------"<<endl;
            kurti();
            kartui++;

            break;
        case 2:
            cout<<"-----------"<<endl;
            pirma();
            break;
        case 3:
            cout<<"-----------"<<endl;
            paskutine();
            break;
        case 4:
            cout<<"-----------"<<endl;
            nurodyta();
            break;
        case 5:
            cout<<"-----------"<<endl;
            poskaiciaus();
            break;
        case 6:
            cout<<"-----------"<<endl;
            spausdinti();
            break;
        case 7:
            cout<<"-----------"<<endl;
            istrinti();
            break;
        case 8:
            cout<<"-----------"<<endl;
            trintipagalelementa();
            break;
        case 9:
            cout<<"-----------"<<endl;
            atbulinis();
            break;
        default:
            cout<<"Tokio pasirinkimo nera"<<endl;
        }

        cout<<"Jei norite isjungti programa, parasykite : [t], jei ne, tai [n]"<<endl;
        cin >> pabaiga;
    }





    return 0;
}
