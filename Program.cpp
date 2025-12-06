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
void wyswietlanie(int x);
float pobierzF();
float pobierzC();
float pobierzK();
float check(float temp, char stopnie);



float F, K, C;
int opcja;

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
        bool wybrano_przeliczanie = false;


        if (opcja == 1 || opcja == 2) {
            pobierzF();
            wynik_sprawdzenia = check(F, 'F');

            if (wynik_sprawdzenia != -999.0) {
                wyswietlanie(opcja);
            }

        }
        if (opcja == 3 || opcja == 4) {
            pobierzC();
            wynik_sprawdzenia = check(C, 'C');

            if (wynik_sprawdzenia != -999.0) {
                wyswietlanie(opcja);
            }

        }
        if (opcja == 5 || opcja == 6) {
            pobierzK();
            wynik_sprawdzenia = check(K, 'K');

            if (wynik_sprawdzenia != -999.0) {
                wyswietlanie(opcja);
            }

        }
        cout << "\nNacisnij ENTER, aby wrocic do menu ";
        cin.ignore(); 
        cin.get();

    }
   
    return 0;
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

void wyswietlanie(int x) {
    float fahr = F, celsius = C, kelwin = K;


    switch (x) {
    case 1:
        celsius = FtoC(fahr);
        cout << fahr << "   " << celsius << endl;

        break;

    case 2:

        kelwin = FtoK(fahr);
        cout << fahr << "   " << kelwin << endl;

        break;

    case 3:

        fahr = CtoF(celsius);
        cout << celsius << "   " << fahr << endl;

        break;

    case 4:

        kelwin = CtoK(celsius);
        cout << celsius << "   " << kelwin << endl;

        break;

    case 5:

        celsius = KtoC(kelwin);
        cout << kelwin << "   " << celsius << endl;

        break;

    case 6:

        fahr = KtoF(kelwin);
        cout << kelwin << "   " << fahr << endl;

        break;

    case 7:
        return;

    default:
        return;

    }
}

float pobierzF() {
    cout << "Podaj temperature do przeliczenia w stopniach Fahrenheita \n";
    cin >> F;
    return F;
}

float pobierzC() {
    cout << "Podaj temperature do przeliczenia w stopniach Celsjusza \n";
    cin >> C;
    return C;
}

float pobierzK() {
    cout << "Podaj temperature do przeliczenia w stopniach Kelwina \n";
    cin >> K;
    return K;
}

float check(float temp, char stopnie) {

   if (temp < 0 && stopnie == 'K') {
       cout << "Nie ma takiej temperatury.Jeśli ta funkcja nie zwróci - 999.0 w wyniku, to oznacza, że to co zwróciła jest prawidłowątemperaturą i można jej użyć do przeliczenia." << endl;
       return -999.0;
   }

   if (temp < -273.15 && stopnie == 'C') {
       cout << "Nie ma takiej temperatury.Jeśli ta funkcja nie zwróci - 999.0 w wyniku, to oznacza, że to co zwróciła jest prawidłowątemperaturą i można jej użyć do przeliczenia." << endl;
       return -999.0;
   }

   if (temp < -459.67 && stopnie == 'F') {
       cout << "Nie ma takiej temperatury.Jeśli ta funkcja nie zwróci - 999.0 w wyniku, to oznacza, że to co zwróciła jest prawidłowątemperaturą i można jej użyć do przeliczenia." << endl;
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
