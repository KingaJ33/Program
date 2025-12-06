// Program.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
 #include <stdlib.h>
using namespace std;

float FtoC(float stopnie);
float FtoK(float stopnie);
float CtoF(float stopnie);
float CtoK(float stopnie);
float KtoC(float stopnie);
float KtoF(float stopnie);
float wyswietlanie(int x);
float pobierzF();
float pobierzC();
float pobierzK();
float check(float temp, char stopnie);
void historia(float stara, float nowa, char stary, char nowy);




float F, K, C;
int opcja;
double tab[100] = { 0 };
char tab2[100] = { 0 };
int dataCounter = 0;


int main()
{

    while (true) {

        system("cls");

        cout << "MENU " << endl;
        cout << "Wybierz: " << endl;
        cout << "1 - przelicz Fahr->Celsius\n2 - przelicz Fahr->Kelwin\n3 - przelicz Celsius->Fahr\n4 - przelicz Celsius->Kelwin\n5 - przelicz Kelwin->Celsius\n6 - przelicz Kelwin->Fahr\n7 - zakoncz dzialanie programu\n ";
        cout << "Wybrano: ";
        cin >> opcja;

        if (opcja == 7) {
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

        if (opcja < 1 || opcja > 7) {
            cout << "Nieznana opcja!" << endl;
        }


        cout << "\nNacisnij ENTER, aby wrocic do menu ";
        cin.ignore(); 
        cin.get();

       
       
    }
   
    return 0;
}

void historia(float stara, float nowa, char stary, char nowy) {

    if (dataCounter < 99) {

        tab[dataCounter] = stara;
        tab2[dataCounter] = stary;
        tab[dataCounter + 1] = nowa;
        tab2[dataCounter + 1] = nowy;


        dataCounter += 2;
        cout << "Zapisano wynik do historii" << endl;
    }
    else {
        cout << "Tablica historii jest pelna!" << endl;
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

    case 7:
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

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
