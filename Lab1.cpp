#include <iostream>
#include <string>
#define N 10
using namespace std;

void dodajOsobe(string *tabNazwisko, string Nazwisko) {
    for (int i = 0; i < N; i++)
    {
        if (tabNazwisko[i] == "")
        {
            tabNazwisko[i] = Nazwisko;
            return;
        }
    }
    cout << "Lista pełna\n";
}

void ustawImie(string *tabImie, string Imie) {

    for (int i = 0; i < N; i++)
    {
        if (tabImie[i] == "")
        {
            tabImie[i] = Imie;
            return;
        }
        
    }
    

}

void ustawIndeks(int *tabIndeks, int Indeks) {

    for (int i = 0; i < N; i++)
    {
        if (tabIndeks[i] == 0)
        {
            tabIndeks[i] = Indeks;
            return;
        }
        
    }
    

}

void ustawObecnosc(int *tabIndeks, bool *tabObecnosc, int Indeks, bool Obecnosc) {
    for (int i = 0; i < N; i++)
    {
        if (tabIndeks[i] == Indeks)
        {
            tabObecnosc[i] = Obecnosc;
            return;
        }
        
    }
    
    cout << "Nieobecny\n";

}

void drukujListe(int *tabIndeks, string *tabImie, string *tabNazwisko, bool *tabObecnosc) {


cout << "Nr Indeksu\tImie\tNazwisko\tObecnosc\n";

    for (int i = 0; i < N; i++)
    {
        if (tabNazwisko[i] != "")
        {
            cout << "\n";
            cout << tabIndeks[i] << "\t";
            cout << tabImie[i] << "\t";
            cout << tabNazwisko[i] << "\t";
                if (tabObecnosc[i])
                {
                    cout << "1";
                }
                else
                    {
                        cout << "0";
                    }
                cout << "\n";

        }
        
    }
    
cout << endl;

}

int main() {


    string tabNazwisko[N];
    bool tabObecnosc[N] = {0};
    int tabIndeks[N] = {0};
    string tabImie[N];
    string Nazwisko;
    bool Obecnosc;
    int Indeks;
    string Imie;
    int input;

    while(true) {

    cout << "\n";
    cout << "1: Dodaj nr Indeksu\n";
    cout << "2: Dodaj Imie\n";
    cout << "3: Dodaj Nazwisko\n";
    cout << "4: Ustaw Obecność\n";
    cout << "5: Wyświetl\n";
    cout << "6: Koniec\n";
    cout << "\n";

    cin >> input;

    switch (input)
    {
    case 1:
        cout << "Podaj nr indeksu: \n";
        cin >> Indeks;
        ustawIndeks(tabIndeks, Indeks);
        break;

    case 2:
        cout << "Podaj imie \n";
        cin >> Imie;
        ustawImie(tabImie, Imie);
        break;

    case 3:
        cout << "Podaj nazwisko: \n";
        cin >> Nazwisko;
        dodajOsobe(tabNazwisko, Nazwisko);
        break;

    case 4:
        cout << "Podaj nr Indeksu\n";
        cin >> Indeks;
        cout << "Obecność: \n";
        cin >> Obecnosc;
        ustawObecnosc(tabIndeks, tabObecnosc, Indeks, Obecnosc);
        break;

    case 5:
        drukujListe(tabIndeks, tabImie, tabNazwisko, tabObecnosc);
        break;

    case 6:
       return 0;

    default:
       cout << "Brak opcji\n";
    }
    
}
    return 0;
}