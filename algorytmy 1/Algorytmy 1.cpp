#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#define maxsize 100
using namespace std;

string palList[maxsize];
int sizeoflist = 0;


// zad 1
class Tablica {
    int **tab;
    int n;
    int m;
public:
    Tablica(int n, int m)
    {
        this->n = n;
        this->m = m;

        tab = new int*[n];
        for (int i = 0; i < n; i++) {
            tab[i] = new int[m];
        }
    }

    void Randomorg(int x) {
        // losowanie = rand()% x;
        for (int i=0; i < n; i++) {
            for (int y=0; y < m; y++)
            {
                tab[i][y] = rand() % x;
            }
        }
    }
    void Wyswietlanie()
    {
        for (int i = 0; i < n; i++) {
            cout << "\n";
            for (int y = 0; y < m; y++)
            {
                cout << tab[i][y]<< " ";
            }
        }
    }
    int Max()
    {
        int max = tab[0][0];
        for (int i = 0; i < n; i++) {
            for (int y = 0; y < m; y++)
            {
                if (max < tab[i][y])
                {
                    max = tab[i][y];
                }
            }
        }
        return max;
    }

};

// zad 2
void addStringElement(string* tab, int &size, string element) {
    if (size < maxsize) {
        tab[size] = element;
        size++;
        cout << "Dodano element: " << element << endl;
    }
    else {
        cout << "Nie mozna dodac elementu - osiagnieto maksymalny rozmiar tablicy" << endl;
    }
}
void saveStringToFile(string tab[maxsize], int size, string filename) {
    ofstream file(filename);

    if (file.is_open()) {
        for (int i = 0; i < size; i++) {
            file << tab[i] << endl;
        }

        file.close();
        cout << "Tablica stringow zostala zapisana do pliku " << filename << endl;
    }
    else {
        cout << "Nie udalo sie otworzyc pliku " << filename << endl;
    }
}
void loadStringFromFile(string* tab, string filename) {
    ifstream file(filename);


    if (file.is_open()) {
        int size = 0;

        while (!file.eof() && size < maxsize) {
            string temp;
            getline(file, temp);
            tab[size] = temp;
            size++;
        }

        file.close();
        cout << "Tablica stringow zostala wczytana z pliku " << filename << endl;
    }
    else {
        cout << "Nie udalo sie otworzyc pliku " << filename << endl;
    }
}
void saveStringToBinaryFile(string tab[maxsize], int size, string filename) {
    ofstream file(filename, ios::out | ios::binary);

    if (file.is_open()) {
        for (int i = 0; i < size; i++) {
            int length = tab[i].length();
            file.write((char*)&length, sizeof(length));
            file.write(tab[i].c_str(), length);
        }

        file.close();
        cout << "Tablica stringow zostala zapisana do pliku " << filename << endl;
    }
    else {
        cout << "Nie udalo sie otworzyc pliku " << filename << endl;
    }
}
void loadStringFromBinaryFile(string* tab, string filename) {
    ifstream file(filename, ios::in | ios::binary);

    if (file.is_open()) {
       int size = 0;

        while (!file.eof() && size < maxsize) {
            int length;
            file.read((char*)&length, sizeof(length));
            file.read((char*)tab[size].c_str(), length);
            size++;
        }

        file.close();
        cout << "Tablica stringow zostala wczytana z pliku " << filename << endl;
    }
    else {
        cout << "Nie udalo sie otworzyc pliku " << filename << endl;
    }
}
// zad 3
int potega(int x, int p)
{
    
    if (p == 0)
    {
        return 1;
    }
    else if (p==1)
    {
        return x;
    }
    else if (p > 0)
    {
        return (x * potega(x, p - 1));
    }
    else if (p < 0)
    {
        return 0;
    }
}
int silnia(int x)
{
    if (x == 1)
    {
        return x;
    }
    else
    {
        return x * silnia(x - 1);
    }
}
// zad 4
bool jestPal(string tekst)
{
    
    if (tekst.length() == 1)
    {
        return true;
    }
    if (tekst.length() == 2)
    {
        if (tekst[0] = tekst[1])
        {
            return true;
        }
        else {
            return false;
        }

    }
    if (tekst[0] == tekst[tekst.length() - 1])
    {
        return jestPal(tekst.substr(1,tekst.length() - 2));
    }
    else
    {
        return false;
    }

}
// zad 5
void permutuj(string tekst, int poz = 0) {

 
    if (poz == tekst.size()) {
        cout << tekst <<" ";
         if (jestPal(tekst))
    {
        if (sizeoflist == maxsize) {
            cout << "Brak miejsca na ten palindrom w tablicy.\n";
        }
        cout << "jest palindromem";
        palList[sizeoflist] = tekst;
        sizeoflist++;
    }
         cout << "\n";
    }
    else {
        for (int i = poz; i < tekst.size(); i++) {
            swap(tekst[i], tekst[poz]);
            permutuj(tekst, poz + 1);
            swap(tekst[i], tekst[poz]);
        }
    }
    }
