#include <iostream>
#include <string>
#define ilosc_osob 10 // max osob
#define ilosc_list 2 // max list
using namespace std;

class Osoba
{
    private: 
    string nazwisko;
    string imie;

    public:
    Osoba(string n, string im) 
    {
        nazwisko = n;
        imie = im;
    }

    string getNazwisko()
    {
        return nazwisko;
    }

    string getImie()
    {
        return imie;
    }

    void setNazwisko(string s_nazwisko)
    {
        nazwisko = s_nazwisko;
    }
    void setImie(string s_imie)
    {
        imie = s_imie;
    }

        virtual void wyswietl()
        {
            cout << nazwisko << " " << imie << endl;
        }
};

class Student : public Osoba 
{

    private:
    int indeks;

    public:

Student(string n, string im, int in) : Osoba(n, im)
    {
        indeks = in;
    }

    int getIndeks()
    {
        return indeks;
    }

           void setIndeks(int s_indeks)
    {
        indeks = s_indeks;
    }

    virtual void wyswietl()
        {
            cout << getNazwisko() << " " << getImie() << " " << getIndeks() << endl;
        }

};

class Stazysta : public Osoba 
{

    private:
        int nr_id;

    public:

    Stazysta(string n, string im, int id) : Osoba(n, im)
    {
        nr_id = id;
    }

        int getId()
        {
            return nr_id;
        }

        void setId(int s_id)
        {
            nr_id = s_id;
        }

         virtual void wyswietl()
        {
            cout << getNazwisko() << " " << getImie() << " " << getId() << endl;
        }


};

class ListaObecnosci
{
    private:
        Osoba* tablicaOsob[ilosc_osob];
        bool tablicaObecnosci[ilosc_osob];
        int rozmiar = 0;
        

    public:
        ListaObecnosci()
        {
            for (int i = 0; i < ilosc_osob; i++)
            {
                tablicaOsob[i] = nullptr;
                tablicaObecnosci[i] = false;
            }
        }

void dodajOsobe(Osoba* o)
    {
        if (rozmiar < ilosc_osob)
        {
            tablicaOsob[rozmiar] = o;
            rozmiar++;
        }

            else
                {
                    cout << "Lista pelna.\n";
                }

    }


    void ustawObecnosc(string nazwisko, bool obecnosc) {
    for (int i = 0; i < rozmiar; i++)
    {
        if (tablicaOsob[i] != nullptr && tablicaOsob[i]->getNazwisko() == nazwisko)
            {
                tablicaObecnosci[i] = obecnosc;
            }
    }   
}

void usunzlisty(string nazwisko) 
{
    for (int i = 0; i < ilosc_osob; i++)
    {
        if (tablicaOsob[i] != nullptr && tablicaOsob[i]->getNazwisko() == nazwisko)
        {
            tablicaOsob[i] = nullptr;
            tablicaObecnosci[i] = false;
            cout << "Osoba została usunieta z listy\n";
        }
        
    }
    
}


void wyswietl()
{
    for (int i = 0; i < rozmiar; i++)
    {
        if (tablicaOsob[i] != nullptr)
        {
            cout << tablicaOsob[i]->getNazwisko() << " " << tablicaOsob[i]->getImie() << " \n";

            if (tablicaObecnosci[i])
            {
                cout << "Obecny";
            }
            else
            {
                cout << "Nieobecny";
            }

            cout << endl;
        }
    }
}

};

class InterfejsUzytkownika 
{

    private:
    Osoba **tablicaOsob;
    int iloscOsob;
    ListaObecnosci **tablicaList;
    int iloscList = 0;

void wyswietlListeOsob() 
{
   int count = 0;
   for (int i = 0; i < iloscOsob; i++)
   {
    if (tablicaOsob[i] != nullptr)
    {
        tablicaOsob[i]->wyswietl();
        count++;
    }
    
   }
   if (count == 0)
   {
    cout << "Lista osob jest pusta.\n";
   }
   
}

Osoba* wyszukajPoNazwisku(string nazwisko) {
    for (int i = 0; i < ilosc_osob; i++)
    {
        if (tablicaOsob[i] != nullptr && tablicaOsob[i] -> getNazwisko() == nazwisko)
        {
            return tablicaOsob[i];
        }
    }
    return nullptr;    
}    

    public:
    InterfejsUzytkownika(Osoba **tab_osob, int il_osob, ListaObecnosci **tab_list, int il_list)
{
    tablicaOsob = tab_osob;
    iloscOsob = il_osob;

    tablicaList = tab_list;
    iloscList = il_list;
}

void dodajOsobe(int typ_osoby, string nazwisko, string imie, int indeks, int nr_id) {
    for (int i = 0; i < ilosc_osob; i++)
    {
        if (tablicaOsob[i] == nullptr)
        {
            switch(typ_osoby)
            {
                case 1:
                tablicaOsob[i] = new Student(nazwisko, imie, indeks);
                break;

                case 2:
                tablicaOsob[i] = new Stazysta(nazwisko, imie, nr_id);
                break;

                default:
                tablicaOsob[i] = new Osoba(nazwisko, imie);
            }
            return;
        }

    }
    cout << "Lista pełna\n";
}

void dodajListe() {
    for (int i = 0; i < ilosc_list; i++)
    {
        if (tablicaList[i] == nullptr)
        {
            tablicaList[i] = new ListaObecnosci();
            iloscList++;
            cout << "Dodano liste o numerze: " << i+1 << " do bazy list\n";
            return;
        }
    }
    cout << "Lista pelna\n";
}

