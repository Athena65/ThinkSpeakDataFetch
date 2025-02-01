# **ThinkSpeakDataFetch**

This project involves reading data from the internet and displaying it on an LCD monitor. It utilizes an ESP8266 microcontroller to fetch data from the internet and present it in a user-friendly format.

---

## **Features**

- **Wi-Fi Connectivity**: Connects to a specified Wi-Fi network to access internet data.
- **Data Retrieval**: Fetches data from online sources, such as ThingSpeak channels.
- **LCD Display**: Displays the retrieved data on an LCD screen for real-time monitoring.

---

## **Hardware Requirements**

- ESP8266 Microcontroller
- 16x2 LCD Display
- I2C Module for LCD (optional but recommended)
- Connecting Wires
- Breadboard (optional)

---

## **Software Requirements**

- Arduino IDE
- ESP8266 Board Package installed in Arduino IDE
- LiquidCrystal_I2C Library (if using I2C module)

---

## **Setup Instructions**

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/Athena65/ThinkSpeakDataFetch.git
   cd ThinkSpeakDataFetch
   ```

2. **Open the `.ino` File**:
   Launch the Arduino IDE and open the `ThinkSpeakDataFetch.ino` file located in the repository.

3. **Configure Wi-Fi Credentials**:
   In the `.ino` file, locate the following lines:
   ```cpp
   const char* ssid = "your_SSID";
   const char* password = "your_PASSWORD";
   ```
   Replace `"your_SSID"` and `"your_PASSWORD"` with your Wi-Fi network's SSID and password.

4. **Configure ThingSpeak Settings** (if applicable):
   If you're fetching data from a ThingSpeak channel, ensure you have the correct API key and channel ID set in the code:
   ```cpp
   const char* apiKey = "your_API_key";
   const char* channelID = "your_channel_ID";
   ```
   Replace `"your_API_key"` and `"your_channel_ID"` with your ThingSpeak API key and channel ID.

5. **Select the Board and Port**:
   - In the Arduino IDE, navigate to `Tools` > `Board` and select `NodeMCU 1.0 (ESP-12E Module)` or the appropriate ESP8266 board.
   - Navigate to `Tools` > `Port` and select the COM port to which your ESP8266 is connected.

6. **Upload the Sketch**:
   Click the upload button in the Arduino IDE to compile and upload the code to the ESP8266.

---

## **Circuit Diagram**

Connect the hardware components as follows:

- **ESP8266 to LCD via I2C**:
  - `SDA` to `D2`
  - `SCL` to `D1`
  - `VCC` to `3.3V`
  - `GND` to `GND`

*Note: If not using an I2C module, connect the LCD pins to the ESP8266 GPIO pins accordingly and adjust the code to use the standard LiquidCrystal library.*

---

## **Usage**

1. **Power the ESP8266**:
   Connect the ESP8266 to a power source (e.g., USB cable connected to your computer or a USB power adapter).

2. **Data Display**:
   Once powered, the ESP8266 will connect to the specified Wi-Fi network, fetch data from the configured internet source, and display the information on the LCD screen.

---

## **Troubleshooting**

- **Serial Monitor**:
  Use the Serial Monitor in the Arduino IDE (set to the correct baud rate, e.g., 115200) to view debug messages and ensure the ESP8266 is connecting to Wi-Fi and retrieving data correctly.

- **LCD Not Displaying Data**:
  - Verify the connections between the ESP8266 and the LCD.
  - Ensure the correct I2C address is set in the code (common addresses are `0x27` or `0x3F`).
  - Adjust the contrast potentiometer on the LCD module if available.

---

## **Contributing**

Contributions are welcome! If you have suggestions for improvements or new features, feel free to open an issue or submit a pull request.
