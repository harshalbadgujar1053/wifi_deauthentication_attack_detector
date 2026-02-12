# 🛡️ Wi-Fi Deauthentication Attack Detection System

### Embedded Wireless Intrusion Detection using ESP8266

![Hardware](https://img.shields.io/badge/Hardware-ESP8266-blue)
![Domain](https://img.shields.io/badge/Domain-Wireless_Security-red)
![Type](https://img.shields.io/badge/Type-Intrusion_Detection-green)
![Platform](https://img.shields.io/badge/Platform-Arduino-orange)

---

## 📌 Project Overview

This project implements a lightweight **Wireless Intrusion Detection System (WIDS)** using the ESP8266 NodeMCU to detect Wi-Fi Deauthentication (Deauth) attacks in real time.

Deauthentication attacks exploit vulnerabilities in IEEE 802.11 management frames by sending forged deauth packets to disconnect clients from an access point. Since these frames are not authenticated, they can be spoofed to create denial-of-service conditions.

The ESP8266 operates in promiscuous mode to capture raw 802.11 frames and analyze them at the MAC layer. When a Deauthentication frame (subtype `0xC0`) is identified, the system triggers immediate visual and serial alerts.

---

## 🎯 Objective

To build a simple, cost-effective embedded detection mechanism capable of:

* Capturing raw Wi-Fi management frames
* Identifying Deauthentication packets in real time
* Providing immediate alert through Serial Monitor
* Indicating attack presence via built-in LED

---

## ⚙️ Detection Mechanism

After connecting to Wi-Fi in Station (STA) mode, the ESP8266 enables promiscuous mode to monitor all nearby packets. A callback function inspects the frame control field of captured packets and checks for Deauthentication subtype (`0xC0`).

Upon detection:

* A warning message is printed on Serial Monitor
* The built-in LED blinks in a fixed pattern

### 🚨 LED Alert Pattern

| LED State | Duration  |
| --------- | --------- |
| ON        | 2 seconds |
| OFF       | 5 seconds |

⚠️ The NodeMCU built-in LED is **Active LOW**

* LOW → ON
* HIGH → OFF

---

## 📡 Sample Output

```
[WiFi] Connected!
[WiFi] IP Address: 192.168.238.68
[Monitor] Promiscuous mode ON.
[⚠️] Deauth packet detected!
```

Repeated alerts indicate continuous deauthentication attempts.

---

## 🛠 Hardware Used

| Component                 | Quantity |
| ------------------------- | -------- |
| ESP8266 NodeMCU (ESP-12E) | 1        |
| USB Data Cable            | 1        |
| Laptop / PC               | 1        |

No external components are required.

---

## 💻 Software Requirements

* Arduino IDE
* ESP8266 Board Package

---

## 🔐 Security Significance

This project demonstrates practical understanding of:

* IEEE 802.11 frame structure
* Wireless network vulnerabilities
* MAC-layer packet inspection
* Embedded intrusion detection concepts
* IoT security fundamentals

It highlights the transition from understanding wireless attacks to building defensive detection mechanisms.

---

## 🔮 Future Improvements

* Cloud-based logging
* Telegram/MQTT alerts
* Detection of additional management frame abuse
* Web-based monitoring dashboard

---

## ⚠️ Ethical Use Disclaimer

This project is strictly for educational and defensive cybersecurity purposes.
Use only in controlled environments or networks you own.
Unauthorized interference with networks is illegal.