    void loop() 
    {
    
    int input = 0;
    string t_nazwisko, t_imie;
    int t_typ_osoby, t_indeks, t_nr_id, t_wybrana_lista;

    while(true) {

    cout << "\n";
    cout << "1: Dodaj Osobe do bazy osob\n";
    cout << "2: Dodaj liste obecnosci do bazy list\n";
    cout << "3: Wybierz liste obecnosci z ktora chcesz pracowac\n";
    cout << "4: Wyswietl baze osob\n";
    cout << "5: Edytuj dane osob w bazie\n";
    cout << "6: Zakoncz\n";
    cout << "Wybrana opcja: \n";

    cin >> input;
    
    cout << "\n";

    switch (input)
    {
    case 1: //Dodaj Osobe

    cout << "Kogo chcesz dodać?\n";
    cout << "1. Student\n";
    cout << "2. Stazysta\n";
    cin >> t_typ_osoby;

    cout << "Podaj nazwisko: \n";
    cin >> t_nazwisko;
    cout << "Podaj imie: \n";
    cin >> t_imie;
    if (t_typ_osoby == 1)
    {
        cout << "Podaj indeks studenta: \n";
        cin >> t_indeks;
        t_nr_id = 0;

    }

    else if (t_typ_osoby == 2)
    {
        cout << "Podaj numer id stazysty: \n";
        cin >> t_nr_id;
        t_indeks = 0;
    }
    
    

    dodajOsobe(t_typ_osoby, t_nazwisko, t_imie, t_indeks, t_nr_id);

    break;

case 2: //Dodaj liste obecnosci

        dodajListe();

        break;
    
case 3: //Wybierz liste obecnosci z ktora chcesz pracowac

        {
    if (iloscList == 0)
    {
        cout << "Brak list w bazie.\n";
        break;
    }

    int numerListy;
    cout << "Podaj numer listy (Od 1 do " << iloscList << "): ";
    cin >> numerListy;

    if (numerListy >= 1 && numerListy <= iloscList)
    {
        bool wyjdzZListy = false;

        while (!wyjdzZListy)
        {
            cout << "Pracujesz z listą o numerze: " << numerListy << endl;
            cout << "1. Wyswietl liste" << numerListy << endl;
            cout << "2. Dodaj osobe do listy " << numerListy << endl;
            cout << "3. Zmien obecnosc osoby na liscie " << numerListy << endl;
            cout << "4. Usun osobe z listy " << numerListy << endl;
            cout << "5. Powrot do menu glownego" << endl;
            cout << "Wybrana opcja: \n";
            cin >> t_wybrana_lista;
            cout << "\n";

            switch (t_wybrana_lista) //Wyswietl
            {
            case 1:
                tablicaList[numerListy - 1]->wyswietl();
                break;

            case 2: //Dodaj
            {
                cout << "Podaj nazwisko osoby do dodania: ";
                cin >> t_nazwisko;
                Osoba* o = wyszukajPoNazwisku(t_nazwisko);
                if (o != nullptr)
                    tablicaList[numerListy - 1]->dodajOsobe(o);
                break;
            }

            case 3: //Zmien
            {
                string nazwisko;
                int zmiana;
                cout << "Podaj nazwisko osoby: ";
                cin >> nazwisko;
                cout << "1. Obecny\n";
                cout << "2. Nieobecny\n";
                cout << "Wybrana opcja: ";
                cin >> zmiana;

                if (zmiana == 1)
                    tablicaList[numerListy - 1]->ustawObecnosc(nazwisko, true);
                else if (zmiana == 2)
                    tablicaList[numerListy - 1]->ustawObecnosc(nazwisko, false);
                else
                    cout << "Nieprawidlowa opcja.\n";
                break;
            }

            case 4: //Usun
            {
                string nazwisko;
                cout << "Podaj nazwisko osoby do usuniecia: ";
                cin >> nazwisko;
                tablicaList[numerListy - 1]->usunzlisty(nazwisko);
                break;
            }

            case 5:
                wyjdzZListy = true;
                break;

            default:
                cout << "Brak takiej opcji.\n";
                break;
            }
        }
    }
    else
    {
        cout << "Nieprawidlowy numer listy.\n";
    }
    break;
}

case 4: //Wyswietl baze osob
        
        wyswietlListeOsob();
        break;
        
case 5: //Edytuj dane osoby w bazie

{
    int zmiana;
    
    cout << "\n";
    cout << "1: Zmien Nazwisko\n";
    cout << "2: Zmien Imie\n";
    cout << "3: Koniec\n";
    cout << "\n";
    
    cin >> zmiana;

        cout << "Podaj nazwisko osoby, ktorej dane chcesz zmienic: \n";
        cin >> t_nazwisko;
        Osoba* osoba = wyszukajPoNazwisku(t_nazwisko);

        if (osoba == nullptr)
        {
            cout << "Nie znaleziono osoby o takim nazwisku.\n";
            break;
        }
        
        
        switch (zmiana)
        {

        case 1:
            cout << "Podaj nowe nazwisko: \n";
            cin >> t_nazwisko;
            osoba->setNazwisko(t_nazwisko);
            break;
        case 2:
            cout << "Podaj nowe imie: \n";
            cin >> t_imie;
            osoba->setImie(t_imie);
            break;

        case 3:
        break;

    default:
       cout << "Brak opcji.\n";
       break;
        }

        break;
    }

case 6: //Zakoncz
      return;
    }
    
}
}

};


int main() {

    Osoba* tablicaOsob[ilosc_osob] = {};          
    ListaObecnosci* tablicaList[ilosc_list] = {};  

    InterfejsUzytkownika ui(tablicaOsob, ilosc_osob, tablicaList, ilosc_list);  
    ui.loop();

    return 0;
}

//Zmiana z class lista indeks na nazwisko zal. ze nazwiska sie nie powtorza