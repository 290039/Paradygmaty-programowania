#include <iostream>
#include <string>
#define N 10 // max osob
#define M 10 // max list
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

Osoba* studenci[N] = {};

void dodajStudenta(string nazwisko, string imie, int indeks) {
    for (int i = 0; i < N; i++)
    {
        if (studenci[i] == nullptr)
        {
            studenci[i] = new Osoba(nazwisko, imie, indeks);
            return;
        }
    }
    cout << "Lista pełna\n";
}


Osoba* wyszukajPoIndeksie(Osoba* studenci[], int indeks) {
    for (int i = 0; i < N; i++)
    {
        if (studenci[i] != nullptr && studenci[i] -> getIndeks() == indeks)
        {
            return studenci[i];
        }
    }
    return nullptr;    
}

void wyswietlListeStudentow(Osoba* studenci[]) 
{
   int count = 0;
   for (int i = 0; i < N; i++)
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

class ListaObecnosci
{
    private:
        Osoba* osoby[N];
        bool obecnosc[N];
        int rozmiar;
        

    public:
        ListaObecnosci()
        {
            for (int i = 0; i < N; i++)
            {
                osoby[i] = nullptr;
                obecnosc[i] = false;
            }
        }

void dodajOsobę(Osoba* o)
    {
        if (rozmiar < N)
        {
            osoby[rozmiar] = o;
            rozmiar++;
        }

            else
                {
                    cout << "Lista pelna.\n";
                }
        
    }

    void ustawObecnosc(int indeks, bool sprawdzenie) {
    for (int i = 0; i < rozmiar; i++)
    {
        if (osoby[i] != nullptr && osoby[i]->getIndeks() == indeks)
            {
                obecnosc[i] = sprawdzenie;
            }
    }   
}

void wyswietl()
{
    for (int i = 0; i < rozmiar; i++)
    {
        if (osoby[i] != nullptr)
        {
            cout << osoby[i]->getNazwisko() << " " << osoby[i]->getImie() << " " << osoby[i]->getIndeks() << " ";

            if (obecnosc[i])
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

ListaObecnosci* listy[M] = {};
int liczbaList = 0;

int main() {

string nazwisko, imie;
int indeks, input;

    while(true) {

    cout << "\n";
    cout << "1: Dodaj Osobe\n";
    cout << "2: Wyświetl\n";
    cout << "3: Zmien dane\n";
    cout << "4: Stworz liste\n";
    cout << "5: Dodaj osobe do listy\n";
    cout << "6: Sprawdz obecnosc\n";
    cout << "7: Wyswietl\n";
    cout << "8: Koniec\n";
    cout << "\n";

    cin >> input;
    switch (input)
    {
    case 1:

    cout << "Podaj nazwisko: \n";
    cin >> nazwisko;
    cout << "Podaj imie: \n";
    cin >> imie;
    cout << "Podaj indeks: \n";
    cin >> indeks;

    dodajStudenta(nazwisko, imie, indeks);

    break;

    case 2:
        wyswietlListeStudentow(studenci);
        break;

    case 3:
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
        cin >> indeks;
        Osoba* osoba = wyszukajPoIndeksie(studenci, indeks);

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
            cin >> nazwisko;
            osoba->setNazwisko(nazwisko);
            break;
        case 3:
            cout << "Podaj nowe imie: \n";
            cin >> imie;
            osoba->setImie(imie);
            break;

        case 4:
        break;

    default:
       cout << "Brak opcji.\n";
       break;
        }

        break;
    }

    case 4: //Stworz liste
        if (liczbaList < M)
        {
            listy[liczbaList++] = new ListaObecnosci();
            cout << "Utworzono liste: " << liczbaList << endl;
        }
        break;
        
    case 5: //Dodaj osobe do listy
        {
        int numerListy;
        cout << "Podaj numer wybranej listy od 1 do " << liczbaList << ": ";
        cin >> numerListy;

        cout << "Podaj indeks osoby do dodania: ";
        cin >> indeks;
        Osoba* o = wyszukajPoIndeksie(studenci, indeks);
        
        listy[numerListy - 1]->dodajOsobę(o);

        cout << "Dodano osobę do listy.\n";
        }
         break;

    case 6: //Sprawdz obecnosc
{
    int numerListy;
    bool obecny;

    cout << "Podaj numer listy: ";
    cin >> numerListy;

    cout << "Podaj indeks: ";
    cin >> indeks;

    cout << "Obecnosc 0/1 ?";
    cin >> obecny;

    if (numerListy <= liczbaList)
    {
        listy[numerListy - 1]->ustawObecnosc(indeks, obecny);
    }

    break;
}
    
    case 7: //Wyswietl
{
    int numerListy;
    cout << "Podaj numer listy: ";
    cin >> numerListy;

    if (numerListy <= liczbaList)
    {
        listy[numerListy - 1]->wyswietl();
    }

    break;
}

    case 8:
      return 0;
    }
    
}
    return 0;
}


//Mozliwosc tworzenia oddzielnych list obecnosci/Można sprobowac stworzyć pętle podczas której będzie można dodawać osoby zeby nie wpisywac ciagle listy