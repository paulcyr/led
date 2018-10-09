#pragma once
#include <SPI.h>
#include <FlashStorage.h>
#include <WiFi101.h>
#include "Log.h"

namespace PWiFi {

  #include "Secrets.h"

  Log log;

  typedef struct {
    int type;
    String ssid;
    String password;
  } WiFiConfig;
  
  FlashStorage(wifi_config, WiFiConfig);
  
  WiFiConfig wifiConfigCache;
  
  String getSSID() {
  
    if (wifiConfigCache.ssid.length() > 0) {
      return wifiConfigCache.ssid;
    }
  
    WiFiConfig wifiConfig = wifi_config.read();
    
    if (wifiConfig.ssid.length() > 0) {
      return wifiConfigCache.ssid;
    }
  
    return DEFAULT_WIFI_SSID;
  }
  
  bool setSSID(String newSSID) {
  
    String oldSSID = getSSID();
  
    if (newSSID == oldSSID) {
      return true;
    }
  
    WiFiConfig wifiConfig = wifi_config.read();
    wifiConfig.ssid = newSSID;
    wifiConfigCache.ssid = newSSID;
  
    return true;
  }
  
  String getPassword() {
  
    if (wifiConfigCache.password.length() > 0) {
      return wifiConfigCache.password;
    }
  
    WiFiConfig wifiConfig = wifi_config.read();
    
    if (wifiConfig.password.length() > 0) {
      return wifiConfigCache.password;
    }
  
    return DEFAULT_WIFI_PASS;
  }
  
  bool setPassword(String newPassword) {
  
    String oldPassword = getPassword();
  
    if (newPassword == oldPassword) {
      return true;
    }
  
    WiFiConfig wifiConfig = wifi_config.read();
    wifiConfig.password = newPassword;
    wifiConfigCache.password = newPassword;
  
    return true;
  }
  
  void printWiFiData() {
    // print your WiFi shield's IP address:
    IPAddress ip = WiFi.localIP();
    log.write("IP Address: ");
    log.writeln(ip);
    log.writeln(ip);
  
    // print your MAC address:
    byte mac[6];
    WiFi.macAddress(mac);
    log.write("MAC address: ");
    log.write(mac[5], HEX);
    log.write(":");
    log.write(mac[4], HEX);
    log.write(":");
    log.write(mac[3], HEX);
    log.write(":");
    log.write(mac[2], HEX);
    log.write(":");
    log.write(mac[1], HEX);
    log.write(":");
    log.writeln(mac[0], HEX);
  
  }
  
  void printCurrentNet() {
    // print the SSID of the network you're attached to:
    log.write("SSID: ");
    log.writeln(WiFi.SSID());
  
    // print the MAC address of the router you're attached to:
    byte bssid[6];
    WiFi.BSSID(bssid);
    log.write("BSSID: ");
    log.write(bssid[5], HEX);
    log.write(":");
    log.write(bssid[4], HEX);
    log.write(":");
    log.write(bssid[3], HEX);
    log.write(":");
    log.write(bssid[2], HEX);
    log.write(":");
    log.write(bssid[1], HEX);
    log.write(":");
    log.writeln(bssid[0], HEX);
  
    // print the received signal strength:
    long rssi = WiFi.RSSI();
    log.write("signal strength (RSSI):");
    log.writeln(rssi);
  
    // print the encryption type:
    byte encryption = WiFi.encryptionType();
    log.write("Encryption Type:");
    log.writeln(encryption, HEX);
    log.writeln();
  }
  
  
  
  
  int connect() {
    
    int status = WL_IDLE_STATUS;
    
    if (WiFi.status() == WL_NO_SHIELD) {
      log.writeln("WiFi shield not present");
      // don't continue:
      while (true);
    }
  
    String ssidString = getSSID();
    String passwordString = getPassword();
    char ssid[ssidString.length()];
    char password[passwordString.length()];
    
    ssidString.toCharArray(ssid, ssidString.length() + 1);
    passwordString.toCharArray(password, passwordString.length() + 1);
  
    // attempt to connect to WiFi network:
    while ( status != WL_CONNECTED) {
      log.write("Attempting to connect to WPA SSID: ");
      log.writeln(ssid);
      // Connect to WPA/WPA2 network:
      status = WiFi.begin(ssid, password);
  
      // wait 10 seconds for connection:
      delay(10000);
    }
  
    // you're connected now, so print out the data:
    log.writeln("You're connected to the network");
    return 0;
  }
}


