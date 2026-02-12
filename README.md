# Wi-Fi Deauthentication Attack Detector
This project demonstrates a low-cost, effective system for identifying **Denial-of-Service (DoS)** attacks on Wi-Fi networks using the **ESP8266 NodeMCU** platform. It identifies forged deauthentication frames that exploit vulnerabilities in the IEEE 802.11 protocol, which lacks authentication for management frames.

## Overview
The system consists of two primary components: an **Attacker** node and a **Detector** node. While the attacker demonstrates the vulnerability by disrupting target Wi-Fi, the detector switches to **promiscuous mode** to sniff nearby 802.11 management frames and alert the user in real-time.

## Key Features
* **Real-time Monitoring:** Sniffs all nearby packets and specifically filters for deauth frames.
* **Visual & Serial Alerts:** Triggers a specific LED blinking pattern (2s ON, 5s OFF) and prints warnings to the Serial Monitor upon detection.
* **Lightweight Design:** Optimized for the ESP8266's limited memory (80 KB RAM).
* **IoT Integration:** Includes support for the Telegram Bot API for remote notifications.

## Hardware & Software
### Hardware
**Detector:** ESP8266 NodeMCU CP2102 
**Attacker:** ESP8266 NodeMCU V3 
**Connectivity:** Micro USB Cables & Wi-Fi enabled mobile hotspot 

### Software
**Arduino IDE:** For coding and monitoring 
**NodeMCU PyFlasher:** To flash custom attacker firmware 
**Libraries:** `UniversalTelegramBot` and ESP8266 Board Package 

## How It Works
1. **Initialization:** The detector connects to the assigned Wi-Fi and displays its local IP address.
2. **Promiscuous Mode:** The device enters a sniffing state to listen for all 802.11 management traffic.
3. **Analysis:** If a deauthentication packet is identified, the system sets `attackDetected` to true.
4. **Response:** The Serial Monitor logs `[⚠️] Deauth packet detected!` and the onboard LED (D4) begins to blink rhythmically.

## Experimental Results
The detector successfully identifies attacks launched from the attacker node. Below is an example of the detection log:
```text
22:31:46.018 -> [WiFi] Connected!
22:31:46.018 -> [WiFi] IP Address: 192.168.238.68
22:31:46.052 -> [Monitor] Promiscuous mode ON.
22:33:47.479 -> [⚠️] Deauth packet detected!
```
(Source: Project Serial Monitor Output )
