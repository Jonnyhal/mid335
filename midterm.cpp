//Jonathan Halbrook
//midterm cs335
//unit testing for notes and octave
//Extra Credit: with tolerance = 0.005 how many bad values?

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include "text.cpp"

using namespace std;

//frequency definitions
#define A4 440.0
#define F0 A4
#define F0_note A
#define F0_octave 4

typedef enum {
    C = 1,
    Cs,
    D,
    Ds,
    E,
    F,
    Fs,
    G,
    Gs,
    A,
    As,
    B,
    END = B,
    HALF_STEPS_PER_OCTAVE = B,
} note_t;

double freq(note_t note, int octave_delta);

int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12};
int bad=0;

int main(int argc, char *argv[])
{
    //note_t note;
    int octave_delta;
    float tolerance = 0.004;

    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <NOTE>  <OCTAVE_DELTA>" << endl;
        return 0;
    }
    //
    /*note = (note_t)(toupper(argv[1][0]) - 64);
    switch(toupper(argv[1][0])) {
        case 'A': note = A; break;
        case 'B': note = B; break;
        case 'C': note = C; break;
        case 'D': note = D; break;
        case 'E': note = E; break;
        case 'F': note = F; break;
    }*/
    //You may call your unit test here...
    cout << "tolerance: " << tolerance << endl;
    cout << "freq function unit-test\n\n";
    cout << "note\t" << "octave\t" << "value\t" << "diff\n";
    cout << "----\t" << "-----\t" << "-------\t" << "-----------\n";
    for(octave_delta=0; octave_delta<9; octave_delta++){    
        for (int j=0; j<B; j++) {
            note_t eCurrent = (note_t)(j+1);
            float ret = freq(eCurrent, octave_delta);
            float diff = ret - result[j+(octave_delta*12)];
            diff = fabs(diff);
            if (diff > tolerance) {
                cout << arr[j] << "\t" << octave_delta << "\t" << ret << "\t" << diff << "\t<-----bad\n";
                bad++;
            } else {
                cout << arr[j] << "\t" << octave_delta << "\t" << ret << "\t" << diff << "\tgood\n";
            } 

        }
    }
    octave_delta = atoi(argv[2]);
    //cout << freq(note, octave_delta) << endl;
    cout << "bad element count: " << bad << endl;
    return 0;
}

//-----------------------------------------------------------
//Generate a frequency in hz that is half_steps away from C_4
//Do not modify this function.
//-----------------------------------------------------------
double freq(note_t note, int octave_delta)
{
    double freq;
    double factor;
    double a;
    int n;
    int octave = octave_delta - F0_octave;

    a = pow(2.0, 1.0/(double)HALF_STEPS_PER_OCTAVE);
    n = note - F0_note;
    freq = F0 * pow(a, (double)n);
    factor = pow(2.0, (double)octave);
    freq = freq * factor;
    return freq;
}


