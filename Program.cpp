// Program.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <stdlib.h>
#include "headerFile.h"

using namespace std;

void historia2();
void usuwanie();
void modyfikacja();


float F, K, C;
int opcja;
double tab[6] = { 0 };
char tab2[6] = { 0 };
int dataCounter = 0;


int main()
{

    while (true) {

        system("cls");

        cout << "MENU " << endl;
        cout << "Wybierz: " << endl;
        cout << "1 - przelicz Fahr->Celsius\n2 - przelicz Fahr->Kelwin\n3 - przelicz Celsius->Fahr\n4 - przelicz Celsius->Kelwin\n5 - przelicz Kelwin->Celsius\n6 - przelicz Kelwin->Fahr\n7 - pokaz historie\n8 - usun wpis z historii\n9 - modyfikacja wpisu z historii\n-1 - zakoncz dzialanie programu\n ";
        cout << "Wybrano: ";
        cin >> opcja;

        if (opcja == -1) {
            return 0;
        }


        float wynik_sprawdzenia;
        float wynik_koncowy = 0;
        bool wybrano_przeliczanie = false;


        if (opcja == 1 || opcja == 2) {
            pobierzF();
            wynik_sprawdzenia = check(F, 'F');

            if (wynik_sprawdzenia != -999.0) {
                
                wynik_koncowy = wyswietlanie(opcja);

                if (opcja == 1) {
                    historia(F, wynik_koncowy, 'F', 'C');
                }
                else if (opcja == 2) {
                    historia(F, wynik_koncowy, 'F', 'K');
                }
            }

        }
        if (opcja == 3 || opcja == 4) {
            pobierzC();
            wynik_sprawdzenia = check(C, 'C');

            if (wynik_sprawdzenia != -999.0) {

                wynik_koncowy = wyswietlanie(opcja);

                if (opcja == 3) {
                    historia(C, wynik_koncowy, 'C', 'F');
                }
                else if (opcja == 4) {
                    historia(C, wynik_koncowy, 'C', 'K');
                }
            }

        }
        if (opcja == 5 || opcja == 6) {
            pobierzK();
            wynik_sprawdzenia = check(K, 'K');

            if (wynik_sprawdzenia != -999.0) {

                wynik_koncowy = wyswietlanie(opcja);

                if (opcja == 5) {
                    historia(K, wynik_koncowy, 'K', 'C');
                }
                else if (opcja == 6) {
                    historia(K, wynik_koncowy, 'K', 'F');
                }
            }

        }

        if (opcja == 7) {
            historia2();

        }

        if (opcja == 8) {
            usuwanie();
        }

        if (opcja == 9) {
            modyfikacja();
        }

        if (opcja < -1 || opcja > 9) {
            cout << "Nieznana opcja!" << endl;
        }


        cout << "\nNacisnij ENTER, aby wrocic do menu ";
        cin.ignore(); 
        cin.get();


    }
   
    return 0;
}


void historia(float stara, float nowa, char stary, char nowy) {

    if (dataCounter < 6) {

        tab[dataCounter] = stara;
        tab2[dataCounter] = stary;
        tab[dataCounter + 1] = nowa;
        tab2[dataCounter + 1] = nowy;


        dataCounter += 2;
        cout << "Zapisano wynik do historii" << endl;
    }
    else {
        cout << "WARNING: Tablice historii sa pelne! Wynik wyswietlony, ale nie zapisany w historii." << endl;
    }
}


float FtoC(float stopnie) { 
    float wynik = (5.0 / 9.0) * (stopnie - 32.0);
    return wynik;
}

float FtoK(float stopnie) {
    float wynik = (stopnie + 459.67) * 5.0 / 9.0;
    return wynik;
}

float CtoF(float stopnie) {
    float wynik = stopnie * 9.0 / 5.0 + 32.0;
    return wynik;
}

float CtoK(float stopnie) {
    float wynik = stopnie + 273.15;
    return wynik;
}

