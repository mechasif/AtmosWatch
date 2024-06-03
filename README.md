# DHT11 and MQ135 Sensor with LCD Display

This project integrates a DHT11 temperature and humidity sensor, an MQ135 air quality sensor, and a LiquidCrystal_I2C LCD to display the sensor readings. The project utilizes an ELEGOO UNO R3 equipped with an ATMega16U2 Processor, an 8-bit AVR® RISC-based microcontroller to read sensors' data and display the LCD readings.

## Table of Contents
- [Introduction](#introduction)
- [Components](#components)
- [Circuit Diagram](#circuit-diagram)
- [Installation](#installation)
- [Usage](#usage)
- [Author](#author)
- [License](#license)

## Introduction
This project reads temperature, humidity, and air quality levels using the DHT11 and MQ135 sensors, and displays the data on a LiquidCrystal_I2C LCD. It is a simple yet effective way to monitor environmental conditions in real time.

## Components
- ELEGOO UNO R3 (or, Arduino UNO R3)
- DHT11 Temperature and Humidity Sensor
- MQ135 Air Quality Sensor
- LiquidCrystal_I2C LCD (20x4)
- Jumper wires
- Breadboard

## Circuit Diagram
![Circuit_Diagram](https://github.com/mechasif/DHT11-MQ135-LCD-Monitor/blob/main/Images/Circuit_Diagram.png)


## Installation
1. **Clone the repository:**
   ```sh
   git clone https://github.com/yourusername/DHT11-MQ135-LCD-Monitor.git
   ```
2. **Install the necessary libraries:**
   - [LiquidCrystal_I2C](https://github.com/johnrickman/LiquidCrystal_I2C)
   - [DHT sensor library](https://github.com/adafruit/DHT-sensor-library)

3. **Open the project in your Arduino IDE and upload the code to your board.**

## Usage
1. **Connect the components as per the circuit diagram for the LCD.**
2. **Power on the Microcontroller.**
3. **Observe the temperature, humidity, and air quality readings on the LCD.**

### Code Explanation
- **Setup Function:**
  - Initializes the LCD and sensors.
  - Sets up the VCC pin for the MQ135 sensor.
  - Displays an activation message on the LCD.

- **Loop Function:**
  - Reads data from the DHT11 sensor (temperature and humidity).
  - Reads data from the MQ135 sensor (air quality).
  - Displays the readings on the LCD.
  - Prints the readings to the serial monitor for debugging.

## Author
**Asif Ahmed**

- **Email:** inbox.asifahmed@gmail.com
- **LinkedIn:** [Asif Ahmed](https://www.linkedin.com/in/mechasif/)

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

Feel free to contribute, report issues, or fork this repository to improve the project. Your contributions are highly appreciated!
