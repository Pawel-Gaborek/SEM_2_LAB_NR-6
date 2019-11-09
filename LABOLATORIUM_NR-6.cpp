#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

//ponizej definiuje klase dla nazw zesolow. W tej klasie dla odmiany korzystam z konstruktora.
class TeamName
{
public:
    string nameOfTeam;
    //ponizej tworze kontruktor. Nawa musi byc taka sama jak nazwa klasy = "TeamName"
    TeamName(string Team_Name):
    nameOfTeam(Team_Name)
    {
        
    }
};

//ponizej definiuje klase dla pojedynczego zawodnika. W c++ praktycznie struktura i klasa sie niewiele roznia,
//jednak klasa mi umozliwa definiowanie dostepnu do ziennych
class PersonalOfPlayer
{
    //definiuje zmienne do ktorych jest ogolny dostep w klasie publicznej
public:
    string PlayerName;
    string PlayerSurname;
    string PlayerHeight;
    string PlayerAge;
    string PlayerPosition;
    
    //virtual PersonalOfPlayer* clone()
    //{
    //    return new PersonalOfPlayer(*this);
    //}
    
    PersonalOfPlayer* deepCopy(PersonalOfPlayer *playerNew)
    {
        return new PersonalOfPlayer(*playerNew);
    }
};

class CopyTeam
{
    //definiuje zmienne do ktorych jest ogolny dostep w klasie publicznej
public:
    string PlayerName;
    string PlayerSurname;
    string PlayerHeight;
    string PlayerAge;
    string PlayerPosition;
    
    CopyTeam (const PersonalOfPlayer &);
    //PersonalOfPlayer(const PersonalOfPlayer &);
};

//ponizej okreslam klase kopiujaca. Korzystam dodatkowo z konstruktora.
CopyTeam::CopyTeam(const PersonalOfPlayer &source)
{
    PlayerName=source.PlayerName;
    PlayerSurname=source.PlayerSurname;
    PlayerHeight=source.PlayerHeight;
    PlayerAge=source.PlayerAge;
    PlayerPosition=source.PlayerPosition;
}

class Team
{
public:
    //Ponizej tworze kontener dla zespolu pojedynczego ktory zawiera w sobie struktury informacji o
    //pojedynczych zawodnikach. Czyli wypelniam kontener "OneTeam" pojedynczym kontenerami = zawodnikami,
    //co czynie podajac liczbe iteracji w petli.
    //ponizej takze przekazuje informacje, że wypełnienie kontenera "OneTeam" bedzie dokonane poprzez
    //typ którym jest wektor "OnePlayer". Tak tworzę drużynę.
    
    Team (int Teams, int Players)
    {
        //vector<vector<PersonalOfPlayer>>OneTeam( Teams, vector<PersonalOfPlayer>( Players ) );
        //return OneTeam;
    };
    
    
};