float KtoC(float stopnie) {
    float wynik = stopnie - 273.15;
    return wynik;
}

float KtoF(float stopnie) {
    float wynik = stopnie * 9.0 / 5.0 - 459.67;
    return wynik;
}

float wyswietlanie(int x) {
    float fahr = F, celsius = C, kelwin = K;
    float wynik;

    switch (x) {
    case 1:
        wynik = FtoC(fahr);
        cout << fahr << "   " << wynik << endl;

        break;

    case 2:

        wynik = FtoK(fahr);
        cout << fahr << "   " << wynik << endl;

        break;

    case 3:

        wynik = CtoF(celsius);
        cout << celsius << "   " << wynik << endl;

        break;

    case 4:

        wynik = CtoK(celsius);
        cout << celsius << "   " << wynik << endl;

        break;

    case 5:

        wynik = KtoC(kelwin);
        cout << kelwin << "   " << wynik << endl;

        break;

    case 6:

        wynik = KtoF(kelwin);
        cout << kelwin << "   " << wynik << endl;

        break;

    case -1:
        return 0;

    default:
        return 0;

    }

    return wynik;
}

float pobierzF() {
    cout << "Podaj temperature do przeliczenia \n";
    cin >> F;
    return F;
}

float pobierzC() {
    cout << "Podaj temperature do przeliczenia  \n";
    cin >> C;
    return C;
}

float pobierzK() {
    cout << "Podaj temperature do przeliczenia  \n";
    cin >> K;
    return K;
}

float check(float temp, char stopnie) {

   if (temp < 0 && stopnie == 'K') {
       cout << "Nie ma takiej temperatury.Jesli ta funkcja nie zwroci - 999.0 w wyniku, to oznacza, ze to co zwrocila jest prawidlowa temperatura i mozna jej uzyc do przeliczenia." << endl;
       return -999.0;
   }

   if (temp < -273.15 && stopnie == 'C') {
       cout << "Nie ma takiej temperatury.Jesli ta funkcja nie zwroci - 999.0 w wyniku, to oznacza, ze to co zwrocila jest prawidlowa temperatura i mozna jej uzyc do przeliczenia." << endl;
       return -999.0;
   }

   if (temp < -459.67 && stopnie == 'F') {
       cout << "Nie ma takiej temperatury.Jesli ta funkcja nie zwroci - 999.0 w wyniku, to oznacza, ze to co zwrocila jest prawidlowa temperatura i mozna jej uzyc do przeliczenia." << endl;
       return -999.0;
   }

   return temp;
}


void historia2() {
    system("cls");

    int x;
    bool czy_jest_wynik = false;

    cout << "HISTORIA" << endl;
    cout << "Wybierz opcje: " << endl;
    cout << " 1. Tylko C- > inne\n 2. Tylko F-> inne\n 3. Tylko K-> inne\n 4. Cala historia\n";
    cin >> x;

    for (int i = 0; i < (dataCounter / 2); i++) {

        int iS = i * 2;      
        int iN = i * 2 + 1;  
        bool pokazac = false;

        
        if (x == 4) {
            pokazac = true;
        }
        else if (x == 1 && tab2[iS] == 'C') {
            pokazac = true;
        }
        else if (x == 2 && tab2[iS] == 'F') {
            pokazac = true;
        }
        else if (x == 3 && tab2[iS] == 'K') {
            pokazac = true;
        }

        if (pokazac == true) {
            cout << " < " << i << " > " << tab[iS] << tab2[iS] << " = " << tab[iN] << tab2[iN] << endl;
            czy_jest_wynik = true;
        }

    }

    if (czy_jest_wynik == false) {
        cout << "brak danych" << endl;
    }

}