void usunDup() {

    string templist[maxsize];
    int sizeoftemplist = 0;

    for (int i = 0; i < sizeoflist; i++)
    {
        bool jestDup = false;

        for (int y = 0; y < sizeoftemplist; y++)
        {
            if (palList[i] == templist[y])
            {
                jestDup = true;
            }
        }
        if (!jestDup) {
            templist[sizeoftemplist++] = palList[i];
        }
    }
    for (int x = 0; x < sizeoflist; x++)
    {
        palList[x] = templist[x];
    }
    sizeoflist = sizeoftemplist;

}
void wyswpal()
{
    for (int x = 0; x < sizeoflist; x++)
    {
        cout << palList[x] << "\n";
    }
}
//zad 8
class ListaJ {
public:
    ListaJ(){
    }
    float value;
    ListaJ *next;
};

class ListF {
    ListaJ* first = nullptr;
    int _size = 0;

public:
    ListF() {
    }
    void addValue(float x)
    {
        ListaJ *nazwa = new ListaJ;
        
        nazwa->value = x;
        nazwa->next = nullptr;
        if (first == nullptr)
        {
            first = nazwa;
        }
        else {
        ListaJ *temp = first;
            for (int i = 0; i < _size-1; i++)
            {
                temp = temp->next;
            }
            temp->next = nazwa;
        }
        _size += 1;
    }
    void wysw()
    {
        ListaJ nazwa = *first;
        for (int i = 0; i < _size; i++)
        {
            cout << nazwa.value << "\n";
            if (nazwa.next != nullptr) {
                nazwa = *nazwa.next;
            }

        }
    }
    void usunAll()
    {
        ListaJ temp = *first;
        int tempsize = _size;
        for (int i = 0; i < tempsize; i++)
        {
            ListaJ* temp = first;
            for (int y = 0; y < _size - 1; y++)
            {
                temp = temp->next;
            }
        delete temp;
        _size -= 1;
        }
        first = nullptr;
    }
    void usunEl(float element)
    {
      
        if (first == nullptr) {
            cout << "Lista jest pusta";
        }
        else {
           
            if (first->value == element) {
                ListaJ* temp = first;
                first = first->next;
                delete temp;
                _size--;          
            }
            else {
                ListaJ* temp2 = first;
                while (temp2->next != nullptr) {
                    if (temp2->next->value == element) {
                        ListaJ* temp = temp2->next;
                        temp2->next = temp2->next->next;
                        delete temp;
                        _size--;  
                    }
                   temp2 = temp2->next;
                }
            }
            if (_size == 0)
            {
                first = nullptr;
            }
        }
    }
};

class Kolejka {
   
    ListaJ* first = nullptr;
    int _size = 0;
public:
    Kolejka() {
    }
    void addValue(float x)
    {
        ListaJ* nazwa = new ListaJ;

        nazwa->value = x;
        nazwa->next = nullptr;
        if (first == nullptr)
        {
            first = nazwa;
        }
        else {
            ListaJ* temp = first;
            for (int i = 0; i < _size - 1; i++)
            {
                temp = temp->next;
            }
            temp->next = nazwa;
        }
        _size += 1;
    }

