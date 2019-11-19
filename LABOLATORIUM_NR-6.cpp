#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

class matrix
{
    vector<vector<double>>matrix_matrix;
    int columns;
    int lines;

public:
    
    matrix(int columns, int lines)
    {
        vector<vector<double>>matrix_matrix(columns, vector<double>( lines ) );;
        for (int j=0 ; j<columns ; j++)
        {
            for (int i=0 ; i<lines ; i++)
            {
                matrix_matrix[j][i]=0;
            }
        }
        
    }

    
    matrix(int columns, int lines, vector<string>temp)
    {
        vector<vector<double>>matrix_matrix(columns, vector<double>( lines ) );
        for (int j=2 ; j<columns ; j++)
        {
            for (int i=0 ; i<lines ; i++)
            {
                matrix_matrix[j][i]=stod(temp[4]);
            }
        }
        for (int ii=0 ; ii <= columns ; ii++)
        {
            for (int jj=0 ;  jj<= lines ; jj++)
            {
                cout << "Kolumna: " << ii+1 << " wiersz: " << jj+1 << " wynosi: " << matrix_matrix[ii][jj] << "\n" << endl;
            }
        }
    }
    
    void change_value(int columns, int lines, double change_value)
    {
        matrix_matrix[columns][lines] = change_value;
    }
    
    void return_string();
    

    void add_number(int columns, int lines, double add_value)
    {
        for (int i = 0; i < columns; i++)
        {
            for (int j = 0; j < lines; j++)
            {
                matrix_matrix[i][j] += add_value;
            }
        }
    }
    
    void matrix_transsposed();
    void transfer(int columns, int lines)
    {
        vector<vector<double>>matrix_transsposed(lines, vector<double>( columns ) );
        a = tr;
        int t;
        t = row;
        row = column;
        column = t;
        
        for (int i = 0; i < lines; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                matrix_transsposed[i][j] = matrix_matrix[j][i];
            }
        }
        
        
    }
    
    void read_file();
    
    void save_file();
    
    void print_matrix();
    
};

void print_file(vector<string>temp)
{
    for (int ii=0 ; ii <= temp.size() ; ii++)
    {
        cout << temp[ii] << "\n";
    }
}

void print_matrix(int columns, int lines, &matrix)
{
    for (int ii=0 ; ii <= columns ; ii++)
    {
        for (int jj=0 ;  jj<= lines ; jj++)
        {
            cout << "Kolumna: " << ii+1 << " wiersz: " << jj+1 << "wynosi: " << matrix_matrix[ii][jj] << endl;
        }
    }
}

//////////////////////////////////////////////////////////////////////////
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\---//////////////////////////////////\\
///////////////////////////////////---\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//////////////////////////////////////////////////////////////////////////

