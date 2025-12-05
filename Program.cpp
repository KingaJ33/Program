// Program.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
using namespace std;

float FtoC(float stopnie);
float FtoK(float stopnie);
float CtoF(float stopnie);
float CtoK(float stopnie);
float KtoC(float stopnie);
float KtoF(float stopnie);
void wyswietlanie(int x);

int main()
{
    int opcja;

    cout << "Wybierz: " << endl;
    cout << "1 - przelicz Fahr->Celsius\n2 - przelicz Fahr->Kelwin\n3 - przelicz Celsius->Fahr\n4 - przelicz Celsius->Kelwin\n5 - przelicz Kelwin->Celsius\n6 - przelicz Kelwin->Fahr\n7 - zakoncz dzialanie programu\n ";
    cin >> opcja;

    if (opcja == 1 || opcja == 2) {
        cout << "Podaj temperature do przeliczenia w F \n";
        

    }
    
    wyswietlanie(opcja);

   
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
    float fahr, celsius, kelwin;

    switch (x) {
    case 1:
        for (fahr = 0.0; fahr <= 200; fahr = fahr + 20) {
            celsius = FtoC(fahr);
            cout << fahr << "   " << celsius << endl;
        }
        break;

    case 2:
        for (fahr = 0.0; fahr <= 200; fahr = fahr + 20) {
            kelwin = FtoK(fahr);
            cout << fahr << "   " << kelwin << endl;
        }
        break;

    case 3:
        for (celsius = 0.0; celsius <= 200; celsius = celsius + 20) {
            fahr = CtoF(celsius);
            cout << celsius << "   " << fahr << endl;
        }
        break;

    case 4:
        for (celsius = 0.0; celsius <= 200; celsius = celsius + 20) {
            kelwin = CtoK(celsius);
            cout << celsius << "   " << kelwin << endl;
        }
        break;

    case 5:
        for (kelwin = 0.0; kelwin <= 200; kelwin = kelwin + 20) {
            celsius = KtoC(kelwin);
            cout << kelwin << "   " << celsius << endl;
        }
        break;

    case 6:
        for (kelwin = 0.0; kelwin <= 200; kelwin = kelwin + 20) {
            fahr = KtoF(kelwin);
            cout << kelwin << "   " << fahr << endl;
        }
        break;

    case 7:
        return ;

    default:
        return ;

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
