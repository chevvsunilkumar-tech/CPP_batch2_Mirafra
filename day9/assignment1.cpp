#include <iostream>
using namespace std;

int main()
{
    const int sensors = 4;   
    const int data = 4;   

    
    float **sensor_data = new float*[sensors];

    // Allocate memory for each sensor
    for (int i = 0; i < sensors; i++)
    {
        sensor_data[i] = new float[data];
    }

  
    // entering  data
    for (int i = 0; i < data; i++)
    {
        sensor_data[0][i] = 25.0 ;     // Temperature
        sensor_data[1][i] = 50.0 ;     // Humidity
        sensor_data[2][i] = 30.0 ;     // Heat Index
        sensor_data[3][i] = 1000.0 ;   // Pressure
    }

    //print averages
    float avg;

    cout << "Average Sensor Values: \n";

    for (int s = 0; s < sensors; s++)
    {
        avg = 0;
        for (int i = 0; i < data; i++)
        {
            avg += sensor_data[s][i];
        }
        avg /= data;

        if (s == 0) cout << "Temperature: ";
        if (s == 1) cout << "Humidity   : ";
        if (s == 2) cout << "Heat Index : ";
        if (s == 3) cout << "Pressure   : ";

        cout << avg << endl;
    }

    // Free memory
    for (int i = 0; i < sensors; i++)
    {
        delete[] sensor_data[i];
    }
    delete[] sensor_data;

    return 0;
}

