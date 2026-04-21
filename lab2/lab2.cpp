// Tablica w której są obiekty klasy osoba, powizac z informacja czy dana osoba jest czy danej osoby nie ma, dodać funkcję sprawdzenia obecnosci, utrzymujemy dwie tablice, w jednej lista osob w drugiej obecnosci
//dom: takich list obecnosci w naszym programie moze byc wiecej niz jedna, gdzie nazwisko indeks staja sie wskaznikami, wskazniki na obiekty, tablica osob to tablica wskaznikow, tablica 10 wskaznikow na obiekt klasy osoba - mozliwosc posiadania jednego obiektu jan kowalski do wszystkichlist, wartosc na lobecnosci1 1 np a na lobecnosci2 0 i to tak jakby okej, żeby nie duplikować w kółko osób
// Tablice, wskazniki, podstawowe uzywanie klas, poskladac i zobaczyc jak bedzie dzialac [zmiana na tablice wskaznikow nie obiektow]
#include <iostream>
#include <string>
#define N 10 // max osob
using namespace std;

class Osoba
{
    private: 
    string nazwisko;
    string imie;
    int indeks;

    public:
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


void dodajOsobe(Osoba** tabOsoby, string nazwisko, string imie, int indeks)
{

    for (int i = 0; i < N; i++)
    {
        if (tabOsoby[i]->getNazwisko() == "")
        {
            tabOsoby[i]->setNazwisko(nazwisko);
            tabOsoby[i]->setImie(imie);
            tabOsoby[i]->setIndeks(indeks);
        
            return;
        }
        
    }

    cout << "Brak miejsca w tablicy.\n";

}

void ustawObecnosc(Osoba** tabOsoby, bool* obecnosc, int indeks, bool czy_obecny)
{
    bool znaleziono = false;

    for (int i = 0; i < N; i++)
    {
        if (tabOsoby[i]->getIndeks() == indeks)
        {
            obecnosc[i] = czy_obecny;
            znaleziono = true;
        }
        
    }
    
    if (znaleziono)
    {
        cout << "Obecnosc zaktualizowana\n";
    }

    else
    cout << "Osoba nie znaleziona\n";
    
}

void edytuj(Osoba* osoba, int zmiana)
{
   string noweNazwisko, noweImie;
   int nowyIndeks;
            
        switch (zmiana)
        {
        case 1:
            cout << "Podaj nowy nr indeksu:\n";
            cin >> nowyIndeks;
            osoba->setIndeks(nowyIndeks);
            break;
        case 2:
            cout << "Podaj nowe nazwisko: \n";
            cin >> noweNazwisko;
            osoba->setNazwisko(noweNazwisko);
            break;
        case 3:
            cout << "Podaj nowe imie: \n";
            cin >> noweImie;
            osoba->setImie(noweImie);
            break;

        case 4:
        break;

    }

}

void wyswietlListe(Osoba** tabOsoby, bool* obecnosci)
{
    for (int i = 0; i < N; i++)
    {
        if (tabOsoby[i]->getNazwisko() != "")
        {
            tabOsoby[i]->wyswietl();
            cout << "Obecny: " << (obecnosci[i] ? "TAK" : "NIE") << endl;
        }
        
    }
    

    return;

}

Osoba* wyszukajPoIndeksie(Osoba** tab, int szukanyIndeks)
{

for (int i = 0; i < N; i++)
{
    if (tab[i]->getNazwisko() != "" && tab[i]->getIndeks() == szukanyIndeks)
    {
        return tab[i];
    }
    
}

return nullptr;

}


int main() {

Osoba *tabOsoby[N];
bool tabObecnosci[N];

for(int i = 0; i < N; ++i) 
{
    tabOsoby[i] = new Osoba();
}

string nazwisko, imie;
int indeks, input;

    while(true) {

    cout << "\n";
    cout << "1: Dodaj Osobe\n";
    cout << "2: Wyświetl\n";
    cout << "3: Zmien dane\n";
    cout << "4: Sprawdz obecnosc\n";
    cout << "5: Koniec\n";
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

    dodajOsobe(tabOsoby, nazwisko, imie, indeks);

    break;

    case 2:
        wyswietlListe(tabOsoby, tabObecnosci);
        break;

    case 3:
    {
    int zmiana, indeks;

    cout << "\n";
    cout << "1: Zmien nr Indeksu\n";
    cout << "2: Zmien Nazwisko\n";
    cout << "3: Zmien Imie\n";
    cout << "4: Koniec\n";
    cout << "\n";

    cin >> zmiana;

    if (zmiana == 4) break;

    cout << "Podaj indeks: ";
    cin >> indeks;

    Osoba* osobaDoEdycji = wyszukajPoIndeksie(tabOsoby, indeks);
        if (osobaDoEdycji != nullptr)
        {
            edytuj(osobaDoEdycji, zmiana);
        }

        break;
}

    case 4:
{
    int szukanyIndeks, czy_obecny;
    cout << "Podaj indeks: ";
    cin >> szukanyIndeks;
    cout << "Obecnosc [0/1]: ";
    cin >> czy_obecny;

    ustawObecnosc(tabOsoby, tabObecnosci, szukanyIndeks, czy_obecny);
    
    break;
}

    case 5:
      return 0;
    }
    
}
    return 0;
}
