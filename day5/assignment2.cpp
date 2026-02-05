#include <iostream>
#include <memory>
#include <string>
#include <cstdlib>

using namespace std;

class Sensor {
public:
    Sensor(const string& type) : sensor_name(type) {
        cout << sensor_name << " is now enabled\n";
    }

    ~Sensor() {
        cout << sensor_name << " is now disabled\n";
    }

    int readData() const {
        int value = rand() % 100;
        cout << sensor_name << " reads value: " << value << "\n";
        return value;
    }

private:
    string sensor_name;
};

void readSensorData(const shared_ptr<Sensor>& sensor) {
    sensor->readData();
}

void useSensorRvalue(shared_ptr<Sensor>&& sensor) {
    cout << "Rvalue shared_ptr received\n";
    sensor->readData();
}

void replaceSensorDoublePtr(shared_ptr<Sensor>* sensor_ptr) {
    if (sensor_ptr && *sensor_ptr) {
        (*sensor_ptr)->readData();
    }

    *sensor_ptr = make_shared<Sensor>("Pressure");
}

int main() {
    shared_ptr<Sensor> temp_sensor = make_shared<Sensor>("Temperature");
    readSensorData(temp_sensor);

    shared_ptr<Sensor> humidity_sensor = make_shared<Sensor>("Humidity");
    useSensorRvalue(move(humidity_sensor));

    shared_ptr<Sensor> light_sensor = make_shared<Sensor>("Light");
    replaceSensorDoublePtr(&light_sensor);

    return 0;
}