int main()
{
    int PlayersNumber;
    int TeamNumbers;
    int team_number;
    int player_number;
    char choice2;
    char choice3;
    char choice4;
    char continuation;
    string GetTeamName;
    string nameTemp;
    int exit = 0;
    
    
    
    using namespace std;
    
    
    
    while(exit==0)
    {
        //ponizej definiuje wektor z nazwami druzyn. Wypelniam go inna metoda poprzez tzw "push backi"
        //vector<TeamName>teamTeam;
        //ponizej podaj w nawiasach < typ zmiennej > jakim bedzie wypelniony moj kontener jednego zawodnika.
        //Mogle wybrac integera, char itp., jednak na potrzeby programu pojedynczy kontener zawodnika nalezy
        //wypelnic innym typem, a mianowicie typem struktury z klasy ktora zostala utworzona i dodatkowo
        //zostal stworzony konstruktor "PersonalOfPlayer. W C++ struktura "struct" i klasa "class"
        //sa bardzo pododbne
        //vector<double>matrix;
        
        //ponizej tworze wektor ktory bedzie grupowac wszystkie zespoly do kontenerka "ChampionsLeage"
        
        cout << "Super ! Wlasnie uruchomiles program do labolatorium nr 6 na kierunku Informatyka\n";
        cout << "Program umozliwi Ci stworzenie macierzy.\n";
        cout << "Bedziesz mogl takze wykonac kilka dzialan na macierzach.\n";
        cout << "Powodzenia i fajnej zabawy przy tworzeniu macierzy.\n";
        cout << "\n\n\n";
        cout << "Podaj liczbe kolumn macierzy\n";
        cin >> TeamNumbers;
        cout << "\n Podaj liczbe wierszy\n";
        cin >> PlayersNumber;
        
        
        
        //ponizej definiuje wektor wielowymiarowy z okreslona liczba druzyn oraz zawodnikow
        
        vector<vector<PersonalOfPlayer>>matrix( TeamNumbers, vector<PersonalOfPlayer>( PlayersNumber ) );
        
        
        Team(TeamNumbers, PlayersNumber);
        
        //ponizej tworze petle w petli ktora ma zadanie dodac druzyny i zawodnikow do poszczegolnych druzyn
        for (int j=0 ; j<TeamNumbers ; j++)
        {
            
            cout << "\nPodaj nazwe druzyny nr:" << j+1 << endl;
            cin >> GetTeamName;
            teamTeam.push_back(TeamName(GetTeamName));
            
            for (int i=0 ; i<PlayersNumber ; i++)
            {
                cout << "\nPodaj nazwisko zawodnika nr\t" << i+1 << "\t dla druzyny numer:" << j+1 << ":\n";
                string name;
                cin >> name;
                OneTeam[j][i].PlayerName=name;
                
                cout << "\nPodaj imie zawodnika nr\t" << i+1 << "\t dla druzyny numer:" << j+1 << ":\n";
                string surname;
                cin >> surname;
                OneTeam[j][i].PlayerSurname=surname;
                
                cout << "\nPodaj wzrost zawodnika nr\t" << i+1 << "\t dla druzyny numer:" << j+1 << ":\n";
                string height;
                cin >> height;
                OneTeam[j][i].PlayerHeight=height;
                
                cout << "\nPodaj wiek zawodnika nr\t" << i+1 << "\t dla druzyny numer:" << j+1 << ":\n";
                string age;
                cin >> age;
                OneTeam[j][i].PlayerAge=age;
                
                cout << "\nPodaj pozycje zawodnika nr\t" << i+1 << "\t dla druzyny numer:" << j+1 << ":\n";
                string position;
                cin >> position;
                OneTeam[j][i].PlayerPosition=position;
            }
            //ponizej aby sprawdzic czy wprowadzilem poprawnie korzystam z petli iteracyjnej do wypisania
            //poszczegolnych danych pojedynczego zawodnika
            for ( int ii=0 ; ii<PlayersNumber ; ii++)
            {
                cout << "\nNazwisko zawodnika nr:\t" << ii+1 << " to " << OneTeam[j][ii].PlayerName;
                cout << "\nImie zawodnika nr:\t" << ii+1 << " to " << OneTeam[j][ii].PlayerSurname;
                cout << "\nWzrost zawodnika nr:\t" << ii+1 << " to " << OneTeam[j][ii].PlayerHeight;
                cout << "\nWiek zawodnika nr:\t" << ii+1 << " to " << OneTeam[j][ii].PlayerAge;
                cout << "\nPozycja zawodnika nr:\t" << ii+1 << " to " << OneTeam[j][ii].PlayerPosition;
            }
        }
        
        ///////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////
        //ponizej kopiuje do wektora mowa druzyne
        cout << "\n\n\nCzy chcesz utworzyc kolejna druzyne i skopiowac zawodnikow z ostatniej druzyny ??";
        cout << "\nW przypadku ponownego uruchomienia wpisz litere ''t'', w przerciwnym razie wpisz litere ''n''.\n";
        cin >> choice2;
        if (choice2 == 't')
        {
            
            cout << "\nPojemnosc wektora przed rozszerzeniem to:" << OneTeam.size();
            
            teamTeam.resize(TeamNumbers+1, TeamName(GetTeamName));
            
            OneTeam.resize(TeamNumbers+1, vector<PersonalOfPlayer>(PlayersNumber) );
            
            cout << "\nPojemnosc wektora nazwa druzyn po resize to:" << OneTeam.size();
            
            teamTeam[TeamNumbers+1].nameOfTeam=teamTeam[TeamNumbers].nameOfTeam;
            
            cout << "\nNazwa skopiowanej dryzyny to:" << teamTeam[TeamNumbers+1].nameOfTeam;
            
            TeamNumbers = TeamNumbers+1;
            
            cout << "\nIlosc zespolow wynosi:" << TeamNumbers;
            
            //*OneTeam[2][2].PlayerName = &OneTeam[0][0].PlayerName;
            
        }
        else
        {
            cout << "Niestety zdecydowales by nie dodawac kolejnej druzyny.";
            cout << "Ale masz ponizej jeszcze opcje wyswietlania druzyn i zawodnikow.";
        }
        
        ///////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////
        //ponizej wyswietlam wszystkich zawodnikow
        cout << "\n\n\nCzy chcesz wyswietlic zawodnikow ze wszystkich druzyn ??";
        cout << "\nW przypadku wyboru ''tak'' wpisz litere ''t'', w przerciwnym razie wpisz litere ''n''.\n";
        cin >> choice3;
        if (choice3 == 't')
        {
            for (int ij=0 ; ij<TeamNumbers  ; ij++)
            {
                cout << "\n\n\nZawodnicy druzyny " << teamTeam[ij].nameOfTeam << " maja nastepujace dane:\n";
                
                for ( int io=0 ; io<PlayersNumber ; io++)
                {
                    cout << "\nNazwisko zawodnika nr:\t" << io+1 << " to " << OneTeam[ij][io].PlayerName;
                    cout << "\nImie zawodnika nr:\t" << io+1 << " to " << OneTeam[ij][io].PlayerSurname;
                    cout << "\nWzrost zawodnika nr:\t" << io+1 << " to " << OneTeam[ij][io].PlayerHeight;
                    cout << "\nWiek zawodnika nr:\t" << io+1 << " to " << OneTeam[ij][io].PlayerAge;
                    cout << "\nPozycja zawodnika nr:\t" << io+1 << " to " << OneTeam[ij][io].PlayerPosition;
                }
            }
        }
        
        else
        {
            cout << "Niestety zdecydowales by nie wyswietlac calej listy druzyn i zawodnikow";
            cout << "Ale masz ponizej jeszcze jedna opcje do wyboru.";
        }
        
        ///////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////
        //ponizej wyswietlam okreslonego zawodnika
        cout << "\n\n\nCzy chcesz wyswietlic dane okreslonego zawodnika z okreslonej druzyny ??";
        cout << "W przypadku ponownego uruchomienia wpisz litere ''t'', w przerciwnym razie wpisz litere ''n''.\n";
        cin >> choice4;
        if (choice4 =='t')
        {
            cout << "Podaj numer druzyny ktorej dane zawodnika chcesz wyswietlic\n";
            cin >> team_number;
            cout << "Podaj numer zawodnika ktoreg dane chcesz wyswietlic\n";
            cin >> player_number;
            cout << "\nZawodnik druzyny " << teamTeam[team_number].nameOfTeam << " ma nastepujace dane:";
            cout << "\nNazwisko zawodnika:";
            cout << OneTeam[team_number-1][player_number-1].PlayerName << "\n" << endl;
            cout << "\nImie zawodnika:";
            cout << OneTeam[team_number-1][player_number-1].PlayerSurname << "\n" << endl;
            cout << "\nWzrost zawodnika:";
            cout << OneTeam[team_number-1][player_number-1].PlayerHeight << "\n" << endl;
            cout << "\nWiek zawodnika:";
            cout << OneTeam[team_number-1][player_number-1].PlayerAge << "\n" << endl;
            cout << "\nPozycja na boisku zawodnika:";
            cout << OneTeam[team_number-1][player_number-1].PlayerPosition << "\n" << endl;
        }
        else
        {
            cout << "Niestety, niechcesz dodac kolejnej druzyny, moze nastepnym razem";
        }
        ///////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////
        
        while(1)
        {
            cout << "\nProgram wlasnie zakonczyl swoje dzialanie";
            cout << "Czy chcesz uruchomic program ponownie ??";
            cout << "W przypadku ponownego uruchomienia wpisz litere ''t'', w przerciwnym razie wpisz litere ''n''.";
            cout << "Pamietaj ze wielkosc liter ma zmaczenie.\n\n\n";
            cin >> continuation;
            if(continuation=='t')
            {
                break;
            }
            else
            {
                cout << "Niestety podales bledna litere";
                cout << "Sproboj jeszcze raz";
            }
            
        }
        cout << "Szkoda ze nie chcesz ponownie uruchomic programu";
        cout << "Moze nastepnycm razem. Powodzenia !!!";
    }
    return 0;
}