    void wysw()
    {
        ListaJ nazwa = *first;
        for (int i = 0; i < _size; i++)
        {
            cout << nazwa.value << "\n";
            if (nazwa.next != nullptr) {
                nazwa = *nazwa.next;
            }

        }
    }
    void usunAll()
    {
        int tempsize = _size;
        for (int i = 0; i < tempsize; i++)
        {
            usun();
        }
    }
    
void usun()
    {
     ListaJ* tmp = first->next;
     float tempp = first->value;
     delete first;
  
     if (_size == 0)
     {
         cout << "brak elementów w kolejce";
     }
     else{
     first = tmp;
     }
    
     cout << "usunieto :" << tempp <<"\n";
     _size--;
     if (_size == 0)
     {
         first = nullptr;
     }
    }
};

int main()
{
    srand(time(NULL));
    int m = 10;
    int n = 10;
    int x;
    string element;
    int size = 0;
    string tab[maxsize];
    string tab1[maxsize];
    string tab2[maxsize];
    string filename;
    Tablica Tablica(n, m);
   /* 
    Kolejka kol;
    kol.addValue(123);
    kol.addValue(1233);
    kol.addValue(1253);
    kol.addValue(1243);
    kol.wysw();
    kol.usunAll();
    kol.addValue(123343);
    kol.wysw();
    cout << potega(5,3)<<"\n";
    cout << potega(3,3) << "\n";
    cout << silnia(3) << "\n";
    cout << silnia(4) << "\n";
    cout <<  jestPal("kajak") <<"\n";
    cout <<  jestPal("kajck") << "\n";
    ListF Kamil;
    Kamil.addValue(3);
    Kamil.addValue(4);
    Kamil.addValue(5);
    Kamil.wysw();
    Kamil.usunEl(4);
    Kamil.usunAll();
    permutuj("kajak");
    usunDup();
    wyswpal();
    Kamil.addValue(1);
    Kamil.wysw();*/
    
    //// menu
  /*  int choice = 0;
    while (choice != 9) {
        cout << "Menu: " << endl;
        cout << "1. Dodaj element do tablicy" << endl;
        cout << "2. Zapisz tablicę do pliku tekstowego" << endl;
        cout << "3. Wczytaj tablicę z pliku tekstowego" << endl;
        cout << "4. Zapisz tablicę do pliku binarnego" << endl;
        cout << "5. Wczytaj tablicę z pliku binarnego" << endl;
        cout << "6. Wypełnij tablice losowymi liczbami" << endl;
        cout << "7. Wyswietl tablice" << endl;
        cout << "8. Znajdz max element" << endl;
        cout << "9. Wyjście" << endl;

        cout << "Wybierz opcję: ";
        do
        {
            cin >> choice;
        } while (cin.get() != '\n');
       

        switch (choice) {
        case 1:
            cout << "Wprowadz element: \n";
            getline(cin, element);
            addStringElement(tab, size, element);
           break;
        case 2:
            cout << "Podaj nazwę pliku: ";
            getline(cin, filename);
            saveStringToFile(tab, size, filename);
            break;
        case 3:
            cout << "Podaj nazwę pliku: ";
            getline(cin, filename);
            loadStringFromFile(tab1, filename);
            break;
        case 4:
            cout << "Podaj nazwę pliku: ";
            getline(cin, filename);
            saveStringToBinaryFile(tab, size, filename);
            break;
        case 5:
            cout << "Podaj nazwę pliku: ";
            getline(cin, filename);
            loadStringFromBinaryFile(tab2, filename);
            break;
 
        case 6:
            cout << "podaj zakres liczb (0-x)";
            cin >> x;
            
            Tablica.Randomorg(x);
            break;
        case 7:
            Tablica.Wyswietlanie();
            break;
        case 8:
            cout << Tablica.Max() <<"\n";
            break;

        case 9:
            return 0;
        default:
            cout << "Nieprawidłowa opcja, wybierz jeszcze raz." << endl;
        }
    }*/

    ////koniec menu
    ListF Kamil;
    Kamil.addValue(3);
    Kamil.addValue(4);
    Kamil.addValue(5);
    Kamil.wysw();
    Kamil.usunEl(3);
    Kamil.wysw();
   

    return 0;

}

