#include <iostream>
#include <memory>
#include <string>

class Sensor {
public:
    Sensor(const std::string& type) : sensor_name(type) {
        std::cout << sensor_name << " is now enabled\n";
    }

    ~Sensor() {
        std::cout << sensor_name << " is now disabled\n";
    }

    int readData() const {
        int value = rand() % 100;
        std::cout << sensor_name << " reads value: " << value << "\n";
        return value;
    }

private:
    std::string sensor_name;
};

void readSensorData(const std::unique_ptr<Sensor>& sensor) {
    std::cout << "Just checking the sensor data\n";
    sensor->readData();
}

void transferSensor(std::unique_ptr<Sensor>&& sensor) {
    std::cout << "Rvalue of sensor data has been taken for modifications\n";
    sensor->readData();
    std::cout << "Rvalue sensor will be destroyed\n";
}

void replaceSensor(std::unique_ptr<Sensor>* sensor_ptr) {
    if (sensor_ptr && *sensor_ptr) {
        std::cout << "Old sensor is still available. Reading before replacement.\n";
        (*sensor_ptr)->readData();
    }
    *sensor_ptr = std::make_unique<Sensor>("Pressure");
    std::cout << "Temperature sensor has been replaced with pressure sensor.\n";
}

int main() {
    std::unique_ptr<Sensor> temp_sensor = std::make_unique<Sensor>("Temperature");
    readSensorData(temp_sensor);

    std::unique_ptr<Sensor> humidity_sensor = std::make_unique<Sensor>("Humidity");
    transferSensor(std::move(humidity_sensor));

    std::unique_ptr<Sensor> light_sensor = std::make_unique<Sensor>("Light");
    replaceSensor(&light_sensor);

    return 0;
}

