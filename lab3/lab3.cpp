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
    int indeks;

    public:
    Osoba(string n, string im, int in) 
    {
        nazwisko = n;
        imie = im;
        indeks = in;
    }


    string getNazwisko()
    {
        return nazwisko;
    }

    string getImie()
    {
        return imie;
    }

    int getIndeks() 
    {
        return indeks;
    }

    void setNazwisko(string s_nazwisko)
    {
        nazwisko = s_nazwisko;
    }
    void setImie(string s_imie)
    {
        imie = s_imie;
    }
    void setIndeks(int s_indeks)
    {
        indeks = s_indeks;
    }

        void wyswietl()
        {
            cout << nazwisko << " " << imie << " " << indeks << endl;
        }
};

Osoba* studenci[ilosc_osob] = {};



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


    void ustawObecnosc(int indeks, bool obecnosc) {
    for (int i = 0; i < rozmiar; i++)
    {
        if (tablicaOsob[i] != nullptr && tablicaOsob[i]->getIndeks() == indeks)
            {
                tablicaObecnosci[i] = obecnosc;
            }
    }   
}

void usunzlisty(int indeks) 
{
    for (int i = 0; i < ilosc_osob; i++)
    {
        if (tablicaOsob[i] != nullptr && tablicaOsob[i]->getIndeks() == indeks)
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
            cout << tablicaOsob[i]->getNazwisko() << " " << tablicaOsob[i]->getImie() << " " << tablicaOsob[i]->getIndeks() << " ";

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
    int iloscList;

void wyswietlListeStudentow(Osoba* studenci[]) 
{
   int count = 0;
   for (int i = 0; i < ilosc_osob; i++)
   {
    if (studenci[i] != nullptr)
    {
        studenci[i]->wyswietl();
        count++;
    }
    
   }
   if (count == 0)
   {
    cout << "Lista studentów jest pusta.\n";
   }
   
}

Osoba* wyszukajPoIndeksie(int indeks) {
    for (int i = 0; i < ilosc_osob; i++)
    {
        if (studenci[i] != nullptr && studenci[i] -> getIndeks() == indeks)
        {
            return studenci[i];
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

void dodajStudenta(string nazwisko, string imie, int indeks) {
    for (int i = 0; i < ilosc_osob; i++)
    {
        if (studenci[i] == nullptr)
        {
            studenci[i] = new Osoba(nazwisko, imie, indeks);
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
            cout << "Dodano liste o numerze: " << i << " do bazy list\n";
            return;
        }
    }
    cout << "Lista pelna\n";
}

    void loop() 
    {
        
    string t_nazwisko, t_imie;
    int t_indeks, input, wybrana_lista;

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

    cin >> input;
    switch (input)
    {
    case 1: //Dodaj Osobe

    cout << "Podaj nazwisko: \n";
    cin >> t_nazwisko;
    cout << "Podaj imie: \n";
    cin >> t_imie;
    cout << "Podaj indeks: \n";
    cin >> t_indeks;

    dodajStudenta(t_nazwisko, t_imie, t_indeks);

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
            cin >> wybrana_lista;
            cout << "\n";

            switch (wybrana_lista) //Wyswietl
            {
            case 1:
                tablicaList[numerListy - 1]->wyswietl();
                break;

            case 2: //Dodaj
            {
                cout << "Podaj indeks osoby do dodania: ";
                cin >> t_indeks;
                Osoba* o = wyszukajPoIndeksie(t_indeks);
                if (o != nullptr)
                    tablicaList[numerListy - 1]->dodajOsobe(o);
                break;
            }

            case 3: //Zmien
            {
                int t_indeks, zmiana;
                cout << "Podaj indeks osoby: ";
                cin >> t_indeks;
                cout << "1. Obecny\n";
                cout << "2. Nieobecny\n";
                cout << "Wybrana opcja: ";
                cin >> zmiana;

                if (zmiana == 1)
                    tablicaList[numerListy - 1]->ustawObecnosc(t_indeks, true);
                else if (zmiana == 2)
                    tablicaList[numerListy - 1]->ustawObecnosc(t_indeks, false);
                else
                    cout << "Nieprawidlowa opcja.\n";
                break;
            }

            case 4: //Usun
            {
                int t_indeks;
                cout << "Podaj indeks osoby do usuniecia: ";
                cin >> t_indeks;
                tablicaList[numerListy - 1]->usunzlisty(t_indeks);
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
        
        wyswietlListeStudentow(tablicaOsob);
        break;
        
case 5: //Edytuj dane osoby w bazie

{
    int zmiana, nowyIndeks;
    
    cout << "\n";
    cout << "1: Zmien nr Indeksu\n";
    cout << "2: Zmien Imie\n";
    cout << "3: Zmien Nazwisko\n";
    cout << "4: Koniec\n";
    cout << "\n";
    
    cin >> zmiana;

        cout << "Podaj indeks osoby, ktorej dane chcesz zmienic: \n";
        cin >> t_indeks;
        Osoba* osoba = wyszukajPoIndeksie(t_indeks);

        if (osoba == nullptr)
        {
            cout << "Nie znaleziono osoby o takim indeksie.\n";
            break;
        }
        
        
        switch (zmiana)
        {

        case 1:
            cout << "Podaj nowy nr indeksu:\n";
            cin >> nowyIndeks;
            osoba->setIndeks(nowyIndeks);
            break;
        case 2:
            cout << "Podaj nowe nazwisko: \n";
            cin >> t_nazwisko;
            osoba->setNazwisko(t_nazwisko);
            break;
        case 3:
            cout << "Podaj nowe imie: \n";
            cin >> t_imie;
            osoba->setImie(t_imie);
            break;

        case 4:
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



ListaObecnosci* listy[ilosc_list] = {};
int liczbaList = 0;

int main() {

    Osoba* tablicaOsob[ilosc_osob] = {};          
    ListaObecnosci* tablicaList[ilosc_list] = {};  

    InterfejsUzytkownika ui(tablicaOsob, ilosc_osob, tablicaList, ilosc_list);  
    ui.loop();

    return 0;
}


//Mozliwosc tworzenia oddzielnych list obecnosci/Można sprobowac stworzyć pętle podczas której będzie można dodawać osoby zeby nie wpisywac ciagle listy