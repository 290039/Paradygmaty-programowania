#include <iostream>
#include <string>

using namespace std;

class Osoba
{
    private: 
    string nazwisko;
    string imie;


    public: 
    Osoba() 
    {};
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

    virtual void drukuj()
        {

        cout << " Osoba: " << imie;

        };
};


class Student : public Osoba 
{

    private:
    int nr_indeksu;

    public:

        void drukuj()
         override {

        cout << " Student: " << getImie();

        };
};

class Stazysta : public Osoba 
{

    private:
    int nr_id;

    public:

     void drukuj()
       override {

        cout << " Stazysta " << getImie();

        };
};



int main()
{
    Osoba os;
    os.setImie("Jan");

    Student st;
    st.setImie("Natalia");

    Stazysta staz;
    staz.setImie("Bartosz");

    os.drukuj();
    st.drukuj();
    staz.drukuj();

    Osoba *tab[2];
    tab[0] = &os;
    tab[1] = &st;
    tab[3] = &staz;

    tab[0]->drukuj();
    tab[1]->drukuj();
    tab[3]->drukuj();

return 0;
}

// interfejs drukowalny zaimplementowac do klasy osoba student Stazysta a po stronie dodomu: uzycie/wykorzystanie interfejsu
// funkcja drukuj dostaje wskaznik na class drukowalny wykorzystac interfejs zeby odwolac sie do INTERFEJS
//definicja metody, dziedziczenie po klasach ktory interfejs definiuje, uzaleznienie dzialania jakiejs metody od klasy interfejsowym
//ZADANIE Wprowadzic interfejs, rozbudowac program o jeszcze jedna klase, student zaoczny-wszystkie atrybuty takie same ale przedstawia się inaczej, pozostale elementy wszystkie takie same jak byly, interfejs drukowallny ma byc polimorficzny, metoda zdefiniowana jest metoda abstrakcyjna nie posiada w klasie interfejsowej 
