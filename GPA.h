#include<iostream>
#include<iomanip>
using namespace std;

class Average
{
private:
    int sizeSub, sizeLab;
    int* subjects;
    int* labs;
    int sumSubjects, sumLabs;
    double avr;

public:
    Average() : sizeSub(0), sizeLab(0), subjects(nullptr), labs(nullptr), sumSubjects(0), sumLabs(0), avr(0.0) {}

    ~Average()
    {
        delete[] subjects;
        delete[] labs;
    }

    void setMarks()
    {
        cout << "Enter the number of university subjects: ";
        cin >> sizeSub;

        subjects = new int[sizeSub];
        for (int i = 0; i < sizeSub; i++)
        {
            cout << "Enter your mark in subject " << i + 1 << " : ";
            cin >> subjects[i];

            // Validate the input marks
            subjects[i] = max(35, min(subjects[i], 100));

            sumSubjects += subjects[i];
        }

        char ch;
        cout << "\nDo you intend to enroll in a laboratory (y/n): ";
        cin >> ch;

        if (ch == 'y' || ch == 'Y')
        {
            cout << "Enter the number of university laboratory: ";
            cin >> sizeLab;

            labs = new int[sizeLab];
            for (int i = 0; i < sizeLab; i++)
            {
                cout << "Enter your mark in laboratory " << i + 1 << " : ";
                cin >> labs[i];

                // Validate the input marks
                labs[i] = max(35, min(labs[i], 100));

                sumLabs += labs[i];
            }
        }
        else
        {
            cout << "OK." << endl;
        }
    }

    void CalculateSystem()
    {
        avr = ((sumSubjects * static_cast<double>(3)) + sumLabs) / ((sizeSub * 3) + sizeLab);

        cout << "\n\t\t--------------------------------------" << endl;
        cout << fixed << showpoint << setprecision(2) << "\t\tYour semester average of 100 = " << avr << " %" << endl;
        cout << "\t\t--------------------------------------" << endl;

        cout << "\n\nDo you want to calculate your cumulative average (y/n): ";
        char ch; // choice
        cin >> ch;

        if (ch == 'y' || ch == 'Y') // to calculate cumulative average
        {
            double Pavr; // previous average
            int Phour; // previous hour

            cout << "Enter your previous average : ";
            cin >> Pavr;

            cout << "Enter the number of hours that were passed at your previous average : ";
            cin >> Phour;

            avr = ((Pavr * Phour) + (avr * ((sizeSub * 3) + sizeLab))) / (Phour + ((sizeSub * 3) + sizeLab));

            cout << "\n\n\t\t----------------------------------------" << endl;
            cout << "\t\tYour Cumulative average of 100 = " << avr << " %" << endl;
            cout << "\t\t----------------------------------------\n\n" << endl;
        }
    }
};


