#include <iostream>
#include <vector>
using namespace std ;
vector<double>input_numbers(size_t count)
{
    vector<double> numbers(count);
    for (size_t i = 0; i < count; i++)
    {
        cin >> numbers[i];
    }
    return numbers;
}
void find_minmax(vector<double> numbers, double& min, double& max , size_t number_count)
{
    min = numbers[0];
    max = numbers[0];
    for ( int i = 0 ; i < number_count ; i ++ )
    {
        if ( numbers[i] > max )
        {
            max=numbers[i] ;
        }
        else
        {
            if ( numbers[i] < min )
            {
                min = numbers[i] ;
            }
        }
    }

}
void make_histogram(vector<double> numbers, size_t bin_count , size_t number_count  , double max , double min , size_t &max4ucel )
{
      vector<size_t> bins(bin_count,0);
    for ( int i = 0 ; i < number_count ; i ++ )
    {
        size_t bin_index=((numbers[i]-min)/(max-min))*bin_count ;
        if ( bin_index == bin_count )
        {
            bin_index -- ;
        }
        bins[bin_index]++;
    }
     max4ucel = bins[0] ;
    size_t korzinka = 0 ;
    for ( int i = 0 ; i < bin_count ; i ++)
    {
        if ( max4ucel < bins[i])
        {
            max4ucel = bins[i] ;
            korzinka = i ;
        }
    }
}
void show_histogram_text(vector<size_t> bins, size_t max4ucel , size_t bin_count )
{
     const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1 - 2*2;
cout << "+" ;
    if (max4ucel > SCREEN_WIDTH - 3 - 1 - 2*2 )
    {
        for (  int i =0 ; i < SCREEN_WIDTH-2 ; i ++ )
            cout << "-" ;
    }
    else
    {
        for ( int i = 0 ; i < max4ucel+5 ; i ++ )
        {
            cout << "-" ;
        }
    }
    cout << "+" ;
    if ( max4ucel <  MAX_ASTERISK)
    {
        cout << endl ;
    }

    for ( int i = 0 ; i < bin_count ; i ++ )
    {
        if ( bins[i] < 100 && bins[i] >=10 )
        {
            cout <<"|" << " " << bins[i] << '|' ;
        }
        if ( bins[i] < 10 )
        {
            cout <<"|" << " " <<" " << bins[i] << '|' ;
        }
        if ( bins[i] >= 100 )
        {
            cout <<"|"<< bins[i] << '|' ;
        }
        //for ( int j =0 ; j < bins[i] ; j ++ )
        {
            if ( max4ucel> MAX_ASTERISK)
            {
                size_t height = (SCREEN_WIDTH - 3 - 1 - 2*2) * (static_cast<double>(bins[i]) / max4ucel);
                for ( int i = 0 ; i < height ; i ++ )
                {
                    cout << "*" ;
                }
            }
            else
            {
                for ( int j =0 ; j < bins[i] ; j++ )
                {
                    cout <<"*" ;
                }
            }

        }

        if (max4ucel > MAX_ASTERISK)
        {
            size_t height = (SCREEN_WIDTH - 3 - 1 - 2*2) * (static_cast<double>(bins[i]) / max4ucel);
            for (int j = height ; j <MAX_ASTERISK+2; j++ )
            {
                cout <<" ";
            }
            cout << "|" ;
        }
        else
        {
            for (int j = bins[i] ; j < max4ucel+1 ; j++ )
            {
                cout << " ";
            }
            cout << "|" ;
            cout << endl ;
        }
    }

    cout<< "+" ;
    if (max4ucel > SCREEN_WIDTH - 3 - 1 )
    {
        for (  int i =0 ; i < 78 ; i ++ )
            cout<< "-" ;
    }
    else
    {
        for ( int i = 0 ; i < max4ucel+5 ; i++ )
        {
            cout<< "-" ;
        }
    }
    cout << "+" ;
}
int main ()
{
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1 - 2*2;
    size_t number_count ;
    cerr << "vvedite number count " ;
    cin >> number_count ;
    vector<double> numbers =input_numbers(number_count);
    const auto numbers = input_numbers(number_count);
    double min = numbers[0] ;
    double max = numbers[0] ;
    find_minmax( numbers,  min,  max , number_count) ;
    size_t bin_count ;
    cerr << "vvedite kol-vo korzinok " ;
    cin >> bin_count ;
    const auto bins = make_histogram(numbers, bin_count ,number_count , max , min);
    size_t max4ucel ;
    show_histogram_text(bins ,max4ucel , bin_count);
    return 0 ;
}
