// Program.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <stdlib.h>
#include "headerFile.h"

using namespace std;

void historia2();
void usuwanie();
void modyfikacja();
void losowe();
int convertToInteger(const char vector[], int size);
double convertToDouble(const char vector[], int size);


bool conversionFailed = false;
float F, K, C;
int opcja;
double tab[100] = { 0 };
char tab2[100] = { 0 };
int dataCounter = 0;


int main()
{
    srand(time(NULL));

    while (true) {
        char tempStr[280];

        system("cls");

        cout << "MENU " << endl;
        cout << "Wybierz: " << endl;
        cout << "1 - przelicz Fahr->Celsius\n2 - przelicz Fahr->Kelwin\n3 - przelicz Celsius->Fahr\n4 - przelicz Celsius->Kelwin\n5 - przelicz Kelwin->Celsius\n6 - przelicz Kelwin->Fahr\n7 - pokaz historie\n8 - usun wpis z historii\n9 - modyfikacja wpisu z historii\n10 - losowe wypelnianie historii\n-1 - zakoncz dzialanie programu\n ";
        cout << "Wybrano: ";
        cin >> tempStr;
        opcja = convertToInteger(tempStr, 280);

        if (conversionFailed) {
            cout << "To nie jest poprawna opcja menu! Sprobuj jeszcze raz." << endl;
            cout << "\nNacisnij ENTER, aby wrocic do menu ";
            cin.ignore();
            cin.get();
            continue;
        }

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

        if (opcja == 10) {
            losowe();
        }

        if (opcja < -1 || opcja > 10) {
            cout << "Nieznana opcja!" << endl;
        }


        cout << "\nNacisnij ENTER, aby wrocic do menu ";
        cin.ignore(); 
        cin.get();


    }
   
    return 0;
}


int convertToInteger(const char vector[], int size) {
    int result = 0;
    bool isNegative = false;
    conversionFailed = false;

    for (int i = 0; i < size; ++i) {
        if (vector[i] == '\0') break;

        if (isdigit(vector[i])) {
            result = result * 10 + (vector[i] - '0');
        }
        else if (vector[i] == '-' && i == 0) {
            isNegative = true;
        }
        else if (vector[i] == '+' && i == 0) {
            continue;
        }
        else {
            conversionFailed = true;
            cout << "Blad: Niepoprawny znak w liczbie calkowitej!" << endl;
            break;
        }
    }
    return isNegative ? -result : result;
}

double convertToDouble(const char vector[], int size) {
    double result = 0.0;
    double fractionalMultiplier = 0.1;
    bool isNegative = false;
    bool isFractional = false;
    bool signRecognised = false;
    conversionFailed = false;

    for (int i = 0; i < size; ++i) {
        if (vector[i] == '\0') break;

        if (isdigit(vector[i])) {
            if (isFractional) {
                result += (vector[i] - '0') * fractionalMultiplier;
                fractionalMultiplier *= 0.1;
            }
            else {
                result = result * 10.0 + (vector[i] - '0');
            }
        }
        else if ((vector[i] == '.' || vector[i] == ',') && !isFractional) {
            isFractional = true;
        }
        else if (vector[i] == '-' && !signRecognised) {
            isNegative = true;
            signRecognised = true;
        }
        else if (vector[i] == '+' && !signRecognised) {
            signRecognised = true;
            continue;
        }
        else {
            conversionFailed = true;
            cout << "Blad: Niepoprawny format liczby zmiennoprzecinkowej!" << endl;
            break;
        }
    }
    return isNegative ? -result : result;
}


void historia(float stara, float nowa, char stary, char nowy) {

    if (dataCounter < 100) {

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
    char str[280];
    do {
        cout << "Podaj temperature (Fahrenheit) do przeliczenia: ";
        cin >> str;
        F = (float)convertToDouble(str, 280);
        if (conversionFailed) cout << "To nie jest prawidlowy zapis liczby! Sprobuj ponownie." << endl;
    } while (conversionFailed);
    return F;
}

float pobierzC() {
    char str[280];
    do {
        cout << "Podaj temperature (Celsius) do przeliczenia: ";
        cin >> str;
        C = (float)convertToDouble(str, 280);
        if (conversionFailed) cout << "To nie jest prawidlowy zapis liczby! Sprobuj ponownie." << endl;
    } while (conversionFailed);
    return C;
}

float pobierzK() {
    char str[280];
    do {
        cout << "Podaj temperature (Kelvin) do przeliczenia: ";
        cin >> str;
        K = (float)convertToDouble(str, 280);
        if (conversionFailed) cout << "To nie jest prawidlowy zapis liczby! Sprobuj ponownie." << endl;
    } while (conversionFailed);
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
    cout << "Wybrano: ";
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

        dataCounter -= 2;

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

void losowe() {
    system("cls");

    int los;
    int odp;
    cout << "LOSOWE WYPELNIANIE HISTORII" << endl;
    cout << "Podaj ile losowych wartosci przeliczyc?"<< endl;
    cout << "Wybrano: " << endl;
    cin >> los;


    if ((dataCounter + los * 2) > 100) {

        int wolneMiejsca = 100 - dataCounter;
        int ileMozna = wolneMiejsca / 2;

        cout << "Brak miejsca na " << los << " wpisow. Zostalo miejsca na " << ileMozna << "." << endl;
        cout << "Czy wygenerowac tylko tyle losowek ile zostalo miejsca (wybierz 1), czy nie (wybierz 0)?" << endl;
        cin >> odp;

        if (odp == 0) {
            return;
        }
        else if (odp == 1) {
            los = ileMozna; 
        }
        else {
            cout << "Niepoprawna odpowiedz - anulowano." << endl;
            return;
        }
    }

    for (int i = 0; i < los; i++) {

       
        int losSkala = rand() % 3;
        char zrodloChar = ' ';
        int x = 0;
        double temp = 0;

        
        if (losSkala == 0) { // C
            zrodloChar = 'C';
            
            x = -273 + (rand() % 1001);
        }
        else if (losSkala == 1) { // F
            zrodloChar = 'F';
           
            x = -459 + (rand() % 1001);
        }
        else if (losSkala == 2) { // K
            zrodloChar = 'K';
           
            x = 0 + (rand() % 1001);
        }

  
        temp = (double)x;

        
        char celChar = ' ';
        do {
            int losCel = rand() % 3;
            if (losCel == 0) celChar = 'C';
            if (losCel == 1) celChar = 'F';
            if (losCel == 2) celChar = 'K';
        } while (celChar == zrodloChar);

       
        double wynik = 0;
        if (zrodloChar == 'C') {
            if (celChar == 'F') wynik = CtoF(temp);
            if (celChar == 'K') wynik = CtoK(temp);
        }
        else if (zrodloChar == 'F') {
            if (celChar == 'C') wynik = FtoC(temp);
            if (celChar == 'K') wynik = FtoK(temp);
        }
        else if (zrodloChar == 'K') {
            if (celChar == 'C') wynik = KtoC(temp);
            if (celChar == 'F') wynik = KtoF(temp);
        }

       
        tab[dataCounter] = temp;
        tab2[dataCounter] = zrodloChar;
        tab[dataCounter + 1] = wynik;
        tab2[dataCounter + 1] = celChar;

        dataCounter += 2;
    }

    cout << "Wygenerowano " << los << " losowych przeliczen." << endl;
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