void usuwanie() {
    system("cls");

    cout << "USUWANIE Z HISTORII" << endl;

    if (dataCounter == 0) {
        cout << "Historia jest pusta. Nie ma co usuwac." << endl;
        return; 
    }

    for (int i = 0; i < (dataCounter / 2); i++) {
        int iS = i * 2;
        int iN = i * 2 + 1;
      
        cout << i + 1 << ". " << tab[iS] << tab2[iS] << " = " << tab[iN] << tab2[iN] << endl;
    }

    int entityToRemove;
    cout << "Podaj numer linii do usuniecia: " << endl;
    cin >> entityToRemove;

    if (entityToRemove > 0 && entityToRemove <= (dataCounter / 2)) {

        int indexDoUsuniecia = entityToRemove * 2 - 2;

        for (int j = indexDoUsuniecia; j < dataCounter - 2; j++) {
            tab[j] = tab[j + 2];
            tab2[j] = tab2[j + 2];
        }

        cout << "Usunieto wpis nr " << entityToRemove << "." << endl;
    }
    else {
        cout << "Taki wpis nie istnieje!" << endl;
    }

}

void modyfikacja() {
    system("cls");
    cout << "MODYFIKACJA HISTORII" << endl;

    if (dataCounter == 0) {
        cout << "Historia jest pusta." << endl;
        return;
    }

    for (int i = 0; i < (dataCounter / 2); i++) {
        int iS = i * 2;
        int iN = i * 2 + 1;
        cout << i + 1 << ". " << tab[iS] << tab2[iS] << " -> " << tab[iN] << tab2[iN] << endl;
    }

    int nr;
    cout << "Podaj numer wpisu do modyfikacji: ";
    cin >> nr;

    int maxNr = dataCounter / 2;
    if (nr < 1 || nr > maxNr) {
        cout << "Niepoprawny numer wpisu!" << endl;
        return;
    }

    int iS = (nr - 1) * 2;    
    int iN = (nr - 1) * 2 + 1;

    float nowatemp;
    char nowaskala1;

    cout << "Podaj nowa wartosc temperatury " << endl;
    cin >> nowatemp;

    cout << "Podaj nowa skale dla tej temperatury (C, F, K) " << endl;
    cin >> nowaskala1;

    float test = check(nowatemp, nowaskala1);
    if (test == -999.0) {
        
        return;
    }

    char skala2;
    cout << "Na jaka skale przeliczyc temperature? (C, F, K)" << endl;
    cin >> skala2;

    float nowywynik;
    bool przeliczono = false;

    if (nowaskala1 == 'C') {
        if (skala2 == 'F') { 
            nowywynik = CtoF(nowatemp); 
            przeliczono = true;
        }
        else if (skala2 == 'K') { 
            nowywynik = CtoK(nowatemp);
            przeliczono = true;
        }
        else if (skala2 == 'C') { 
            nowywynik = nowatemp; 
            przeliczono = true;
        }
    }

    if (nowaskala1 == 'F') {
        if (skala2 == 'K') {
            nowywynik = FtoK(nowatemp);
            przeliczono = true;
        }
        else if (skala2 == 'C') {
            nowywynik = FtoC(nowatemp);
            przeliczono = true;
        }
        else if (skala2 == 'F') {
            nowywynik = nowatemp;
            przeliczono = true;
        }
    }

    if (nowaskala1 == 'K') {
        if (skala2 == 'C') {
            nowywynik = KtoC(nowatemp);
            przeliczono = true;
        }
        else if (skala2 == 'F') {
            nowywynik == KtoF(nowatemp);
            przeliczono = true;
        }
        else if (skala2 == 'K') {
            nowywynik = nowatemp;
            przeliczono = true;
        }
    }
    if (przeliczono) {
        
        tab[iS] = nowatemp;
        tab2[iS] = nowaskala1;

        tab[iN] = nowywynik;
        tab2[iN] = skala2;

        cout << "Zmodyfikowany wpis: "
            << tab[iS] << tab2[iS] << " -> " << tab[iN] << tab2[iN] << endl;
    }
    else {
        cout << "Blad: Nieznana kombinacja skal!" << endl;
    }
}





// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