int main()
{
    int matrix_columns;
    int matrix_lines;
    int exit = 0;
    int jj=1;
    char continuation;
    char answer;
    string GetTeamName;
    string nameTemp;
    string file_name;
    string templine;
    string tempstring;
    vector<string>lineslines;
    string tempstring_temp;
    string ww;
    fstream file;
    fstream team;
    int change_column;
    int change_line;
    double change_value;
    
    using namespace std;

    while(exit==0)
    {
        cout << "Super ! Wlasnie uruchomiles program do labolatorium nr 6 na kierunku informatyka\n";
        cout << "Program umozliwi Ci stworzenie macierzy.\n";
        cout << "Bedziesz mogl takze wykonac kilka dzialan na macierzach.\n";
        cout << "Powodzenia i fajnej zabawy przy tworzeniu macierzy.\n";
        cout << "\n\n\n";
        cout << "Podaj nazwe pliku w ktorym ma byc zapisana macierz\n";
        cin >> file_name;
        
        file.open(file_name+=".txt", ios::in);
        if(file.good()==false)
        {
            cout << "Przykro mi! Jednak program nie mogl odnalezc pliku o takiej nazwie.";
            cout << "Program teraz utworzy nowy plik o nazwie ''matrix.txt''";
            file.open("matrix.txt", ios::out | ios::app);
            cout << "Utworzona macierz bedzie miala rozmiar 4x3" << endl;
            matrix_columns=4;
            matrix_lines=3;
            matrix(matrix_columns, matrix_lines);
        }
        else
        {
            cout << "Brawo! Wlasnie otworzyles plik o nazwie ''Matrix''" << endl;
            while(getline(file, templine))
            {
                lineslines.push_back(templine);
                jj++;
            }
            matrix_columns=stoi(lineslines[0]);
            matrix_lines=stoi(lineslines[1]);
            //lineslines.erase (lineslines.begin(),lineslines.begin()+2);
            matrix(matrix_columns, matrix_lines, lineslines);
        }
        
        cout << "Czy chcesz wyswietlic zawartosc pliku??\n";
        cin >> answer;
        if (answer == 't')
        {
            {
                cout << "Teraz beda wyswietlone wszystkie linie\n";
                print_file(lineslines);
            }
        }
        
        cout << "Ilosc kolumn macierzy wynosi: " << matrix_columns << " ilosc wierszy macierzy wynosi: " << matrix_lines << endl;
        
        cout << "Podaj nr kolumny i wiersza w ktorej ma byc zmieniona wartosc:\n" << endl;
        cout << "Kolumna: " << endl;
        cin >> change_column;
        cout << "Wiersz: " << endl;
        cin >> change_line;
        cout << "Podaj nowa wartosc dla elementu macierzy: " << endl;
        cin >> change_value;
        change_value(change_column, change_line, change_value);
        
        
        

        
        cout << "Czy chcesz wyswietlic zawartosc macierzy??\n";
        cin >> answer;
        if (answer == 't')
        {
            {
                cout << "Teraz beda wyswietlone wszystkie linie\n";
                //print_matrix(matrix_columns, matrix_lines, matrix_matrix);
            }
        }
        
        
        
        
        for (int il=0 ; il <= matrix_columns ; il++)
        {
            for (int jk=0 ;  jk<= matrix_lines ; jk++)
            {
                //cout << "Kolumna: " << il+1 << " wiersz: " << jk+1 << "wynosi: " << &matrix_matrix[il][jk] << endl;
            }
        }

        

      
        
        cout << "Teraz bedziesz mogl zmodyfikowac wartosci dla elementow macierzy" << endl;
        cout << "Podaj ";

  
        file.close();
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






/*
 cout << "Czy chcesz wyswietlic zawartosc pliku??\n";
 cin >> answer;
 if (answer == 't')
 {
 {
 while(getline(file, templine))
 {
 lineslines.push_back(templine);
 jj++;
 }
 cout << "Teraz beda wyswietlone wszystkie linie\n";
 
 for (int ii=0 ; ii <= lineslines.size() ; ii++)
 {
 cout << lineslines[ii] << "\n";
 }
 }
 }
 */



/*

void matrix::create_matrix()
{
    vector<vector<matrix>>matrix_matrix( m_columns, vector<matrix>( m_lines ) );

    for (int j=0 ; j<m_columns ; j++)
    {
        for (int i=0 ; i<m_lines ; i++)
        {
            matrix_matrix[j][i].number=matrix_number;
        }
        for ( int ii=0 ; ii<matrix_lines ; ii++)
        {
            cout << "Liczba dla kolumny" << matrix_columns << "wiersza" << matrix_lines << "wynosi" << matrix_matrix[j][ii].number << endl;
        }
    }
}

int allocate_data(int colums, int lines)
{
    matrix_matrix.reserve(columns);
    matrix_matrix.resize(lines);
    return 0;
}


vector<string>data::void file_file()
{
    
}




void file_read2 ()
{
    ifstream inputFile ("");
    if (! inputFile . is_open ())
        throw std::exception ("");
    string lineAsString ;
    while (! inputFile .eof ())
    {
        inputFile >> lineAsString ;
        cout << lineAsString << endl ;
    }
}
*/
